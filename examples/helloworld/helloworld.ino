#include <GDXT4X.h>

void setup()
{
  Serial.begin(1000000);
  GD.begin();
}

void loop()
{
  GD.ClearColorRGB(0x500050);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world GDXT4X");
  GD.swap();
}
