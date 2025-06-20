from src.libraries.fluid_properties_db_retrieve import get_fluid_properties_fromT

def get_fluid_properties(T1, T3):
    """
    Retrieves enthalpy and pressure ratio values at two specified temperatures (T1 and T3)
    using the get_fluid_properties_fromT function.

    Returns:
        A tuple (h_1_s, pr_1_s, h_3_s, pr_3_s) containing enthalpy and pressure ratio
        at T1 and T3, respectively.

    Notes:
        - If either T1 or T3 is not found in the database, a message is printed and 
          the function returns None.
        - Assumes the input function returns a dictionary with keys 
          'h (kJ/kg)' and 'pr' or a warning string.
    """
    # Fluid properties at T1
    properties = get_fluid_properties_fromT(T1)  # This returns a dictionary
    if isinstance(properties, dict):
        h_1_s = properties["h (kJ/kg)"]
        pr_1_s = properties["pr"]
    else:
        print("Temperature not found in database.")

    properties = get_fluid_properties_fromT((T3))  # Cp and Cv at average temperature across the process

    # Fluid properties at T3
    if isinstance(properties, dict):
        h_3_s = properties["h (kJ/kg)"]
        pr_3_s = properties["pr"]
    else:
        print("Temperature not found in database.")
        return
    
    return h_1_s, pr_1_s, h_3_s, pr_3_s