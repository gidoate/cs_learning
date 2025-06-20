def diffuser(h_a, P_a, V_a):
    V_1 = 0 # Fluid speed at the entry of the compressor equal to 0
    h_1 = h_a + (V_a**2)/2 # comes from the equation accross a diffuser -> (h_2 - h_1) = (V_1^2 - V_2^2)/2

    return h_1, V_1
