/*
  Emisor (Arduino 1) - Emulación del dispositivo que envía comandos por Bluetooth
  Internet de las Cosas - Entrega 2 - Politécnico Grancolombiano

  Tinkercad Circuits no incluye el módulo Bluetooth HC-05. Como el HC-05 se
  comporta como un puente serial, el enlace se emula con SoftwareSerial entre
  dos Arduino UNO: este Arduino hace el papel del teléfono/computador.

  Conexiones (cruzadas con el Arduino 2):
    pin 3 (TX) -> pin 2 (RX) del receptor
    pin 2 (RX) <- pin 3 (TX) del receptor
    GND        -  GND del receptor

  Uso: escribir 1, 0, 2 o 3 en el Monitor Serie (9600 baudios).
    1 = LED verde ON   0 = LED verde OFF   2 = LED rojo ON   3 = LED rojo OFF

  Salida (CSV): n,tiempo_ms,comando,latencia_ms,respuesta
    latencia_ms = tiempo desde el envío del comando hasta recibir la
                  confirmación 'K' del receptor.
*/

#include <SoftwareSerial.h>

SoftwareSerial enlace(2, 3);   // RX, TX del enlace emulado
unsigned long tEnvio = 0;      // instante en que se envió el último comando
bool esperando = false;        // true mientras se espera la confirmación
char ultimo = 0;               // último comando enviado
int enviados = 0;              // contador de comandos

void setup() {
  Serial.begin(9600);          // Monitor Serie
  enlace.begin(4800);          // a 9600 la confirmación llegaba alterada
  Serial.println("Emisor listo. Escribe 1, 0, 2 o 3");
  Serial.println("n,tiempo_ms,comando,latencia_ms,respuesta");
}

void loop() {
  // 1) Enviar un comando escrito en el Monitor Serie
  if (!esperando && Serial.available()) {
    char c = Serial.read();
    if (c == '0' || c == '1' || c == '2' || c == '3') {
      enlace.write(c);
      ultimo = c;
      tEnvio = millis();       // se toma después de transmitir el byte
      esperando = true;
      enviados++;
    }
  }

  // 2) Esperar la confirmación del receptor (no se imprime nada mientras
  //    tanto, porque SoftwareSerial se descuadra si se imprime y recibe a la vez)
  if (esperando && enlace.available()) {
    char r = enlace.read();
    unsigned long latencia = millis() - tEnvio;
    Serial.print(enviados); Serial.print(",");
    Serial.print(tEnvio);   Serial.print(",");
    Serial.print(ultimo);   Serial.print(",");
    Serial.print(latencia); Serial.print(",");
    Serial.println(r == 'K' ? "OK" : "ERROR");
    esperando = false;
  }

  // 3) Si no hay respuesta en 1 s, el comando se registra como perdido
  if (esperando && millis() - tEnvio > 1000) {
    Serial.print(enviados); Serial.print(",");
    Serial.print(tEnvio);   Serial.print(",");
    Serial.print(ultimo);
    Serial.println(",-1,SIN_RESPUESTA");
    esperando = false;
  }
}
