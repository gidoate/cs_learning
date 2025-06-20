from components.brayton_cycle.components.ideal_brayton_cycle import ideal_brayton_cycle
from components.brayton_cycle.components.irreversibilities_brayton_cycle import irreversibilities_brayton_cycle
from libraries.performance_metrics import performance_metrics
from libraries.general_functions import volumetric_to_mass_flow_rate
from libraries.get_fluid_properties import get_fluid_properties

def brayton_cycle(P1, P4, T1, T3, rc, volumetric_flow_rate, isentropic_turbine_eff,isentropic_compressor_eff):
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
   
    if (Wnet_work_based != Wnet_heat_based):
        return print(f"\nBrayton Cycle calculation fail (Wnet_work != Wnet_heat). Ending simulation...")
    else:
        return Wnet_work_based, bwr, thermal_efficiency,power_output