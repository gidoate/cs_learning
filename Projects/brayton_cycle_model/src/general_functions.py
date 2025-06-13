"""Contains general thermodynamic formulas"""

def volumetric_to_mass_flow_rate(volumetric_flow_rate, P1, T1):
    """
    Calculate mass flow rate (m_dot).

    Parameters:
    volumetric_flow_rate (float): Volumetric flow rate in m³/s
    P1 (float): Pressure in Pascals
    T1 (float): Temperature in Kelvin

    Returns:
    float: Mass flow rate in kg/s
    """
    R_specific = 8314 / 28.97  # Specific gas constant (J/kmol*K)
    m_dot = (volumetric_flow_rate * P1) / (R_specific * T1)
    return m_dot

def compression_ratio(P2, P1):
    """
    Calculate compression ratio.

    Parameters:
    P2 (float): Final pressure after compression (Pa)
    P1 (float): Initial pressure before compression (Pa)

    Returns:
    float: Compression ratio (dimensionless)
    """
    if P1 == 0:
        raise ValueError("P1 cannot be zero to avoid division error.")
    
    rc = P2 / P1
    return rc