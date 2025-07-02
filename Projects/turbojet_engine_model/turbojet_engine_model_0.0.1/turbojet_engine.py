#from components.brayton_cycle import brayton_cycle
from components.diffuser.diffuser import diffuser
#from components.nozzle import nozzle
from components.initial_conditions import P1, T1, V1, V2

def main():
    # -------------------------------- Diffuser ----------------------------
    h2, T2, P2 = diffuser(P1, T1, V1)
    print(f"Diffuser output:\nh2 (kJ/kg) = {h2:.2f} kJ/kg | T2 (K) = {T2:.2f} K | P2 (Pa) = {P2:.2f} Pa\n")

    P5 = P2 # Pressure at the last state of the Brayton Cycle shall be the same as 

if __name__ == "__main__":
    main()