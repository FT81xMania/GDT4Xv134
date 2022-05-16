![FT81xMania](logo.png?raw=true "GDXT4X")

![FT81xMania](logo2.gif?raw=true "GDXT4X")

# MexSpa Team contribution for [FT81xMania](https://ft81xmania.com/comunidad/)

# GDT4Xv134 Library
Library only for Teensy 3.5/6, Teensy 4 and Teensy 4.1; based on Gameduino 23X library. This library can use the resources of the SdFat beta 2 of Greiman (https://github.com/greiman/SdFat-beta) in order to manage media files like assets, cells, avi, png, jpeg, jpg or avi files from the SDIO reader. Situable for **for FTDI EVE2 or EVE3 chips like FT810, FT811, FT813, BT815/BT817.

This version allows you to connect screens with FT800 and FT801 chips, previously they had been left without support, with what has been learned it is possible to manage multimedia files with the SdFat beta library, except that these screens cannot process video files.

# History
We are an enthusiastic team of screens based on [FTDI chip](http://www.ftdichip.com/EVE.htm). We like programming and share our advances. We have reached this goal, our only interest is to give the opportunity to operate this library to multiple platforms of MCU's in the market. Wait for you to enjoy the codes, of our, your time.
Two friends, in Mexico and another in Spain, the water or the puddle does not scare us ...
Last month of May, a member of the Team, we left. We move on.
Without any interest, we publish this library altruistically.

# 03-03-2021: Release initial (GDT4Xv134)


1. Library based on gameduino 23X lib of [James Bowman](https://github.com/jamesbowman/gd2-lib)
2. Library based on [STM32_GD2](https://github.com/nopnop2002/STM32_GD2) user **@nopnop2002** this [link](http://stm32duino.com/viewtopic.php?f=9&t=3466#p44477)

Library with function special **playback videos**. 

# Teensy support 
    
* Teensy 3.5 and Teensy 3.6
* Teensy 4
* Teensy 4.1

# 16-05-2022: Actualización para soportar STM32: F411CE y F407VG

El objetivo principal es poder conectar las pantallas FT81x/BT81x en placas como la teensy 4 y 4.1 aprovechando el poder de la libreria SdFat y el lector SDIO nativo en estas MCU. Con algunos ajustes mínimos ha sido posible conectar placas STM32 como la F411CE y la F407VG, que gracias a su formato reducido las vuelven ideales para proyectos en los que el espacio es una limitante. 

El núcleo oficial para STM32 no permite obtener todo el potencial de la libreria SdFat mas reciente, se ha utilizado el nucleo alternativo desarrollado cor Danieleff (https://github.com/danieleff/STM32GENERIC). El TFT está conectado en el bus SPI1 y el lector microSD está conectado en SPI2.


In memory of my brother Tomas. Thank You!
