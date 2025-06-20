def performance_metrics(Win, Wout, Qin, Qout, m_dot):
    """
    Computes key performance metrics for a Brayton cycle based on energy inputs and outputs.

    Args:
        Win (float): Work input to the compressor [kJ/kg]
        Wout (float): Work output from the turbine [kJ/kg]
        Qin (float): Heat added to the cycle [kJ/kg]
        Qout (float): Heat rejected from the cycle [kJ/kg]
        m_dot (float): Mass flow rate of the working fluid [kg/s]

    Returns:
        tuple: (Wnet_work_based, Wnet_heat_based, bwr, thermal_efficiency, power_output)
            Wnet_work_based  - Net specific work based on Wout - Win [kJ/kg]
            Wnet_heat_based  - Net specific work based on Qin - Qout [kJ/kg]
            bwr              - Back work ratio [%]
            thermal_efficiency - Thermal efficiency of the cycle [%]
            power_output     - Total power output of the cycle [kW]
    """
    # Net work calculations
    Wnet_work_based = Wout - Win  # Net work output based on work difference
    Wnet_heat_based = Qin - Qout # Net work output based on heat balance
    bwr = Win / Wout * 100 # Back work ratio
    # Efficiency calculation
    thermal_efficiency = Wnet_work_based / Qin * 100 # In %
    # Power output calculation (assuming mass flow rate is known)
    power_output = Wnet_work_based * m_dot  # Total power output of the cycle (kW)

    return Wnet_work_based, Wnet_heat_based, bwr, thermal_efficiency, power_output