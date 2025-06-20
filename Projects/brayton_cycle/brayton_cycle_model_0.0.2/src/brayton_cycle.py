from components.ideal_brayton_cycle import ideal_brayton_cycle
from components.irreversibilities_brayton_cycle import irreversibilities_brayton_cycle
from components.initial_conditions import P1, P4, T1, T3, rc, volumetric_flow_rate, isentropic_turbine_eff,isentropic_compressor_eff
from libraries.performance_metrics import performance_metrics
from libraries.general_functions import volumetric_to_mass_flow_rate
from libraries.get_fluid_properties import get_fluid_properties

def main():
    print("Running Brayton Cycle Model...\n")

    # ------------------------------------------------ Preliminary calculations ----------------------------------------------------------
    P3 = P1 * rc
    m_dot = volumetric_to_mass_flow_rate(volumetric_flow_rate, P1, T1)
    
    # ----------------------------------------------------- Fluid properties -------------------------------------------------------------
    h_1_s, pr_1_s, h_3_s, pr_3_s = get_fluid_properties(T1, T3)
    
    # --------------------------------------------------- Ideal Brayton Cycle-------------------------------------------------------------

    print(f"Running the Ideal Brayton Cycle...")
    Wc_s, Wt_s = ideal_brayton_cycle(rc, P3, P4, h_1_s, pr_1_s, h_3_s, pr_3_s)

    # ----------------------------------------------------- Irreversibilities ------------------------------------------------------------

    print(f"Applying irreversibilities...\n")
    Wc, Wt, Qin, Qout = irreversibilities_brayton_cycle(Wc_s, Wt_s, h_1_s, h_3_s, isentropic_compressor_eff, isentropic_turbine_eff)
    
    # ------------------------------------------------ Work, efficiency, and power output ------------------------------------------------
    
    Wnet_work_based, Wnet_heat_based, bwr, thermal_efficiency, power_output = performance_metrics(Wc, Wt, Qin, Qout, m_dot)
   
    # --------------------------------------------------------- Print results ---------------------------------------------------------
    print(f"RESULTS:\n")
    print(f"    Mass Flow = {m_dot:.2f} m3/s")
    print(f"    Work input and output:\n    Work In = {Wc:.2f} kJ/kg | Work Out = {Wt:.2f} kJ/kg | Net Work (work based) = {Wnet_work_based:.2f} kJ/kg | Net Work (heat based) = {Wnet_heat_based:.2f} kJ/kg")
    print(f"    Power, BWR and Efficiency:\n    Power Output = {power_output:.1f} kW | Back work ratio = {bwr:.1f} % | Efficiency = {thermal_efficiency:.1f} %\n")
    print("Turbine Model Execution Complete.")

if __name__ == "__main__":
    main()