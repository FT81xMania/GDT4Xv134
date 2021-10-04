char Board[40];
char Pinout[50];
int ClaveBoard;

void IDEMCU()
{
     ClaveBoard=0;
     sprintf(Board, "MCU: None               (%d)", ClaveBoard);

  #if defined(ARDUINO_ARCH_STM32)
     ClaveBoard=1;
     if (STM32_CPU==4070){sprintf(Board, "MCU: STM32 F407 M4DEMO_SD"); MCUID=4070;}
     if (STM32_CPU==4071){sprintf(Board, "MCU: STM32 F407 M4DEMO_SDIO"); MCUID=4071;}
     if (STM32_CPU==429){sprintf(Board, "MCU: STM32 F49I-DISCO"); MCUID=429;}
     if (STM32_CPU==746){sprintf(Board, "MCU: STM32 Core7XXI"); MCUID=746;}
     if (STM32_CPU==767){sprintf(Board, "MCU: STM32 Nucleo-F767ZI"); MCUID=767;}
  #endif

#ifdef TEENSYDUINO
     ClaveBoard=2;
  #if defined(__IMXRT1052__)
   sprintf(Board, "MCU: Teensy 4 beta");
  #endif
      
 //#if defined(__IMXRT1062__)
  #if defined(ARDUINO_TEENSY40)
    sprintf(Board, "MCU: Teensy 4");
  #endif

  #if defined(ARDUINO_TEENSY41)
    sprintf(Board, "MCU: Teensy 4.1");
  #endif
     //#else
     
  #if defined(ARDUINO_TEENSY36)
    sprintf(Board, "MCU: Teensy 3.6");
  #endif

  #if defined(ARDUINO_TEENSY35)
    sprintf(Board, "MCU: Teensy 3.5");
  #endif

  #if defined(ARDUINO_TEENSY32)
    sprintf(Board, "MCU: Teensy 3.2");  //Teensy 3.2/3.1
    sprintf(Pinout, "SD_PIN: %d", SD_PIN);
    GD.cmd_text(GD.w-45, (GD.h)-60+16, 20, OPT_CENTER, Pinout);

    //sprintf(Pinout, "SDSpeed: %d", SetSDSpeed);
    //GD.cmd_text(GD.w-45, (GD.h)-60-16-16, 20, OPT_CENTER, Pinout);
  #endif

  #if defined(ARDUINO_TEENSY30)
    sprintf(Board, "MCU: Teensy 3.0");
  #endif
     
 //#endif
#endif

  #ifdef __DUE__
     ClaveBoard=3;
     sprintf(Board, "MCU: Arduino Due");
  #endif

  #ifdef ESP8266
     ClaveBoard=4;
     sprintf(Board, "MCU: ESP8266");
  #endif

  #if defined(ESP32)
     ClaveBoard=5;
     sprintf(Board, "MCU: ESP32");
  #endif

  #if !defined(TEENSYDUINO)&& !defined(ESP32)&& !defined(__DUE__)&& !defined(ESP8266)&& !defined(ARDUINO_ARCH_STM32)&& defined(ARDUINO)
     ClaveBoard=6;
     sprintf(Board, "MCU: Arduino MEGA/UNO");
  #endif
}

char TXP[50];

void Parametros()
{
  GD.SaveContext();
  
  GD.ColorRGB(0x00ff00);
  sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  
  
  GD.cmd_text(3, (GD.h)-18, 26, 0, TXP);
  GD.cmd_text(115, (GD.h)-18, 26, 0, Board);
      
  GD.RestoreContext();
}
