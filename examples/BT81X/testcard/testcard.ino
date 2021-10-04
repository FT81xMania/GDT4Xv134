#include <GDT4Xv134.h>

void setup() {
  GD.begin();
}

void loop() 
{
  GD.Clear();
  GD.cmd_testcard();
}
