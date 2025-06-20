import pandas as pd
import src.components.initial_conditions as init

from src import brayton_cycle

def main():
    df = pd.read_csv("data/rc_sweep.csv")
    df.columns = df.columns.str.strip()
    
    results = []

    for i, row in df.iterrows():
        init.P1 = row["P1"]
        init.P4 = row["P4"]
        init.rc = row["rc"]
        init.T1 = row["T1"]
        init.T3 = row["T3"]
        init.volumetric_flow_rate = row["volumetric_flow_rate"]
        init.isentropic_turbine_eff = row["isentropic_turbine_eff"]
        init.isentropic_compressor_eff = row["isentropic_compressor_eff"]

        print(f"\n--- Simulation {i+1} | rc = {row['rc']} | T1 = {init.T1} K | T3 {init.T3} K ---")
        result = brayton_cycle.main(init.P1, init.P4, init.T1, init.T3, init.rc,
                                    init.volumetric_flow_rate, init.isentropic_compressor_eff,
                                    init.isentropic_turbine_eff)
        results.append(result)

    pd.DataFrame(results).to_csv("data/rc_sweep_results.csv", index=False)
    print("\n✅ Results saved to data/rc_sweep_results.csv")


if __name__ == "__main__":
    main()
