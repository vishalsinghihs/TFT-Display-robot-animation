# Quick Start Guide

## What You'll Build

A TFT display that shows 12 animated robot facial expressions:

```
Happy 😊 → Sad 😢 → Surprised 😮 → Angry 😠 → Neutral 😐 → Winking 😉
   ↑                                                              ↓
Thinking 🤔 ← Sick 🤢 ← Love 😍 ← Excited 🤩 ← Confused 😕 ← Sleepy 😴
```

## 5-Minute Setup

### Step 1: Get the Hardware (~ $20)
- Arduino Uno/Nano or ESP32
- ILI9341 TFT Display (240x320)
- 6 jumper wires

### Step 2: Wire It Up
```
Display → Arduino
-----------------
VCC  →  5V
GND  →  GND
CS   →  Pin 10
RST  →  Pin 8
DC   →  Pin 9
MOSI →  Pin 11
SCK  →  Pin 13
```

### Step 3: Install Libraries
In Arduino IDE:
1. **Sketch** → **Include Library** → **Manage Libraries**
2. Search and install:
   - `Adafruit GFX Library`
   - `Adafruit ILI9341`

### Step 4: Upload the Code
1. Open `robot_facial_expressions.ino` in Arduino IDE
2. Select your board: **Tools** → **Board**
3. Select your port: **Tools** → **Port**
4. Click **Upload** (→) button

### Step 5: Enjoy! 🎉
Your robot should now cycle through 12 expressions automatically!

---

## Testing Without Hardware

Want to see it first? Run the Python simulator:

```bash
pip install pygame
python simulator.py
```

Press SPACE to manually cycle through expressions.

---

## Troubleshooting in 30 Seconds

**Nothing on screen?**
→ Check VCC and GND connections first

**Garbled display?**
→ Verify MOSI (Pin 11) and SCK (Pin 13)

**Won't compile?**
→ Install both Adafruit libraries

**Different pins?**
→ Edit lines 16-18 in the .ino file

---

## What's Next?

- 📖 Read [README.md](README.md) for full documentation
- 🔌 Check [HARDWARE.md](HARDWARE.md) for detailed wiring
- 🎨 See [EXPRESSIONS.md](EXPRESSIONS.md) for expression details
- ✏️ Try [examples/custom_expression.ino](examples/custom_expression.ino) to create your own

---

## Need Help?

1. Double-check all 7 wire connections
2. Verify you're using the correct Arduino board in IDE
3. Try a different USB cable/port
4. Check your display is ILI9341 compatible

**Common Questions:**

**Q: Can I use ESP32?**
A: Yes! Change pins to: CS=15, DC=2, RST=4

**Q: How do I change speed?**
A: Edit `delay(3000)` in the code (line 69)

**Q: Can I add more expressions?**
A: Yes! See the custom_expression.ino example

**Q: Will this work on other displays?**
A: Most SPI TFT displays work with minor changes

---

## Features at a Glance

✅ **12 unique facial expressions**
✅ **Automatic animation cycling**
✅ **Easy to customize**
✅ **Low memory footprint**
✅ **Colorful and engaging**
✅ **Well-documented code**
✅ **Extensible design**
✅ **Works with multiple boards**

---

## Share Your Build!

Built this project? We'd love to see it! Add photos or videos to the project issues or discussions.

**Enjoy bringing your robot to life! 🤖✨**
