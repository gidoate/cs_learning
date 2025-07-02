def irreversibilities_brayton_cycle(Wc_s, Wt_s, h_1, h_3, isentropic_compressor_eff, isentropic_turbine_eff):
    """
    Calculates the actual work and heat values in a Brayton cycle by accounting for isentropic 
    inefficiencies in the compressor and turbine.

    Args:
        Wc_s (float): Isentropic work input to the compressor [kJ/kg].
        Wt_s (float): Isentropic work output from the turbine [kJ/kg].
        h_1 (float): Enthalpy at the compressor inlet [kJ/kg].
        h_3 (float): Enthalpy at the turbine inlet [kJ/kg].
        isentropic_compressor_eff (float): Isentropic efficiency of the compressor (0 < eff ≤ 1).
        isentropic_turbine_eff (float): Isentropic efficiency of the turbine (0 < eff ≤ 1).

    Returns:
        tuple: (Wc, Wt, Qin, Qout)
            Wc   - Actual work input to the compressor [kJ/kg]
            Wt   - Actual work output from the turbine [kJ/kg]
            Qin  - Actual heat added during heat addition [kJ/kg]
            Qout - Actual heat rejected during heat rejection [kJ/kg]
    """
    # Actual compressor work in
    Wc = Wc_s / isentropic_compressor_eff

    # Actual turbine work output
    Wt = Wt_s * isentropic_turbine_eff

    # Actual heat addition
    h_2 = h_1 + Wc
    Qin = h_3 - h_2

    # Actual heat rejection (TBD)
    Qout = Qin - (Wt - Wc)

    return Wc, Wt, Qin, Qout