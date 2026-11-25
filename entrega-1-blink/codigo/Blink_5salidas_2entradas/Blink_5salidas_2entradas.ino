/*
  Blink con cinco salidas y dos entradas - Arduino UNO R3
  Internet de las Cosas - Institución Universitaria Politécnico Grancolombiano
  Autores: Jonatan Felipe Carabalí Victoria, Leidy Vanesa Trujillo Correa,
           Cristian Camilo Díaz Rojas

  Funcionamiento:
  - Cinco LED (pines 12, 11, 10, 9, 8) se encienden uno tras otro (barrido).
  - Pulsador 1 (pin 2): mientras se mantiene presionado, la secuencia se acelera
    (espera de 80 ms en lugar de 250 ms).
  - Pulsador 2 (pin 3): mientras se mantiene presionado, la secuencia se invierte
    (de 8 a 12 en lugar de 12 a 8).
  - En cada paso se envía al Monitor Serie (9600 baudios) una línea CSV:
    tiempo_ms, estado pulsador 1, estado pulsador 2, pin del LED encendido.

  Conexiones:
  - Cada LED: pin digital -> resistencia de 220 ohm -> ánodo del LED; cátodo a GND.
  - Cada pulsador: entre su pin (2 o 3) y GND. Se usa INPUT_PULLUP, por lo que
    la entrada vale HIGH en reposo y LOW al presionar.
*/

int leds[5] = {12, 11, 10, 9, 8};  // pines de los cinco LED (salidas)
int boton1 = 2;                    // pulsador 1: acelera la secuencia
int boton2 = 3;                    // pulsador 2: invierte el sentido

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);       // configura los LED como salidas
  }
  pinMode(boton1, INPUT_PULLUP);    // pulsadores con resistencia pull-up interna
  pinMode(boton2, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("tiempo_ms,B1,B2,LED");  // encabezado del CSV
}

void loop() {
  // Lectura de las entradas (LOW = presionado por el pull-up)
  bool b1 = (digitalRead(boton1) == LOW);
  bool b2 = (digitalRead(boton2) == LOW);
  int espera = b1 ? 80 : 250;       // tiempo que permanece encendido cada LED (ms)

  for (int i = 0; i < 5; i++) {
    int k = b2 ? (4 - i) : i;       // sentido normal o invertido
    digitalWrite(leds[k], HIGH);

    // Registro de la medición en el Monitor Serie
    Serial.print(millis());
    Serial.print(",");
    Serial.print(b1);
    Serial.print(",");
    Serial.print(b2);
    Serial.print(",");
    Serial.println(leds[k]);

    delay(espera);
    digitalWrite(leds[k], LOW);
  }
}
