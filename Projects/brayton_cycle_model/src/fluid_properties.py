import sqlite3
import numpy as np

def get_cp_cv(Tactual):
    # Connect to the database
    conn = sqlite3.connect("db/ideal_gas_properties.db")
    cursor = conn.cursor()

    # Query to get all temperature, Cp, and Cv values
    query = "SELECT Temp_K, Cp_kJ_per_kg_K, Cv_kJ_per_kg_K FROM IdealGasProperties_Air ORDER BY Temp_K"
    cursor.execute(query)
    data = cursor.fetchall()

    conn.close()

    if not data:
        return "No data available in the database."

    # Convert data to numpy arrays for interpolation
    temps = np.array([row[0] for row in data])
    cps = np.array([row[1] for row in data])
    cvs = np.array([row[2] for row in data])

    if Tactual in temps:
        # Exact match found
        index = np.where(temps == Tactual)[0][0]
        return {"Cp (kJ/kg*K)": float(cps[index]), "Cv (kJ/kg*K)": float(cvs[index])}
    elif Tactual < temps[0] or Tactual > temps[-1]:
        return "Temperature is outside the database range, interpolation not possible."
    else:
        # Perform linear interpolation
        Cp_interp = np.interp(Tactual, temps, cps)
        Cv_interp = np.interp(Tactual, temps, cvs)
        return {"Cp (kJ/kg*K)": float(Cp_interp), "Cv (kJ/kg*K)": float(Cv_interp)}
