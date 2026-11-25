/*
  Receptor (Arduino 2) - Placa que recibe los comandos "por Bluetooth"
  Internet de las Cosas - Entrega 2 - Politécnico Grancolombiano

  Este Arduino ocupa el lugar de la placa conectada al módulo HC-05. Recibe un
  carácter por el enlace emulado (SoftwareSerial), enciende o apaga el LED
  correspondiente y responde con 'K' como confirmación (ACK).

  Conexiones:
    pin 2 (RX) <- pin 3 (TX) del emisor
    pin 3 (TX) -> pin 2 (RX) del emisor
    pin 8 -> resistencia 220 ohm -> LED verde -> GND
    pin 9 -> resistencia 220 ohm -> LED rojo  -> GND

  Comandos: 1 = verde ON, 0 = verde OFF, 2 = rojo ON, 3 = rojo OFF

  Salida (CSV): n,tiempo_ms,comando,accion
*/

#include <SoftwareSerial.h>

SoftwareSerial enlace(2, 3);   // RX, TX del enlace emulado
int verde = 8;                 // LED verde
int rojo = 9;                  // LED rojo
int recibidos = 0;             // contador de comandos recibidos

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
  Serial.begin(9600);          // Monitor Serie
  enlace.begin(4800);          // misma velocidad que el emisor
  Serial.println("Receptor listo");
  Serial.println("n,tiempo_ms,comando,accion");
}

void loop() {
  if (enlace.available()) {
    char c = enlace.read();

    // Ejecutar el comando recibido
    String accion = "DESCONOCIDO";
    if (c == '1') { digitalWrite(verde, HIGH); accion = "VERDE_ON"; }
    if (c == '0') { digitalWrite(verde, LOW);  accion = "VERDE_OFF"; }
    if (c == '2') { digitalWrite(rojo, HIGH);  accion = "ROJO_ON"; }
    if (c == '3') { digitalWrite(rojo, LOW);   accion = "ROJO_OFF"; }

    // Registrar el evento en el Monitor Serie
    recibidos++;
    Serial.print(recibidos); Serial.print(",");
    Serial.print(millis());  Serial.print(",");
    Serial.print(c);         Serial.print(",");
    Serial.println(accion);

    delay(10);                 // pausa antes de confirmar
    enlace.write('K');         // confirmación (ACK)
  }
}
