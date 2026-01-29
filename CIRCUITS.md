# Circuit Diagrams (ASCII Art)

## Standard Arduino Uno/Nano Setup

```
                    Arduino Uno
                   ┌───────────┐
                   │           │
    TFT Display    │  ┌─────┐  │
   ┌────────────┐  │  │     │  │
   │            │  │  │ USB │  │
   │  ILI9341   │  │  └─────┘  │
   │  240x320   │  │           │
   │            │  │           │
   └────────────┘  └───────────┘
   
Connections:
   
   TFT Display          Arduino Uno
   ┌──────────┐        ┌──────────┐
   │          │        │          │
   │  VCC ────┼───────▶│ 5V       │
   │  GND ────┼───────▶│ GND      │
   │  CS  ────┼───────▶│ D10      │
   │  RESET ──┼───────▶│ D8       │
   │  DC/RS ──┼───────▶│ D9       │
   │  MOSI ───┼───────▶│ D11      │
   │  SCK ────┼───────▶│ D13      │
   │  LED ────┼───────▶│ 3.3V     │
   │  MISO ───┼───────▶│ D12 (opt)│
   │          │        │          │
   └──────────┘        └──────────┘
```

## ESP32 Setup

```
                      ESP32
                   ┌───────────┐
    TFT Display    │   ┌───┐   │
   ┌────────────┐  │   │ U │   │
   │            │  │   │ S │   │
   │  ILI9341   │  │   │ B │   │
   │  240x320   │  │   └───┘   │
   │            │  │           │
   └────────────┘  └───────────┘

Connections:
   
   TFT Display          ESP32
   ┌──────────┐        ┌──────────┐
   │          │        │          │
   │  VCC ────┼───────▶│ 3.3V     │
   │  GND ────┼───────▶│ GND      │
   │  CS  ────┼───────▶│ GPIO 15  │
   │  RESET ──┼───────▶│ GPIO 4   │
   │  DC/RS ──┼───────▶│ GPIO 2   │
   │  MOSI ───┼───────▶│ GPIO 23  │
   │  SCK ────┼───────▶│ GPIO 18  │
   │  LED ────┼───────▶│ 3.3V     │
   │  MISO ───┼───────▶│ GPIO 19  │
   │          │        │          │
   └──────────┘        └──────────┘
```

## Power Distribution Diagram

```
    USB Port (5V)
         │
         ├──────────▶ Arduino VIN
         │
         └──────────▶ TFT VCC (via Arduino 5V pin)


    OR for 3.3V displays:

    USB Port (5V)
         │
         ▼
    ┌──────────┐
    │ Arduino  │
    │ 3.3V Reg │
    └──────────┘
         │
         └──────────▶ TFT VCC (3.3V)
```

## Breadboard Layout (Top View)

```
   Arduino Uno                    Breadboard              TFT Display
   ┌─────────┐                ┌──────────────┐         ┌───────────┐
   │         │                │ + Rail (5V)  │         │           │
   │  5V  ───┼───────────────▶│──────────────┼────────▶│ VCC       │
   │         │                │              │         │           │
   │  GND ───┼───────────────▶│ - Rail (GND) │         │           │
   │         │                │──────────────┼────────▶│ GND       │
   │  D10 ───┼────────────────┼──────────────┼────────▶│ CS        │
   │  D9  ───┼────────────────┼──────────────┼────────▶│ DC        │
   │  D8  ───┼────────────────┼──────────────┼────────▶│ RESET     │
   │  D11 ───┼────────────────┼──────────────┼────────▶│ MOSI      │
   │  D13 ───┼────────────────┼──────────────┼────────▶│ SCK       │
   │         │                │              │         │           │
   └─────────┘                └──────────────┘         └───────────┘
                                                             │
                        ┌────────────────────────────────────┘
                        │
                        ▼
                    LED (Backlight)
                        │
                    [100Ω Resistor]
                        │
                        ▼
                      3.3V
```

## Component Pinout Reference

### ILI9341 TFT Display (Back View)
```
   ┌─────────────────────────────┐
   │  [ ] [ ] [ ] [ ] [ ] [ ]    │
   │   │   │   │   │   │   │     │
   │  VCC GND CS RST DC SDI(MOSI)│
   │                              │
   │  [ ] [ ] [ ]                 │
   │   │   │   │                  │
   │  LED SCK SDO(MISO)           │
   │                              │
   │        ┌───────────┐         │
   │        │           │         │
   │        │  Display  │         │
   │        │   Area    │         │
   │        │           │         │
   │        └───────────┘         │
   └─────────────────────────────┘
```

### Arduino Uno - Digital Pins (Top View)
```
           ┌──────USB───────┐
           │                │
   ┌───────┴────────────────┴────────┐
   │  D13 D12 D11 D10 D9 D8 D7 D6   │
   │  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]│
   │  SCK MISO MOSI CS DC RST        │
   │                                  │
   │  Arduino Uno / Nano              │
   │                                  │
   │                                  │
   └──────────────────────────────────┘
```

## Full System Diagram

```
┌─────────────────────────────────────────────────────────┐
│                                                         │
│   Power Supply (USB or Battery)                         │
│              │                                          │
│              ▼                                          │
│   ┌────────────────────┐                               │
│   │   Arduino Board    │                               │
│   │                    │                               │
│   │  ┌──────────────┐  │                               │
│   │  │ ATmega328P   │  │                               │
│   │  │ Microcontroller│ │      SPI Bus                 │
│   │  └──────────────┘  │  ┌──────────────┐            │
│   │                    │  │              │            │
│   │  D10 (CS)   ───────┼──┼──▶ TFT CS   │            │
│   │  D9  (DC)   ───────┼──┼──▶ TFT DC   │            │
│   │  D8  (RST)  ───────┼──┼──▶ TFT RST  │ ILI9341   │
│   │  D11 (MOSI) ───────┼──┼──▶ TFT MOSI │ Display   │
│   │  D13 (SCK)  ───────┼──┼──▶ TFT SCK  │ 240x320   │
│   │                    │  │              │            │
│   │  5V  ──────────────┼──┼──▶ TFT VCC  │            │
│   │  GND ──────────────┼──┼──▶ TFT GND  │            │
│   │                    │  └──────────────┘            │
│   └────────────────────┘                               │
│                                                         │
│  Displays 12 Robot Facial Expressions                  │
│  Happy → Sad → Surprised → Angry → Neutral → ...      │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

## Signal Flow Diagram

```
   Arduino                SPI Protocol           TFT Display
   ┌──────┐              ┌──────────┐           ┌─────────┐
   │      │              │          │           │         │
   │ CPU  │─┐            │ Data     │           │ Display │
   │      │ │            │ Packets  │           │ Memory  │
   └──────┘ │            └──────────┘           │ Buffer  │
            │                 │                 └─────────┘
            ▼                 ▼                      ▲
   ┌────────────────┐   ┌─────────┐                │
   │ SPI Hardware   │   │ CS (SS) │────────────────┤
   │                │   │ DC      │────────────────┤
   │ • MOSI (Data)  │──▶│ RST     │────────────────┤
   │ • SCK (Clock)  │──▶│ MOSI    │────────────────┤
   │ • CS (Select)  │──▶│ SCK     │────────────────┤
   │                │   └─────────┘                │
   └────────────────┘         │                    │
                              ▼                    │
                        ┌──────────┐               │
                        │ ILI9341  │               │
                        │ Driver   │───────────────┘
                        │ IC       │
                        └──────────┘
                              │
                              ▼
                        ┌──────────┐
                        │  Pixel   │
                        │  Matrix  │
                        │ 240x320  │
                        └──────────┘
```

## Minimal Wiring (4-wire SPI)

If your display supports it, you can use 4-wire mode (no MISO):

```
   Arduino          TFT Display
     D10  ─────────▶  CS
     D9   ─────────▶  DC
     D8   ─────────▶  RESET
     D11  ─────────▶  MOSI
     D13  ─────────▶  SCK
     5V   ─────────▶  VCC
     GND  ─────────▶  GND
     3.3V ─────────▶  LED (via 100Ω resistor)
```

Note: MISO connection is optional for this project since we only write to the display.

---

For more details, see HARDWARE.md
