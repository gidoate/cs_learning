import sqlite3
import numpy as np

def get_fluid_properties_fromT(Tactual):
    """
    Retrieves enthalpy (h) and pressure ratio (pr) for a given temperature (Tactual)
    from an SQLite database of ideal gas properties for air.
    
    If an exact match is found, returns the corresponding values.
    If not, interpolates between nearest temperature values.
    Returns a warning if the temperature is out of range.
    """
    # Connect to the database
    conn = sqlite3.connect("db/ideal_gas_properties.db")
    cursor = conn.cursor()

    # Query to get all temperature, Cp, and Cv values
    query = "SELECT Temp_K, h_kJ_per_kg, pr FROM IdealGasProperties_Air_pr ORDER BY Temp_K"
    cursor.execute(query)
    data = cursor.fetchall()

    conn.close()

    if not data:
        return "No data available in the database."

    # Convert data to numpy arrays for interpolation
    temps = np.array([row[0] for row in data])
    hs = np.array([row[1] for row in data])
    prs = np.array([row[2] for row in data])

    if Tactual in temps:
        # Exact match found
        index = np.where(temps == Tactual)[0][0]
        return {"h (kJ/kg)": float(hs[index]), "pr": float(prs[index])}
    elif Tactual < temps[0] or Tactual > temps[-1]:
        return "Temperature is outside the database range, interpolation not possible."
    else:
        # Perform linear interpolation
        h_interp = np.interp(Tactual, temps, hs)
        pr_interp = np.interp(Tactual, temps, prs)
        properties = {"h (kJ/kg)": float(h_interp), "pr": float(pr_interp)}
    
    if isinstance(properties, dict):
        h_actual = properties["h (kJ/kg)"]
        pr_actual = properties["pr"]
    else:
        print("Temperature not found in database.")

    return h_actual, pr_actual

def get_fluid_properties_fromPr(pr):
    """
    Retrieves enthalpy (h) and temperature (T) for a given pressure ratio (pr)
    from an SQLite database of ideal gas properties for air.
    
    If an exact match is found, returns the corresponding values.
    If not, interpolates between nearest pr values.
    Returns a warning if pr is out of range.
    """
    # Connect to the database
    conn = sqlite3.connect("db/ideal_gas_properties.db")
    cursor = conn.cursor()

    # Query to get all temperature, Cp, and Cv values
    query = "SELECT Temp_K, h_kJ_per_kg, pr FROM IdealGasProperties_Air_pr ORDER BY pr"
    cursor.execute(query)
    data = cursor.fetchall()

    conn.close()

    if not data:
        return "No data available in the database."

    # Convert data to numpy arrays for interpolation
    temps = np.array([row[0] for row in data])
    hs = np.array([row[1] for row in data])
    prs = np.array([row[2] for row in data])

    if pr in prs:
        # Exact match found
        index = np.where(temps == pr)[0][0]
        return {"h (kJ/kg)": float(hs[index]), "T (K)": float(prs[index])}
    elif pr < prs[0] or pr > prs[-1]:
        return "pr is outside the database range, interpolation not possible."
    else:
        # Perform linear interpolation
        h_interp = np.interp(pr, prs, hs)
        t_interp = np.interp(pr, prs, temps)
        properties = {"h (kJ/kg)": float(h_interp), "T (K)": float(t_interp)}

    if isinstance(properties, dict):
        h_actual = properties["h (kJ/kg)"]    
        t_actual = properties["T (K)"]
    else:
        print("pr not found in database.")
    
    return h_actual, t_actual
    
def get_fluid_properties_fromh(h):
    """
    Retrieves temperature (T) and pressure ratio (pr) for a given enthalpy (h)
    from an SQLite database of ideal gas properties for air.
    
    If an exact match is found, returns the corresponding values.
    If not, interpolates between nearest temperature values.
    Returns a warning if the temperature is out of range.
    """
    # Connect to the database
    conn = sqlite3.connect("db/ideal_gas_properties.db")
    cursor = conn.cursor()

    # Query to get all temperature, Cp, and Cv values
    query = "SELECT Temp_K, h_kJ_per_kg, pr FROM IdealGasProperties_Air_pr ORDER BY Temp_K"
    cursor.execute(query)
    data = cursor.fetchall()

    conn.close()

    if not data:
        return "No data available in the database."

    # Convert data to numpy arrays for interpolation
    temps = np.array([row[0] for row in data])
    hs = np.array([row[1] for row in data])
    prs = np.array([row[2] for row in data])

    if h in hs:
        # Exact match found
        index = np.where(h == hs)[0][0]
        return {"T (K)": float(temps[index]), "pr": float(prs[index])}
    elif h < hs[0] or h > hs[-1]:
        return "Temperature is outside the database range, interpolation not possible."
    else:
        # Perform linear interpolation
        temp_interp = np.interp(h, hs, temps)
        pr_interp = np.interp(h, hs, prs)
        properties = {"T (K)": float(temp_interp), "pr": float(pr_interp)}

    if isinstance(properties, dict):
        t_actual = properties["T (K)"]    
        pr_actual = properties["pr"]
    else:
        print("pr not found in database.")
    
    return t_actual, pr_actual