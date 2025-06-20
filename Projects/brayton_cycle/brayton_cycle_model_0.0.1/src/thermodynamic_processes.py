"""Contains the calculations for all thermodynamic processes within the cycle"""

from fluid_properties import get_cp_cv_h

def isentropic_compression(T1, cp, gamma, rc, isentropic_compressor_eff):
    """Computes final temperature and work during isentropic compression"""
    # Compute final temperature using the isentropic relation
    T2 = T1 * (rc ** ((gamma - 1) / gamma)) 
    
    # Compute work done by the compressor (kJ/kg)
    Wc = cp * (T2 - T1) / isentropic_compressor_eff

    return T2, Wc  # Return values for subsequent calculations

def isentropic_expansion(P3, P4, T3, cp, gamma, isentropic_turbine_eff):
    """Computes the isentropic expansion process in a turbine."""
    
    # Compute temperature after expansion using isentropic relation
    T4 = T3 * (P4 / P3) ** ((gamma - 1) / gamma) 
    
    # Compute work produced by the turbine (kJ/kg)
    Wt = cp * (T3 - T4) * isentropic_turbine_eff
    
    return T4, Wt  # Return final temperature and turbine work

def isobaric_heat_addition(T2, T3, cp):
    """Computes the heat added during the isobaric heat addition stage."""
        
    # Compute heat added (kJ/kg)
    Qin = cp * (T3 - T2)  

    return Qin  # Return heat input for use in subsequent turbine stages

def isobaric_heat_rejection(T1, T4, cp):
    """Computes the heat rejected during the isobaric heat rejection stage."""
    
    # Compute heat rejected (kJ/kg)
    Qout = cp * (T1 - T4)  

    return Qout  # Return heat output for further calculations
