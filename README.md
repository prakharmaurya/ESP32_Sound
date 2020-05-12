# ESP32_Sound
Control your speaker with with ESP32 (8-bit)

# ESP32 Produce Sounds of piano notes
I'm using DAC Pin to perform this action.

# Concept
I tried to produce sin wave of different frequency by changing the 
1. dealy betwwen each steps of voltages (Wait time at each steps produces low frequency.)
2. By Changing the number of steps (Low steps means high frequency at lower resolution.)
![](/Capture.PNG)

# How To Use
There are three arrays
0. Connect AUX cable of speaker(mono only) to Pin 25 and Pin 26
1. fun_ptr_arr => to store fn which play notes of specific frequency eg. NOTE_A5
  Which notes you want to play you have to fill line by line in this array.
2. repeat => this array plays same as long as you want this is like #Tempo
3. delayTime => This is the delay time between each note as you want to adjust

# Implementation
# Problem - 1 DAC can produce only 0V to 3.3V only so this will result in to transfer the #DC in Speaker which is bad
  To overcome this problem I tried to set the other dac Pin 26 to 128 level ( result in 1.65V ). This works like offset now the Voltage     difference between your speaker souldn't result in #DC to your speker or you can User Capcitor to block #DC
# Problem - 2 Your normal speaker does draw more than 20 mili Amp Out of the capblility of Digital Boards
  Use transistor amplifier
  Use AUX
  Or user your earphones may be safe but check first for #DC
# Problem - 3 NOTE Implementation
  I user an android app to analyze frequency
  Some NOTES
  
  ![](/Capture1.PNG)
# Problem - 4 Huge fn call list 
  passed fn as pointer in array
  
# Need to be Implemented
  Make Class and Object and header as lib implementation
