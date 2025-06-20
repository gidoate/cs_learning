from fluid_properties import get_cp_cv_h
from initial_conditions import P1, P2, P3, P4, T1, T3, volumetric_flow_rate, isentropic_turbine_eff,isentropic_compressor_eff
from general_functions import compression_ratio, volumetric_to_mass_flow_rate
from thermodynamic_processes import isentropic_compression, isobaric_heat_addition, isentropic_expansion, isobaric_heat_rejection

def main():
    print("Running Brayton Cycle Model...\n")

    # ------------------------------------------------ Preliminary calculations -----------------------------------------------------------
    rc = compression_ratio(P2, P1)
    m_dot = volumetric_to_mass_flow_rate(volumetric_flow_rate, P1, T1)

    # ------------------------------------------- Process 1: Isentropic Compression -------------------------------------------------------
    # Retrieve Cp an Cv
    properties = get_cp_cv_h(T1)  # This returns a dictionary

    if isinstance(properties, dict):
        cp = properties["Cp (kJ/kg*K)"]
        cv = properties["Cv (kJ/kg*K)"]
        gamma = cp / cv
    else:
        print("Temperature not found in database.")

    T2, Wc  = isentropic_compression(T1, cp, gamma, rc, isentropic_compressor_eff)
    print(f"Stage 1 - Compression Stage:\nT1= {T1:.2f} K | T2 = {T2:.2f} K | Work input = {Wc:.2f} kJ/kg\n")

    # ------------------------------------------- Process 2: Isobaric Heat Addition ------------------------------------------------------
    # Retrieve Cp an Cv
    properties = get_cp_cv_h((T2 + T3)/2)  # Cp and Cv at average temperature across the process

    if isinstance(properties, dict):
        cp = properties["Cp (kJ/kg*K)"]
        cv = properties["Cv (kJ/kg*K)"]
        gamma = cp / cv
    else:
        print("Temperature not found in database.")
        return
    
    Qin = isobaric_heat_addition(T2, T3, cp)
    print(f"Stage 2 - Heat Addition Stage:\nT3 = {T3:.2f} K | Heat Input = {Qin:.2f} kJ/kg\n")

    # -------------------------------------------- Process 3: Isentropic Expansion ------------------------------------------------------
    # Retrieve Cp an Cv
    properties = get_cp_cv_h((T3))

    if isinstance(properties, dict):
        cp = properties["Cp (kJ/kg*K)"]
        cv = properties["Cv (kJ/kg*K)"]
        gamma = cp / cv
    else:
        print("Temperature not found in database.")
        return
    T4, Wt = isentropic_expansion(P3, P4, T3, cp, gamma, isentropic_turbine_eff)
    print(f"Stage 3 - Expansion Stage:\nT4 = {T4:.2f} K | Work Output = {Wt:.2f} kJ/kg\n")

    # --------------------------------------------- Process 4: Isobaric Heat Rejection --------------------------------------------------
    # Retrieve Cp an Cv
    properties = get_cp_cv_h((T1 + T4)/2)  # This returns a dictionary

    if isinstance(properties, dict):
        cp = properties["Cp (kJ/kg*K)"]
        cv = properties["Cv (kJ/kg*K)"]
        gamma = cp / cv
    else:
        print("Temperature not found in database.")
        return
    Qout = isobaric_heat_rejection(T1, T4, cp)
    print(f"Stage 4 - Heat Rejection Stage:\nHeat Output = {Qout:.2f} kJ/kg\n")

    # ------------------------------------------------ Work, efficiency, and power output ----------------------------------------------
    Win = Wc  # Work into the system (compressor work)
    Wout = Wt  # Work outside the system (turbine work)
    # Net work calculations
    Wnet_work_based = Wt - Wc  # Net work output based on work difference
    Wnet_heat_based = Qin + Qout # Net work output based on heat balance
    bwr = Wc / Wt * 100 # Back work ratio
    # Efficiency calculation
    efficiency = Wnet_work_based / Qin * 100 # In %
    # Power output calculation (assuming mass flow rate is known)
    power_output = Wnet_work_based * m_dot  # Total power output of the cycle (kW)

    # --------------------------------------------------------- Print results ---------------------------------------------------------
    print(f"Work and effiency:\nWork In = {Win:.2f} kJ/kg | Work Out = {Wout:.2f} kJ/kg | Net Work (work based) = {Wnet_work_based:.2f} kJ/kg | Net Work (heat based) = {Wnet_heat_based:.2f} kJ/kg | Efficiency = {efficiency:.2f} %\n")
    print(f"Mass flow and Power:\nMass Flow = {m_dot:.2f} m3/s | Power Output = {power_output:.2f} kW | Back work ratio = {bwr:.2f} %\n")
    print("Turbine Model Execution Complete.")

if __name__ == "__main__":
    main()
