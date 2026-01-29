# TFT Display Robot Animation - 12 Facial Expressions

A fun Arduino project that displays 12 different robot facial expressions on a TFT display. Perfect for robotics projects, interactive displays, or learning about graphics programming.

## Features

This project implements **12 distinct facial expressions**:

1. **Happy** 😊 - Smiling face with round eyes
2. **Sad** 😢 - Droopy eyes with a frown
3. **Surprised** 😮 - Wide open eyes and mouth
4. **Angry** 😠 - Angled eyebrows with stern look
5. **Neutral** 😐 - Simple, calm expression
6. **Winking** 😉 - One eye closed, playful smile
7. **Sleepy** 😴 - Half-closed eyes with "ZZZ"
8. **Confused** 😕 - Asymmetric eyes, wavy mouth
9. **Excited** 🤩 - Wide eyes with sparkles
10. **Love** 😍 - Heart-shaped eyes
11. **Sick** 🤢 - X eyes with greenish tint
12. **Thinking** 🤔 - Eyes looking up with thought bubble

## Hardware Requirements

- **Arduino Board** (Uno, Mega, Nano, ESP32, etc.)
- **TFT Display** - ILI9341 (240x320 pixels) or compatible
- **Connecting Wires**
- **Breadboard** (optional)

## Wiring Diagram

### For Arduino Uno/Nano with ILI9341 TFT Display:

```
TFT Display Pin  →  Arduino Pin
--------------------------------
VCC             →  5V
GND             →  GND
CS              →  Pin 10
RESET           →  Pin 8
DC/RS           →  Pin 9
SDI(MOSI)       →  Pin 11 (MOSI)
SCK             →  Pin 13 (SCK)
LED             →  3.3V (or 5V with resistor)
SDO(MISO)       →  Pin 12 (MISO) [optional]
```

### For ESP32 with ILI9341 TFT Display:

```
TFT Display Pin  →  ESP32 Pin
--------------------------------
VCC             →  3.3V
GND             →  GND
CS              →  GPIO 15
RESET           →  GPIO 4
DC/RS           →  GPIO 2
SDI(MOSI)       →  GPIO 23 (MOSI)
SCK             →  GPIO 18 (SCK)
LED             →  3.3V
SDO(MISO)       →  GPIO 19 (MISO) [optional]
```

**Note:** Adjust the pin definitions in the code if you use different pins.

## Software Requirements

### Libraries

Install these libraries via Arduino IDE Library Manager:

1. **Adafruit GFX Library** - Graphics core library
2. **Adafruit ILI9341** - Display driver

#### Installation Steps:

1. Open Arduino IDE
2. Go to `Sketch` → `Include Library` → `Manage Libraries`
3. Search for "Adafruit GFX" and click Install
4. Search for "Adafruit ILI9341" and click Install

## Installation & Usage

1. **Clone or Download** this repository
2. **Connect** your TFT display to Arduino according to the wiring diagram
3. **Open** `robot_facial_expressions.ino` in Arduino IDE
4. **Configure Pins** (if needed):
   ```cpp
   #define TFT_CS   10  // Chip Select
   #define TFT_DC   9   // Data/Command
   #define TFT_RST  8   // Reset
   ```
5. **Select** your board and port in Arduino IDE
6. **Upload** the sketch
7. **Watch** the robot cycle through all 12 expressions!

## How It Works

- The sketch automatically cycles through all 12 facial expressions
- Each expression is displayed for 3 seconds
- The expression name appears at the top of the screen
- After the last expression, it loops back to the first

## Customization

### Modify Display Duration

Change the delay in the `loop()` function:
```cpp
delay(3000);  // Change to desired milliseconds
```

### Change Expression Order

Modify the switch statement in `displayExpression()` function.

### Adjust Colors

Colors are defined at the top of the sketch:
```cpp
#define BLACK    0x0000
#define WHITE    0xFFFF
#define RED      0xF800
// ... etc
```

### Screen Orientation

Change the rotation in `setup()`:
```cpp
tft.setRotation(0);  // 0, 1, 2, or 3
```

## Code Structure

- `setup()` - Initializes the TFT display
- `loop()` - Cycles through expressions
- `displayExpression()` - Routes to specific expression function
- `drawHappy()`, `drawSad()`, etc. - Individual expression drawing functions
- `drawEye()`, `drawHeart()` - Helper functions for common shapes

## Troubleshooting

### Display shows nothing:
- Check wiring connections
- Verify power supply (some displays need 5V, others 3.3V)
- Check pin definitions match your wiring

### Display shows garbled graphics:
- Try different SPI speeds
- Check MOSI and SCK connections
- Verify display is ILI9341 compatible

### Compilation errors:
- Ensure all required libraries are installed
- Check Arduino IDE board selection
- Verify you have the latest library versions

## Technical Details

- **Display Resolution:** 240x320 pixels
- **Color Depth:** 16-bit (65,536 colors)
- **Interface:** SPI
- **Memory Usage:** Optimized for Arduino Uno (32KB flash)

## Contributing

Feel free to contribute by:
- Adding more facial expressions
- Improving animations
- Adding sensor integration (e.g., expressions based on distance sensor)
- Supporting other display types

## License

This project is open source. Feel free to use and modify for your projects!

## Credits

Created for learning and fun robotics projects using Arduino and TFT displays.

## Future Enhancements

Potential additions:
- [ ] Add smooth transitions between expressions
- [ ] Interactive mode with buttons to select expressions
- [ ] Sensor integration (react to proximity, sound, etc.)
- [ ] Animation sequences (blinking, moving eyes)
- [ ] Save custom expressions to EEPROM
- [ ] Support for different display sizes

---

**Enjoy bringing your robot to life with expressions! 🤖**