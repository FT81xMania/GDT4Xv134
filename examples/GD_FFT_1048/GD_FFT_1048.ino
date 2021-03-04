#include <Audio.h>
#include <GDXT4X.h>

//                           GUItool: begin automatically generated code
AudioInputAnalog         adc1;
AudioAnalyzeFFT1024      fft1024; 
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(adc1, 0, i2s1, 0);
AudioConnection          patchCord2(adc1, 0, i2s1, 1);
AudioConnection          patchCord3(adc1, fft1024);
//                            GUItool: end automatically generated code

//Para que no ocurra un conflicto entre SdFat beta y SD, localizar la ruta del binario que genera
//el teensyduino cuando se genera el error, abrir el archivo includes.cache con el editor de texto, y eliminar el llamado a SD.h, 
//Guardar los cambios. En el IDE solo subir el compilado sin verificar. Ya no se producirá el error de conflicto con SD.h

#define NUM_BINS 110 //0-110
int Datos[NUM_BINS];
int oldBarHeights[NUM_BINS];
char floatD[50];
#define TOP      50
long previousMicros0 = 0;
int escala = 7;
float level[16];

int espera = 145;
int LineON = 1;
int CircleON = 0;

Bitmap Background, SaidHello;

void setup() {
  GD.begin();

  Background.fromfile("Fn1.jpg");
  SaidHello.fromtext(26, "FFT values");
  
  analogReadResolution(1);
  AudioMemory(30);
 
  Serial.println("FFT test");
  MP();
}
void loop(){} //nothing to do here!

void MP()
{
 while(1)
 {
  if (fft1024.available()) {
    level[7] =  fft1024.read(23, 32);
    for (int i=0; i < NUM_BINS; i=i+1) {  

      Datos[i] = fft1024.read(i)*1000*escala;
  
     int barHeight = ((oldBarHeights[i] * 1) + Datos[i]) / 2;
     barHeight = ((oldBarHeights[i] * 1) + Datos[i]) / 2;
     
     if (Datos[i] > TOP) Datos[i] = TOP;
      
      Serial.print(Datos[i]);
      Serial.print(" ");

      oldBarHeights[i] = Datos[i];
    }
    Serial.println();
  }

 GD.Clear();
 GD.get_inputs();
 
 GD.SaveContext();
  GD.ColorA(50);
  Background.draw(GD.w / 2, GD.h / 2);
  GD.ColorA(195);
  GD.ColorRGB(0xffffff); SaidHello.draw(7, 250, DEGREES(270));
 GD.RestoreContext();

GD.SaveContext();
  GD.ColorA(100);
  GD.cmd_text(25, 5, 26, 0, "FFT_1024");
  sprintf(floatD,"#bins = %d", NUM_BINS); GD.ColorRGB(0xFFFF00); GD.cmd_text(23, 22, 26, 0, floatD);
  sprintf(floatD,"Teensy 4 @ %d MHz", (F_CPU/1000000)); GD.ColorRGB(0xFFFF00); GD.cmd_text(25, GD.h-25, 26, 0, floatD);
  if(SizeFT813==51){GD.cmd_text(GD.w-320, (GD.h)-25, 26, 0, "EVE chip: 5'' FT813@Riverdi RVT50UQFNWC000");}

  GD.ColorRGB(0xFFFFFF);
  sprintf(floatD,"Dato[0] = %d", Datos[0]);  GD.cmd_text(150, 80, 20, OPT_CENTER, floatD);
  sprintf(floatD,"Dato[1] = %d", Datos[1]);  GD.cmd_text(150, 90, 20, OPT_CENTER, floatD);
  sprintf(floatD,"level[7] = %d", level[7]);  GD.cmd_text(150, 100, 20, OPT_CENTER, floatD);
GD.RestoreContext();

  unsigned long currentMicros0 = millis();
  if(currentMicros0 - previousMicros0 > 16)//350  
  {
   previousMicros0 = currentMicros0;       
    //BarFFT(40, 380, TOP, 23, 6, 8);
    //BarFFT(90, 380, TOP, 8, 4, 6);
    //FillBar(90, 380, TOP, 2, 4, 6);
    //CircleFFTa(90, 380, 8, 4, 6);
    //LineFFT(15, 415, 6, 6, 6);  //64 bins
    
      if (LineON == 1){LineFFT(15+4, 415, 4, 3, 6);}    //110 bins
      if (LineON == 1){LineFFT(15+4, 415, 4, 3, 6);}    //110 bins
      if (CircleON == 1){CircleFFTa(5, 415, 4, 3, 6);}
      if (CircleON == 1){CircleFFTa(5, 415, 4, 3, 6);}
  }
  GD.SaveContext();
   GD.ColorRGB(0xFFFFFF);
   GD.ColorA(195);
   GD.cmd_text(15+4, 419, 20, 0, "80    300     500                      1000    1300   1500                   2000                                            3000                                            4000                                  4800 Hz"); 
  GD.RestoreContext();

  GD.SaveContext();
   GD.cmd_fgcolor(0x000050);    GD.ColorRGB(0xffff00);   
   GD.Tag(1);    GD.cmd_button(GD.w-80, 20, 70, 50, 26, 0,  "FFT line");     GD.Tag(255);
   GD.Tag(2);    GD.cmd_button(GD.w-80, 20+10+50, 70, 50, 26, 0,  "FFT point");    GD.Tag(255);

   if (GD.inputs.tag==1)
   {
     delay(espera);
     LineON = 1;
     CircleON = 0;
   }
   if (GD.inputs.tag==2)
   {
     delay(espera);
     LineON = 0;
     CircleON = 1;
   }   
  GD.RestoreContext();  

  Protector01();
  GD.swap();
 }
}

void LineFFT(int xi, int yi, int largoX, int sepX, int sepY)
{
  GD.SaveContext(); 
   GD.ColorRGB(0xFF0000);
   GD.Begin(LINE_STRIP);
   //GD.LineWidth(1.2 * 16);
   GD.LineWidth(2 * 16);

    GD.Vertex2f((xi) * 16, (yi)* 16);
    for (int j = 2; j < NUM_BINS; j++) 
     {    
        GD.Vertex2f((xi+(largoX/2)+((largoX+sepX)*(j-2))) * 16, ((yi) - (Datos[j]*sepY))* 16);
     }
     GD.Vertex2f((xi+(largoX/2)+(((largoX)*NUM_BINS)+sepX*NUM_BINS)) * 16, (yi)* 16);
  GD.RestoreContext();
}

void BarFFT(int xi, int yi, int segmentos, int largoX, int sepX, int sepY)
{
  GD.SaveContext();  
  GD.ColorA(255);
  GD.Begin(LINES);
  GD.LineWidth(1*16);
  GD.ColorRGB(0xffffff);   //color de los segmentos

    for (int j = 2; j < NUM_BINS; j++) 
      { 
      int dato = map(Datos[j], 0, TOP, 0, segmentos);
      for (int i = 0; i < dato; i++) 
        { 
          GD.Vertex2f((xi+(j*largoX+j*sepX))*16, (yi - (i*sepY))*16); // inicio
          GD.Vertex2f((xi+((j+1)*largoX+j*sepX))*16, (yi - (i*sepY))*16); //  fin   
        }
      }
  GD.RestoreContext();
}

void FillBar(int xi, int yi,  int segmentos, int largoX, int sepX, int sepY)
{
  int SumaX=largoX+sepX;
  GD.SaveContext();  
  GD.ColorA(255);
  GD.Begin(RECTS);
  GD.LineWidth(1*16);
  GD.ColorRGB(0x00ff00);   //color de los segmentos

    for (int j = 2; j < NUM_BINS; j++) 
      { 
        int dato = map(Datos[j], 0, TOP, 0, segmentos);
        for (int i = 0; i < dato; i++) 
        { 
          GD.Vertex2f((xi+((j-0)*SumaX))*16, (yi)*16);  GD.Vertex2f((xi+largoX+((j-0)*SumaX))*16, (yi-(dato*sepY))*16);
        }
      }
  GD.RestoreContext();  
}

void CircleFFTa(int xi, int yi, int largoX, int sepX, int sepY)
{
  GD.SaveContext(); 
   GD.ColorRGB(0xFF0000);
   GD.Begin(POINTS);
   GD.PointSize(4*16);
    for (int j = 2; j < NUM_BINS; j++) 
      { 
        GD.Vertex2f((xi+(largoX/2)+(((largoX)*j)+sepX*j)) * 16, ((yi) - (Datos[j]*sepY))* 16); 
      }
  GD.RestoreContext(); 
}
