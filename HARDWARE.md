# Hardware Configuration Guide

## Supported Displays

This project is designed for ILI9341-based TFT displays but can be adapted for other displays.

### ILI9341 (240x320) - Recommended
- **Resolution:** 240x320 pixels
- **Interface:** SPI
- **Voltage:** 3.3V - 5V (depends on model)
- **Colors:** 16-bit (65K colors)

### Other Compatible Displays
With minor modifications, you can use:
- ST7735 (128x160) - Adjust SCREEN_WIDTH and SCREEN_HEIGHT
- ILI9488 (320x480) - Larger display, scale up drawings
- ST7789 (240x240) - Square display

## Pin Configuration

### Default Pins (Arduino Uno/Nano)
```cpp
#define TFT_CS   10  // Chip Select
#define TFT_DC   9   // Data/Command
#define TFT_RST  8   // Reset
// MOSI -> Pin 11
// SCK  -> Pin 13
// MISO -> Pin 12 (optional)
```

### ESP32 Configuration
```cpp
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
// MOSI -> GPIO 23
// SCK  -> GPIO 18
// MISO -> GPIO 19 (optional)
```

### ESP8266 Configuration
```cpp
#define TFT_CS   15  // D8
#define TFT_DC   4   // D2
#define TFT_RST  5   // D1
// MOSI -> GPIO 13 (D7)
// SCK  -> GPIO 14 (D5)
// MISO -> GPIO 12 (D6)
```

### Arduino Mega Configuration
```cpp
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8
// MOSI -> Pin 51
// SCK  -> Pin 52
// MISO -> Pin 50
```

## Power Requirements

### Current Draw
- **Typical:** 50-150mA (varies with brightness and content)
- **Maximum:** 200mA

### Power Supply Options

1. **USB Power** (5V)
   - Most Arduino boards provide 5V via USB
   - Suitable for development and testing
   
2. **Battery Power**
   - 3.7V LiPo battery (with voltage regulator)
   - 4x AA batteries (6V with regulator to 5V)
   - 9V battery (with Arduino's voltage regulator)

3. **External Adapter**
   - 5V 1A adapter recommended
   - Ensure stable power supply

## Display Voltage Levels

⚠️ **IMPORTANT:** Check your display's voltage requirements!

### 3.3V Displays
Some TFT displays are 3.3V only. If using with 5V Arduino:
- Use level shifters on data pins
- Or use 3.3V Arduino (like Arduino Due)

### 5V Tolerant Displays
Many ILI9341 modules have built-in level shifters and can work with 5V logic.

## Wiring Tips

1. **Use Short Wires:** Keep wires under 10cm for reliable SPI communication
2. **Quality Connections:** Use good quality jumper wires or solder connections
3. **Capacitor:** Add a 10µF capacitor between VCC and GND near the display
4. **Backlight:** Connect LED pin to 3.3V through a 100Ω resistor

## Common Wiring Issues

### Issue: Display shows nothing
- Check VCC and GND connections
- Verify CS, DC, and RST pins match your code
- Ensure power supply can provide enough current

### Issue: Garbled display
- Check MOSI and SCK connections
- Reduce wire length
- Try lower SPI speed (comment out in library)

### Issue: Dim or no backlight
- Connect LED pin to power
- Use appropriate resistor (100-330Ω)
- Some displays have backlight control pin

## Testing Your Setup

### Step 1: Verify Connections
Use a multimeter to check:
- Continuity between Arduino GND and Display GND
- Voltage at display VCC (should be 3.3V or 5V)

### Step 2: Run Test Sketch
Before using the facial expressions sketch, test with this simple code:

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(50, 100);
  tft.println("Display OK!");
}

void loop() {
  // Nothing
}
```

If this works, your hardware is correctly set up!

## Performance Optimization

### SPI Speed
For faster drawing, you can modify the SPI speed in the library initialization:
```cpp
// In Adafruit_ILI9341.cpp, look for SPI.setClockDivider()
// Lower divider = faster speed
```

### Memory Considerations
- Arduino Uno: 32KB Flash, 2KB RAM (limited)
- Arduino Mega: 256KB Flash, 8KB RAM (plenty)
- ESP32: Much more memory, faster processor

## Troubleshooting Hardware

| Symptom | Possible Cause | Solution |
|---------|---------------|----------|
| Blank white screen | Wrong reset or DC pin | Check pin definitions |
| All black | Backlight issue | Check LED pin connection |
| Random pixels | Poor connection | Re-seat wires, check solder |
| Works then stops | Power issue | Use external power supply |
| Colors wrong | Library mismatch | Try different driver library |

## Shopping List

To build this project, you'll need:

- [ ] Arduino Uno/Nano/Mega or ESP32 (~ $5-15)
- [ ] ILI9341 TFT Display 240x320 (~ $8-15)
- [ ] Jumper wires or breadboard kit (~ $3-5)
- [ ] USB cable for programming (~ $3)
- [ ] Optional: Enclosure/case (~ $5-10)
- [ ] Optional: Buttons for interaction (~ $2)

**Total Cost:** $20-50 depending on components chosen

## Next Steps

Once your hardware is set up:
1. Upload the robot_facial_expressions.ino sketch
2. Watch your robot come to life!
3. Customize expressions to match your project
4. Add sensors for interactive responses

---

For more help, consult:
- Adafruit GFX Library documentation
- Arduino SPI documentation
- Your specific display's datasheet
