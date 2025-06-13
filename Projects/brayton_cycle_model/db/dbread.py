import sqlite3

conn = sqlite3.connect("db/ideal_gas_properties.db")
cursor = conn.cursor()

# List all tables
cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
tables = cursor.fetchall()
print("Tables:", tables)

# Query a table
cursor.execute("SELECT * FROM IdealGasProperties_Air;")
rows = cursor.fetchall()
for row in rows:
    print(row)

conn.close()
