from libraries.fluid_properties_db_retrieve import get_fluid_properties_fromT

def get_fluid_properties(Tactual):
    """
    Retrieves enthalpy and pressure ratio values at a specified temperature (Tactual)
    using the get_fluid_properties_fromT function.

    Returns:
        A tuple (h_actual, pr_actual) containing enthalpy and pressure ratio
        at Tactual

    Notes:
        - If Tactual is not found in the database, a message is printed and 
          the function returns None.
        - Assumes the input function returns a dictionary with keys 
          'h (kJ/kg)' and 'pr' or a warning string.
    """
    # Fluid properties at Tactual
    properties = get_fluid_properties_fromT(Tactual)  # This returns a dictionary
    if isinstance(properties, dict):
        h_actual = properties["h (kJ/kg)"]
        pr_actual = properties["pr"]
    else:
        print("Temperature not found in database.")

    return h_actual, pr_actual