# Internet de las Cosas – Proyecto con Arduino

**Institución Universitaria Politécnico Grancolombiano – Ingeniería de Software**
Materia: Internet de las Cosas · Profesor: Jesús Figueroa Guerrero · 2026

**Integrantes**
- Jonatan Felipe Carabalí Victoria
- Leidy Vanesa Trujillo Correa
- Cristian Camilo Díaz Rojas
- Jhoan Pulido Castaño

Este repositorio reúne el proyecto completo del curso: el código fuente documentado, los enlaces a las simulaciones en Tinkercad Circuits, los archivos de las mediciones experimentales, las capturas de los recursos del sistema operativo y los artículos en formato IEEE de cada entrega.

---

## Entregas

| Entrega | Tema | Simulación en Tinkercad | Carpeta |
|---|---|---|---|
| 1 – Semana 3 | Blink con cinco salidas y dos entradas | [Abrir en Tinkercad](https://www.tinkercad.com/things/cbYBSOzz8i9-entrega-internet-de-las-cosas?sharecode=Mycaf2Bx0_Yeii9l4UDihEZ-cH-o2BNq5Om33Pkl-3I) | [`entrega-1-blink`](entrega-1-blink) |
| 2 – Semana 5 | Emulación de un enlace Bluetooth (HC-05) entre dos Arduino UNO | [Abrir en Tinkercad](https://www.tinkercad.com/things/635zr0pWGUh-entrega-2?sharecode=XhJBw0Ih7xSG-tpHKMKaIMD3OPxAG4WwV8C1qhgxH8E) | [`entrega-2-bluetooth`](entrega-2-bluetooth) |

## Estructura

```
IoT-Arduino-Poligran/
├── README.md
├── entrega-1-blink/
│   ├── README.md
│   ├── articulo/                     Artículo IEEE (PDF)
│   ├── codigo/Blink_5salidas_2entradas/
│   ├── datos/                        Mediciones (CSV)
│   ├── imagenes/                     Circuito y gráficas
│   └── recursos-sistema-operativo/   Capturas del Administrador de tareas
└── entrega-2-bluetooth/
    ├── README.md
    ├── articulo/
    ├── codigo/emisor/  codigo/receptor/
    ├── datos/
    ├── imagenes/
    └── recursos-sistema-operativo/
```

## Cómo ejecutar las simulaciones

1. Abrir el enlace de Tinkercad de la entrega y pulsar **Iniciar simulación**.
2. Abrir el **Monitor Serie** (parte inferior del editor de código) para ver los datos que imprime cada Arduino.
3. Para usar una placa física: abrir el archivo `.ino` en el Arduino IDE, elegir la placa **Arduino UNO**, cargar el programa y abrir el Monitor Serie a **9600 baudios**.

## Herramientas

- Tinkercad Circuits (Autodesk) – simulación del circuito y del Arduino UNO R3.
- Arduino (C/C++) – programación de los microcontroladores.
- Administrador de tareas de Windows 11 – medición de los recursos del computador.
