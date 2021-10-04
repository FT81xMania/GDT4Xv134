#include <EEPROM.h>
#include <GDT4Xv134.h>

char TxT[50];
int VTlimpio[50];
int VTlleno[50];


void setup() {
  Serial.begin(9600);
  while (!Serial){}

  for ( unsigned int i = 0 ; i < 25 ; i++ )
  {
   EEPROM.write(i, 0);
   VTlimpio[i]=EEPROM.read(i);
   Serial.print(i); Serial.print(": "); Serial.println(VTlimpio[i]); 
  }
  
  GD.begin();
  
MP();
}

void loop(){}

void MP()
{

  for ( unsigned int i = 0 ; i < 25 ; i++ )
  {
   VTlleno[i]=EEPROM.read(i);
  }

while(1)
{
  GD.ClearColorRGB(0x00aa00); 
  GD.Clear();
  for ( unsigned int i = 0 ; i < 25 ; i++ )
  {
    sprintf(TxT, "Adress %d: %d", i,VTlimpio[i]);
    GD.cmd_text(60, 10+18*i, 28, OPT_CENTER, TxT);
  }

  for ( unsigned int i = 0 ; i < 25 ; i++ )
  {
    sprintf(TxT, "Adress %d: %d", i,VTlleno[i]);
    //Serial.print(i); Serial.print(": "); Serial.println(VTlleno[i]); 
    GD.cmd_text(60+200, 10+18*i, 28, OPT_CENTER, TxT);
  }  
  GD.swap();
  
}
}
