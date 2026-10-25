# NEO-Badge_PCB

A Battery powered badge with a 8x8 0603 SMD LED matrix made using the 10 cent Ch32v003 Risc-V microcontroller.

It can be used to display some cool effects. Also you can wear it, like a badge!

I made it mostly for show and tell but also as a part of my week 1 submission to Half Life.

| Front Picture | Back Picture |
|---------------|--------------|
| ![front](/Pic/3D_NEO-Badge_PCB_v1.0_Front.png) | ![back](/Pic/3D_NEO_Badge_PCB_v1.0_Back.png) |

## PCB Design

The PCB is a 4 Layer board that is powered with a coin cell battery. The circuit uses the (10 cent) ch32v003 RISC-V microcontroller to show graphics on a 8x8 matrix display. All the parts are meant to be soldered onto the PCB. All the PCB files can be found in the [PCB_Files](/PCB_Files/) folder.

For anyone interested here is the schematic:
![schematic](/Pic/SCH_Schematic1_1-P1_2026-10-11.svg)

## Firmware

Since the matrix requires 16 pins and the button and the programming interface requires one each, together with the two power pins we come to the chips 20. So we need to use the XTAL1, XTAL2 and NRST pins as GPIO. PlatformIO takes care of the crystal pins but you need to set the NRST pin manually.

In the [Reset_Unlock](/Reset_Unlock/) folder you can find the file that needs to be uploaded ONCE to the microcontroller. So copy the [reset_unlock.cpp](/Reset_Unlock/reset_unlock.cpp) file contents into [main.cpp](/src/main.cpp) and upload the code. Then just undo the changes in the file and upload normally.

## Installation

1. Clone or download the repo.
2. Initialize the PlatformIO extension
3. Connect the WCH LINK-E programmer.
4. Select the "NEO_Badge_PCB" environment.
5. Follow the steps written in the [firmware section](#firmware).
6. Flash the actual firmware. That's it!

## BOM

|Item                          |Qty|Supplier|Cost/item|Total Cost|link                                                                                        |
|------------------------------|---|--------|---------|----------|--------------------------------------------------------------------------------------------|
|PCB and Stencil               |1  |JLCPCB  |$3.10    |$3.10     |[JLCPCB](https://jlcpcb.com)                                                                |
|0603 SMD Led(MOQ 50. MUL 50)  |100|LCSC    |$0.0123  |$1.23     |[LCSC](https://www.lcsc.com/product-detail/C2290.html?s_z=n_q_C2290&globalKeyword=C2290)    |
|WCH CH32V003F4P6(MOQ 5)       |5  |LCSC    |$0.3132  |$1.57     |[LCSC](https://www.lcsc.com/product-detail/C5187096.html?s_z=n_q_ch32v003)                  |
|Battery Holder CR2032(MOQ 5)  |5  |LCSC    |$0.0940  |$0.47     |[LCSC](https://www.lcsc.com/product-detail/C964833.html?s_z=n_q_C964833&globalKeyword=C964833)|
|Push Button(MOQ 20)           |20 |LCSC    |$0.0311  |$0.65     |[LCSC](https://www.lcsc.com/product-detail/C54407262.html?s_z=n_q_C54407262&globalKeyword=C54407262)|
|Power Switch                  |1  |LCSC    |$0.4788  |$0.4788   |[LCSC](https://www.lcsc.com/product-detail/C115375.html?s_z=n_q_C115375&globalKeyword=C115375)|
|300Ohm 0402 Resistors(MOQ 100)|100|LCSC    |$0.0019  |$ 0.19    |[LCSC](https://www.lcsc.com/product-detail/C25102.html?s_z=n_q_C25102&globalKeyword=C25102) |
|Estimated total shipping      |1  |        |         |$20.00    |                                                                                            |
|Estimated TOTAL               |   |        |         |$27.90    |                                                                                            |
