"""Contains the calculations for all thermodynamic processes within the cycle
Nomenclature:
    - _i : initial state
    - _f : final state
"""
from libraries.fluid_properties_db_retrieve import get_fluid_properties_fromPr

def isentropic_compression(rc, h_i, pr_i):
    """Computes final temperature and work during isentropic compression"""
    # Compute final pr using the compression ratio
    pr_f = rc * pr_i
    print(f"pr_f = {pr_i:.2f}")

    # Search for enthalpy corresponding to pr_2
    h_fs, t_fs = get_fluid_properties_fromPr(pr_f)  # This returns a dictionary

    # Compute work done by the compressor (kJ/kg)
    Wc_s = (h_fs - h_i)

    return h_fs, Wc_s  # Return values for subsequent calculations

def isentropic_expansion(Pi, Pf, h_i, pr_i):
    """Computes the isentropic expansion process in a turbine."""
    
    # Compute final pr after expansion
    pr_f = (Pf / Pi) * pr_i

    # Search for enthalpy corresponding to pr_4
    h_fs, t_fs = get_fluid_properties_fromPr(pr_f)  # This returns a dictionary
    
    # Compute work produced by the turbine (kJ/kg)
    Wt = (h_i - h_fs)
    
    return h_fs, Wt  # Return final temperature and turbine work

def isobaric_heat_addition(h_i, h_f):
    """Computes the heat added during the isobaric heat addition stage."""

    # Compute heat added (kJ/kg)
    Qin = h_f - h_i 

    return Qin  # Return heat input for use in subsequent turbine stages

def isobaric_heat_rejection(h_f, h_i):
    """Computes the heat rejected during the isobaric heat rejection stage."""
    
    # Compute heat rejected (kJ/kg)
    Qout = h_i - h_f # h1 - h4

    return Qout  # Return heat output for further calculations
