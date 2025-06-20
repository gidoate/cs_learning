import sqlite3

# Define the database filename
DB_FILENAME = "db/ideal_gas_properties.db"
SQL_SCRIPT = "db/ideal_gas_properties.sql"

def setup_database():
    try:
        # Connect to SQLite database (creates it if it doesn't exist)
        conn = sqlite3.connect(DB_FILENAME)
        cursor = conn.cursor()

        # Read and execute the SQL script
        with open(SQL_SCRIPT, "r", encoding="utf-8") as sql_file:
            sql_script = sql_file.read()
            cursor.executescript(sql_script)

        # Commit changes, check tables and close connection
        conn.commit()
        
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
        print("Tables in database:", cursor.fetchall())
        
        conn.close()

        print(f"Database '{DB_FILENAME}' migrated successfully!")

    except sqlite3.Error as e:
        print(f"SQLite error: {e}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    setup_database()
