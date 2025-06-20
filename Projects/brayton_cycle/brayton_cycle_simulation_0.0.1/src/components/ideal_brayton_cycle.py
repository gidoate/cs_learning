from src.libraries.thermodynamic_processes import isentropic_compression, isobaric_heat_addition, isentropic_expansion, isobaric_heat_rejection

def ideal_brayton_cycle(rc, P3, P4, h_1_s, pr_1_s, h_3_s, pr_3_s):
    """
    Simulates an ideal Brayton cycle composed of four thermodynamic processes:
    1. Isentropic compression
    2. Isobaric heat addition
    3. Isentropic expansion
    4. Isobaric heat rejection

    Args:
        rc (float): Compression ratio.
        P3 (float): Pressure at the start of expansion (high-pressure side).
        P4 (float): Pressure at the end of expansion (low-pressure side).
        h_1_s (float): Enthalpy at the beginning of compression (isentropic).
        pr_1_s (float): Pressure ratio at the beginning of compression (isentropic).
        h_3_s (float): Enthalpy at the beginning of expansion (isentropic).
        pr_3_s (float): Pressure ratio at the beginning of expansion (isentropic).

    Returns:
        tuple: (Wc_s, Wt_s, Qin_s, Qout_s)
            Wc_s: Work input during isentropic compression [kJ/kg]
            Wt_s: Work output during isentropic expansion [kJ/kg]
            Qin_s: Heat input during isobaric heat addition [kJ/kg]
            Qout_s: Heat output during isobaric heat rejection [kJ/kg]
    """
    # ------------------------------------------- Process 1: Isentropic Compression -------------------------------------------------------
    
    h_2_s, Wc_s  = isentropic_compression(rc, h_1_s, pr_1_s) # xxx_s for ISENTROPIC variables
    print(f"Stage 1 - Compression Stage:\nh_1= {h_1_s:.2f} K | h_2_s = {h_2_s:.2f} K | Work input (ideal) = {Wc_s:.2f} kJ/kg\n")

    # ------------------------------------------- Process 2: Isobaric Heat Addition ------------------------------------------------------
   
    Qin_s = isobaric_heat_addition(h_2_s, h_3_s)
    print(f"Stage 2 - Heat Addition Stage:\nh_3 = {h_3_s:.2f} K | Heat Input (ideal) = {Qin_s:.2f} kJ/kg\n")

    # -------------------------------------------- Process 3: Isentropic Expansion ------------------------------------------------------
    
    h_4_s, Wt_s = isentropic_expansion(P3, P4, h_3_s, pr_3_s)
    print(f"Stage 3 - Expansion Stage:\nh_4_s = {h_4_s:.2f} K | Work Output (ideal) = {Wt_s:.2f} kJ/kg\n")

    # --------------------------------------------- Process 4: Isobaric Heat Rejection --------------------------------------------------
    
    Qout_s = isobaric_heat_rejection(h_1_s, h_4_s)
    print(f"Stage 4 - Heat Rejection Stage:\nHeat Output (ideal) = {Qout_s:.2f} kJ/kg\n")

    return Wc_s, Wt_s