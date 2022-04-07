#include <Arduino.h>
#include <NeoPixelBus.h>

#define NUM_PIXELS 64
#define PIXEL_PIN 4
#define X_AXIS 34
#define Y_AXIS 35
#define SAMPLES 100

int acum_x = 0;
int acum_y = 0;
int contador_x = 0;
int contador_y = 0;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> miMatriz(NUM_PIXELS, PIXEL_PIN);

RgbColor red(128, 0, 0);
RgbColor black(0, 0, 0);

void promedio_eje_x();
void promedio_eje_y();

void setup() {
  Serial.begin(9600);
  miMatriz.Begin();
  miMatriz.Show();
}

void loop() {
  miMatriz.SetPixelColor(0, red); miMatriz.Show();
  promedio_eje_x();  
  promedio_eje_y();
}

void promedio_eje_x() {
  int valor_x = analogRead(X_AXIS);
  acum_x = acum_x + valor_x;
  contador_x++;
  if (contador_x == SAMPLES) {
    int total_x = acum_x / SAMPLES;
    
    Serial.println("Eje x: " + String(total_x));
    contador_x = 0;
    acum_x = 0;
  }
}

void promedio_eje_y() {

}