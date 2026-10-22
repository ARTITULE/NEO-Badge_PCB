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
