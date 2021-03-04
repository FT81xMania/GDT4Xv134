int XProtector=0, velXProtector=1, color;
void Protector01()
{
 XProtector=XProtector+velXProtector;
 if(XProtector>=GD.w)
   {
    velXProtector=-1; 
    color = color + 1;
    if (color>=3){color=0;}
   }
 if(XProtector<=0)
   {
    velXProtector=1;
    color = color + 1;
    if (color>=3){color=0;}
   }
 GD.SaveContext();
   if (color==0)
    {
     GD.ColorRGB(0xff0000);
    }
   if (color==1)
    {
     GD.ColorRGB(0x00ff00);
    }
   if (color==2)
    {
     GD.ColorRGB(0x0000ff);
    }
   //sprintf(TXP,"color = %d", color); GD.cmd_text(GD.w-41, 5, 20, 0, TXP);    
   GD.LineWidth(1.5 * 16);
   GD.Begin(LINES);
   GD.Vertex2f((XProtector)*16,(0)*16);  GD.Vertex2f((XProtector)*16,(GD.h)*16);
 GD.RestoreContext();
}
