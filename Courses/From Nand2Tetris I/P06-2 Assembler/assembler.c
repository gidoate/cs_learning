#include <limits.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "symbol_table.h"
#include "parser.h"
// Prototype for my_strndup function
char *my_strndup(const char *s, size_t n);

/*
* Extract the filename without the extension
*
* @param char *file: the file name with the extension
* @return: 
*    * the file name without the extension (allocates memory)
*     * NULL iff file is not a valid assembly file        
*/

char *extractFileName(const char *file) {
    char *file_token;
    char *ext_token;
    char *filename;
    char *bname;
    char file_cpy[NAME_MAX];
    char *path;

    if (!file) {
        return NULL;
    }

    if (strlen(file) > NAME_MAX) {
        fprintf(stderr, "File name exceeds %d characters\n", NAME_MAX);
        return NULL;
    }

    if ( ! (path = my_strndup(file, strlen(file))) ) {
        return NULL;
    }

    if ( ! (bname = basename(path)) ) {
        free(path);
        return NULL;
    }
    
    strncpy(file_cpy, bname, strlen(bname));
    file_cpy[strlen(file)] = '\0';

    free(path);
    
    file_token = strtok(file_cpy, ".");
    ext_token  = strtok(NULL, ".");

    if (file_token && ext_token && strncmp(ext_token, "asm", 3) == 0) {
        if (!(filename = (char *)malloc(sizeof(char) * strlen(file_token) + 1))) {
            
            return NULL;
        }
        if (!strncpy(filename, file_token, strlen(file_token))) {
            perror("strcpy");
            free(filename);
            
            return NULL;
        }
        filename[strlen(file_token)] = '\0';
        
        return filename;
    }
    fprintf(stderr, "File must have .asm extension\n");
    return NULL;
}

/*
* The assembler's first pass through the assembly code to look ahead of all the
* labels that exist in the program and insert them to the symbol table
*
* @param table: the symbol table
* @param fp   : thre file pointer to read the source code
*/
void first_pass(struct symbol_entry *table, FILE *fp) {
    int i = 0;
    int line_num = 0, is_label = 0;
    fseek(fp, 0, SEEK_SET);
    char line[INSTR_SIZE];
    char symbol[SYMBOL_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == '/' || line[i] == '\r' || line[i] == '\n') {
                break;
            }
            else if (isalnum(line[i]) || line[i] == '@') {
                line_num++;
                break;
            }
            else if (line[i] == '(') {
                //printf("line: %s\n", line);
                parse_address_asm(line, symbol, &is_label);
                //printf("label: %s\n", symbol);
                get_addr_bin(table, symbol, line_num);
                break;
            }
        }
    }
    fseek(fp, 0, SEEK_SET);
}

/*
* Write the output of the assembler to the provided file
*
* @param  filename   : the name of the file without the hack extension to write
*                      the output of the assembler to
* @param instructions: the list of instructions stored in a data structure that
*                      contains all the information needed to convert to 
*                      machine code
* @return            : 1 iff there is nothing wrong with the function.
*                      0 otherwise
*/
int write_binary_instructions(char *filename, 
	                          struct instruct_bin_entry *instructions) 
{
    struct instruct_bin_entry *instruction = instructions;
    FILE *fp;
    int name_size = strlen(filename) + 5 + 1;
    char *fileout_name;

    if ( ! (fileout_name = malloc(sizeof(char) * name_size)) ) {
        perror("malloc");
        return 0;
    }

    strncpy(fileout_name, filename, strlen(filename));
    fileout_name[strlen(filename)] = '\0';
    strncat(fileout_name, ".hack", 6);
    fileout_name[strlen(filename) + 5] = '\0';
    

    if (! (fp = fopen(fileout_name, "w")) ) {
        free(fileout_name);
    }
    while (instruction) {
        fprintf(fp, "%s\n", instruction->instr);
        instruction = instruction->next;
    }
    free(fileout_name);
    fclose(fp);
    return 1;
}


int main (int argc, char **argv) {
    FILE *fp = NULL;
    char *filename;
    int status = 0;
    char line[INSTR_SIZE];
    struct symbol_entry *table = NULL;
    struct instruct_bin_entry *instructions = NULL;

    if (argc < 2) {
        fprintf(stderr, "usage: %s file.asm\n", argv[0]);
        status = 1;
        return 1;
    }

    if (!(filename = extractFileName(argv[1]))) {
        fprintf(stderr, "%s is an invalid filename\n", argv[1]);
        status = 1;
        goto cleanup;
    }
    
    if (!(fp = fopen(argv[1], "r"))) {
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        perror("fopen");
        status = 1;
        goto cleanup;
    }

    if (! (table = init_sym_table()) ) {
        status = 1;
        goto cleanup;
    }

    first_pass(table, fp);

    if ( ! (instructions = parse_instructions(table, fp)) ) {
        status = 1;
        goto cleanup;
    }
    
    fclose(fp);
    fp = NULL;
    status = write_binary_instructions(filename, instructions);

cleanup:
    if (fp) {
        fclose(fp);
    }

    if (filename) {
        free(filename);
    }

    if (table) {
        destroy_table(table);
    }

    if (instructions) {
        destroy_instructions(instructions);
    }
    return status;
}
