// NOM DU PROGRAMME : OLED_PROTOTYPE
// REALISATION INFORMATIQUE : Mathieu Lepage
// DATE DE CREATION : 2020/10/16
// OBJET : Programme test permettant d'afficher un simple message sur l'écran OLED

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_SPIDevice.h>

//Définir l'écran à 128x64
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  // Fonction permettant d'effacer l'affichage de l'initiation de l'écran
  display.clearDisplay();
  // Fonction permetant d'ajuster la taille de la police d'écriture
  display.setTextSize(1);
  // Fonction permettant d'ajuster la couleur du texte
  display.setTextColor(WHITE);
  // Positionnement du curseur de texte
  display.setCursor(0, 5);
  // Affichage d'un texte statique
  display.println("Voici un test OLED");
  display.setCursor(0, 35);
  // Affichage d'un texte statique
  display.println("Coucou GitHub!");
  // Fonction permetant d'afficher le contenu enregistré dans la RAM sur l'écran SSD1306
  display.display(); 
}

void loop() {
}