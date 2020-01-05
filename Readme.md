# Simple temperature PID control project
This is a project for Application Electronic course at my university. The purpose of this project is to control temperature of a small heating block with a 12V/40W heater and 100k NTC thermistor. These components are used in a 3D printer at my laboratory.

# Usage 
## Hardware
The board is designed with Altium Designer
<p align="center">
  <img src="Images/Board_3D.PNG" width="350" title="Board 3D">
</p>

### Out of board components
<p align="center">
  <img src="Images/heating_block.jpg" width="180" title="Heating block">
  <img src="Images/12v-40w-3d-printer-heater.jpg" width="180" title="12V/40V 3D printer heater">
    <img src="Images/100k-ohm-ntc-thermistor-500x500.jpg" width="180" title="100k Ohm NTC thermistor">
</p>

As we can see from above, there are 3 out of board components needed for this project:

* Heating block
* 12V/40V 3D rinter heater
* 100k Ohm NTC thermistor

## Firmware
I use CubeMX to generate code for STM32F103C8T6 MCU in BluePill board. System Workbench IDE is used for code editing and building as well as programming the MCU.

# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

# License
[MIT](https://choosealicense.com/licenses/mit/)
