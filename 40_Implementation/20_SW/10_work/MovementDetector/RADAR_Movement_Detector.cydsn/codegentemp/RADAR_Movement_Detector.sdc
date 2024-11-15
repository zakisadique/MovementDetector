# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\zakis\Documents\SDHD_FFT\MovementDetector\40_Implementation\20_SW\10_work\MovementDetector\RADAR_Movement_Detector.cydsn\RADAR_Movement_Detector.cyprj
# Date: Mon, 08 Jul 2024 11:52:24 GMT
#set_units -time ns
create_clock -name {ADC_DelSig_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {WaveDAC8_DacClk(routed)} -period 33333.333333333328 -waveform {0 16666.6666666667} [list [get_pins {ClockBlock/dclk_2}]]
create_clock -name {Clock_DMA_MEM_UART(routed)} -period 2000000 -waveform {0 1000000} [list [get_pins {ClockBlock/dclk_3}]]
create_clock -name {Clock_DMA_FFT_UART(routed)} -period 2000000 -waveform {0 1000000} [list [get_pins {ClockBlock/dclk_4}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {ADC_DelSig_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {UART_LOG_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 27 53} -nominal_period 1083.3333333333333 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {ADC_DelSig_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 189 377} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {WaveDAC8_DacClk} -source [get_pins {ClockBlock/clk_sync}] -edges {1 801 1599} -nominal_period 33333.333333333328 [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_DMA_MEM_UART} -source [get_pins {ClockBlock/clk_sync}] -edges {1 48001 96001} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Clock_DMA_FFT_UART} -source [get_pins {ClockBlock/clk_sync}] -edges {1 48001 96001} [list [get_pins {ClockBlock/dclk_glb_4}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\zakis\Documents\SDHD_FFT\MovementDetector\40_Implementation\20_SW\10_work\MovementDetector\RADAR_Movement_Detector.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\zakis\Documents\SDHD_FFT\MovementDetector\40_Implementation\20_SW\10_work\MovementDetector\RADAR_Movement_Detector.cydsn\RADAR_Movement_Detector.cyprj
# Date: Mon, 08 Jul 2024 11:52:20 GMT
