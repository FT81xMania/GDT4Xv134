#include <GDT4Xv134.h>

int MCUID;

void setup()
{
  GD.begin();

  GD.cmd_loadimage(0, 0);
  GD.load("6oBaa.jpg");
  
  IDEMCU();
}

void loop()
{
GD.Clear();

 GD.SaveContext();
  GD.Begin(BITMAPS);
  GD.Vertex2ii(0, 0);
 GD.RestoreContext();

  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");

 GD.SaveContext();
  GD.Begin(LINES);
  GD.ColorRGB(255,255,255);
  GD.Vertex2f(0*16, 0*16);    GD.Vertex2f((GD.w)*16, 0*16);  //Superior
  GD.Vertex2f(0*16, (GD.h-1)*16);  GD.Vertex2f((GD.w)*16, (GD.h-1)*16); //inferior
  GD.Vertex2f(0*16, 0*16);  GD.Vertex2f(0*16, (GD.h-1)*16); //izquierda
  GD.Vertex2f((GD.w-1)*16, 0*16);  GD.Vertex2f((GD.w-1)*16, (GD.h-1)*16); //derecha  
 GD.RestoreContext();
 
Parametros();
  
GD.swap();
} 
