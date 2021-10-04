//#include <GD23ZUTX.h>
#include <GDT4Xv134.h>

Bitmap Background,SaidHello;

void setup()
{
  GD.begin();
  //Background.fromfile("dog.jpg");
  //Background.fromfile("tree.jpg");
  //Background.fromfile("Fn1.jpg");
  Background.fromfile("wrc.jpg");
  SaidHello.fromtext(20, "BT817 --- Teensy 4.x");
  MP();
}
void loop(){}

void MP()
{
  int ANG=0;

  int minPX = 10; int maxPX = 800-minPX;
  int movX = minPX;
  int deltaenX = 1;

  int minPY = 10; int maxPY = 475-minPY;
  int movY = minPY;
  int deltaenY = 1;  

while(1)
{
  ANG = ANG + 1;
  if (ANG>=360){ANG=0;}

  movX = movX + deltaenX;
  if(movX >= maxPX){deltaenX = -1;}
  if(movX <= minPX){deltaenX = 1;}

  movY = movY + deltaenY;
  if(movY >= maxPY){deltaenY = -1;}
  if(movY <= minPY){deltaenY = 1;}  
  
  GD.ClearColorRGB(0x000055);
  GD.Clear();

  GD.ColorA(144);
  Background.draw(GD.w / 2, GD.h / 2);
  GD.ColorA(255);
  
  GD.ColorRGB(0xffffff); SaidHello.draw(10, 240, DEGREES(270));
  GD.ColorRGB(0xffffff); SaidHello.draw(795, 240, DEGREES(270));
  GD.ColorRGB(0xffffff); SaidHello.draw(400, 10, DEGREES(0));
  GD.ColorRGB(0xffffff); SaidHello.draw(400, 120, DEGREES(ANG));
  GD.ColorRGB(0xffffff); SaidHello.draw(400, 240, DEGREES(0));
  GD.ColorRGB(0xffffff); SaidHello.draw(400, 360, DEGREES(ANG*(-1)));

  GD.ColorRGB(0xffffff); SaidHello.draw(movX, movY, DEGREES(ANG*(-1)));
  
  GD.ColorRGB(0xffffff); SaidHello.draw(400, 475, DEGREES(0));

  GD.swap(); 
 }
}
