import pandas as pd
import plotly.graph_objects as go

# Load simulation results
df = pd.read_csv("data/rc_sweep_results.csv")

fig1 = go.Figure()
fig2 = go.Figure()

# Net Work
fig1.add_trace(go.Scatter(
    x=df["rc"],
    y=df["Wnet_work_based"],
    mode='lines+markers',
    name='Net Work (kJ/kg)',
    line=dict(color='blue'),
    marker=dict(symbol='circle')
))

# Thermal Efficiency
fig2.add_trace(go.Scatter(
    x=df["rc"],
    y=df["thermal_efficiency"],
    mode='lines+markers',
    name='Thermal Efficiency (%)',
    line=dict(color='red', dash='dash'),
    marker=dict(symbol='square')
))

# Layout
fig1.update_layout(
    title="Brayton Cycle: Net Work vs Compression Ratio",
    xaxis_title="Compression Ratio (rc)",
    yaxis=dict(
    title=go.layout.yaxis.Title(
        text="Net Work Output (kJ/kg)",
        font=dict(color="blue")
    ),
    tickfont=dict(color="blue"),
    range=[300, 1000]
    ),
    template='simple_white',
    hovermode="x unified"
)
fig2.update_layout(
    title="Brayton Cycle: Efficiency vs Compression Ratio",
    xaxis_title="Compression Ratio (rc)",
    yaxis=dict(
    title=go.layout.yaxis.Title(
        text="Thermal Efficiency (%)",
        font=dict(color="red")
    ),
    tickfont=dict(color="red"),
    range=[30, 100]
    ),  
    template='simple_white',
    hovermode="x unified"
)

fig1.show()
fig2.show()
