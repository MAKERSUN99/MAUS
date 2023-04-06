# MAUS
Arduino based Mouse Jiggler
<p align="center"><img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678098086510a.jpg" width="600" /></p>
<p align="center"><img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678098086495a.jpg" width="600" /></p>
<p align="center"><a href="https://www.tindie.com/stores/makersun/?ref=offsite_badges&utm_source=sellers_MAKERSUN&utm_medium=badges&utm_campaign=badge_large"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-larges.png" alt="I sell on Tindie" width="200" height="104"></a></p><br><br>
MAUS creates fake mouse movements to emulate activity and disable screensaver.
<br><br>
MAUS is a small and sometimes helpful tool which simulate mouse movements of 1 pixel up and down, making possible to work and enjoy relaxing lights :)
<br><br>
MAUS uses Arduino code on ATTINY85 chip booting MICRONUCLEUS.
<br><br>
MAUS featuring on board red led and WS2812B rgb led.
<br><br>
Arduino code and Kicad schematics are fully open source.<br><br>
<p align="center"><img src="https://github.com/MAKERSUN99/MAUS/blob/main/IMG/1678271177181.jpg" width="600" /></p>
Main Features:<br><br>
ATTINY85 MCU<br>
RED LED pin PB0<br>
WS2812B RGB LED on pin PB1<br>
PB2 PB3 and PB4 free to program<br>
DEFAULT FUSE SETTINGS:<br><br>
Lfuse: 0xE1 - (digispark default) PLL Clock + Startup 64 ms<br>
Hfuse: 0xDD - External Reset pin enabled (Pin5 not usable as I/O) + BOD 2.7 V + Enable Serial Program and Data Downloading<br>
Efuse: 0xFE - self programming enabled.<br><br>
MAUS comes with Arduino software installed, simply insert into USB<br>
Feels free to change software on your needs<br><br>
For setting up Arduino software:<br>
Board manager URL: http://digistump.com/package_digistump_index.json<br>
Adafruit Neopixel Library: To use this library, open the Library Manager in the Arduino IDE and install it from there.<br><br>
Micronucleus bootloader and info 
<a href="https://github.com/micronucleus/micronucleus" target="_blank"><u>here</u></a><br><br>
