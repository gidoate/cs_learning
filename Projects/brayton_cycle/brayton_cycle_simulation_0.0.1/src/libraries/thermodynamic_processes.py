"""Contains the calculations for all thermodynamic processes within the cycle"""

from src.libraries.fluid_properties_db_retrieve import get_fluid_properties_fromPr

def isentropic_compression(rc, h_1, pr_1):
    """Computes final temperature and work during isentropic compression"""
    # Compute final pr using the compression ratio
    pr_2 = rc * pr_1
    print(f"pr_2 = {pr_2:.2f}")

    # Search for enthalpy corresponding to pr_2
    properties = get_fluid_properties_fromPr(pr_2)  # This returns a dictionary

    if isinstance(properties, dict):
        h_2s = properties["h (kJ/kg)"]    
    else:
        print("pr not found in database.")
    
    # Compute work done by the compressor (kJ/kg)
    Wc_s = (h_2s - h_1)

    return h_2s, Wc_s  # Return values for subsequent calculations

def isentropic_expansion(P3, P4, h_3, pr_3):
    """Computes the isentropic expansion process in a turbine."""
    
    # Compute final pr after expansion
    pr_4 = (P4 / P3) * pr_3 

    # Search for enthalpy corresponding to pr_4
    properties = get_fluid_properties_fromPr(pr_4)  # This returns a dictionary

    if isinstance(properties, dict):
        h_4 = properties["h (kJ/kg)"]    
    else:
        print("pr not found in database.")
    
    # Compute work produced by the turbine (kJ/kg)
    Wt = (h_3 - h_4)
    
    return h_4, Wt  # Return final temperature and turbine work

def isobaric_heat_addition(h_2, h_3):
    """Computes the heat added during the isobaric heat addition stage."""

    # Compute heat added (kJ/kg)
    Qin = h_3 - h_2  

    return Qin  # Return heat input for use in subsequent turbine stages

def isobaric_heat_rejection(h_1, h_4):
    """Computes the heat rejected during the isobaric heat rejection stage."""
    
    # Compute heat rejected (kJ/kg)
    Qout = h_4 - h_1

    return Qout  # Return heat output for further calculations
