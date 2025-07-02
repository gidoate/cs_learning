from libraries.fluid_properties_db_retrieve import get_fluid_properties_fromT, get_fluid_properties_fromh

def diffuser(P1, T1, V1):
    """
    Simulates a diffuser in a jet engine by calculating the new enthalpy, temperature, and pressure
    after kinetic energy is reduced and converted into internal energy.

    Parameters:
    P1 (float): Inlet pressure (Pa)
    T1 (float): Inlet temperature (K)
    V1 (float): Inlet velocity (km/h)

    Returns:
    h2 (float): Outlet specific enthalpy (kJ/kg)
    T2 (float): Outlet temperature (K)
    P2 (float): Outlet pressure (Pa)
    """
    V1 = V1 * (1000 / 3600)  # Convert km/h to m/s
    h1, pr1 = get_fluid_properties_fromT(T1)
    h2 = h1 + (V1**2) / (2 * 1000) # comes from the equation accross a diffuser -> (h_2 - h_1) = (V_1^2 - V_2^2)/2
    T2, pr2 = get_fluid_properties_fromh(h2)
    P2 = (pr2 / pr1) * P1

    return h2, T2, P2