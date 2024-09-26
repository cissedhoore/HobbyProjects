# bfsBasicNode

## Introduction
The first step of this project would be to create a basic starting node as a proof of concept. This node will be called the bfsBasicNode and will used to demonstrate how the system works and as a template to create the other nodes. The node needs to be able to communicate in a wireless way and should possess some simple inputs and outputs (like buttons and LED's for example). The node also needs to be programmable and has to have a good powersource.

## Project Overview

### Components
- ATMEGA32u4 microcontroller
- nRF24L rf-module
- 3v3 LDO
- micro USB port

### bfsBasicNodeV1.0

Link to hardware: https://easyeda.com/cissedhoore/home-system

#### Issues
Some components are to small to be soldered by hand. Like for example the ESD protection [SOT563] and the RF-chip [QFN20].
USB connection to the ATMEGA doesn't work even after flashing the bootloader on the ATMEGA trough ISP connector.  

### bfsBasicNodeV1.1
Usage of the Velleman nRF24L module.  
Cleaner USB connections.  

#### Issues
USB connection to the ATMEGA still doesn't work.
Wireless communication module still needs to be tested.

#### Possible Improvements
Try to work with an Arduino Uno instead of the ATMEGA chip to reduce the chance that it doesn't work.
Try to figure out why the USB communication doesn't work.
