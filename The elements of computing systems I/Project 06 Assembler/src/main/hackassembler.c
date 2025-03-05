#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(int argc, char *argv[])
{
    // Check if the filename is provided as an argument
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // Else, continue to parser
    parser(argc, argv);

    return 0;
}