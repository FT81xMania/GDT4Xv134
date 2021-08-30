#include <GDT4Xv134.h>

void setup()
{
  GD.begin();
}

void loop()
{
  GD.ClearColorRGB(0xf44611);
  GD.Clear();
  GD.ColorRGB(0x0000ff);
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
} 
