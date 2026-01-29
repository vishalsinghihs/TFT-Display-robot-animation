/*
 * Robot Facial Expressions for TFT Display
 * 
 * This sketch displays 12 different facial expressions on a TFT display
 * Designed for 240x320 TFT displays (like ILI9341)
 * 
 * Expressions: Happy, Sad, Surprised, Angry, Neutral, Winking, 
 *              Sleepy, Confused, Excited, Love, Sick, Thinking
 */

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// TFT display pins (adjust according to your hardware)
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// Colors
#define BLACK    0x0000
#define WHITE    0xFFFF
#define RED      0xF800
#define GREEN    0x07E0
#define BLUE     0x001F
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define ORANGE   0xFD20

// Screen dimensions
#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

// Face parameters
#define FACE_X      120  // Center X
#define FACE_Y      160  // Center Y
#define EYE_SPACING 40
#define EYE_SIZE    20
#define PUPIL_SIZE  10

int currentExpression = 0;
const int NUM_EXPRESSIONS = 12;
const char* expressionNames[] = {
  "Happy", "Sad", "Surprised", "Angry", 
  "Neutral", "Winking", "Sleepy", "Confused",
  "Excited", "Love", "Sick", "Thinking"
};

void setup() {
  Serial.begin(115200);
  Serial.println("Robot Facial Expressions");
  
  tft.begin();
  tft.setRotation(0);  // Portrait mode
  tft.fillScreen(BLACK);
  
  delay(1000);
}

void loop() {
  displayExpression(currentExpression);
  
  // Display expression name
  tft.setCursor(10, 10);
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(2);
  tft.print(expressionNames[currentExpression]);
  tft.print("   ");  // Clear previous text
  
  delay(3000);  // Hold each expression for 3 seconds
  
  currentExpression = (currentExpression + 1) % NUM_EXPRESSIONS;
}

void clearFace() {
  tft.fillRect(0, 40, SCREEN_WIDTH, SCREEN_HEIGHT - 40, BLACK);
}

void displayExpression(int expr) {
  clearFace();
  
  switch(expr) {
    case 0: drawHappy(); break;
    case 1: drawSad(); break;
    case 2: drawSurprised(); break;
    case 3: drawAngry(); break;
    case 4: drawNeutral(); break;
    case 5: drawWinking(); break;
    case 6: drawSleepy(); break;
    case 7: drawConfused(); break;
    case 8: drawExcited(); break;
    case 9: drawLove(); break;
    case 10: drawSick(); break;
    case 11: drawThinking(); break;
  }
}

// 1. Happy - Smiling with round eyes
void drawHappy() {
  // Eyes
  drawEye(FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE, true);
  drawEye(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, true);
  
  // Smiling mouth (arc)
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 10, 30 + i, WHITE);
  }
  // Cover top half
  tft.fillRect(FACE_X - 35, FACE_Y, 70, 15, BLACK);
}

// 2. Sad - Droopy eyes and frown
void drawSad() {
  // Droopy eyes
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 25, EYE_SIZE - 5, WHITE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 5, WHITE);
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 25, PUPIL_SIZE - 3, BLACK);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 25, PUPIL_SIZE - 3, BLACK);
  
  // Sad eyebrows
  tft.fillTriangle(FACE_X - EYE_SPACING - 15, FACE_Y - 45, 
                   FACE_X - EYE_SPACING + 15, FACE_Y - 50,
                   FACE_X - EYE_SPACING + 15, FACE_Y - 47, CYAN);
  tft.fillTriangle(FACE_X + EYE_SPACING + 15, FACE_Y - 45, 
                   FACE_X + EYE_SPACING - 15, FACE_Y - 50,
                   FACE_X + EYE_SPACING - 15, FACE_Y - 47, CYAN);
  
  // Frown mouth
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 60, 30 + i, WHITE);
  }
  tft.fillRect(FACE_X - 35, FACE_Y + 30, 70, 30, BLACK);
}

// 3. Surprised - Wide open eyes and mouth
void drawSurprised() {
  // Large wide eyes
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE + 5, WHITE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE + 5, WHITE);
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 30, PUPIL_SIZE + 5, BLACK);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 30, PUPIL_SIZE + 5, BLACK);
  
  // Open mouth (circle)
  tft.fillCircle(FACE_X, FACE_Y + 30, 15, WHITE);
  tft.fillCircle(FACE_X, FACE_Y + 30, 12, BLACK);
  tft.fillCircle(FACE_X, FACE_Y + 30, 8, RED);
}

// 4. Angry - Angled eyebrows and straight mouth
void drawAngry() {
  // Eyes
  drawEye(FACE_X - EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, true);
  drawEye(FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, true);
  
  // Angry eyebrows (angled down towards center)
  for(int i = 0; i < 4; i++) {
    tft.drawLine(FACE_X - EYE_SPACING - 20, FACE_Y - 40 - i, 
                 FACE_X - EYE_SPACING + 20, FACE_Y - 50 - i, RED);
    tft.drawLine(FACE_X + EYE_SPACING + 20, FACE_Y - 40 - i, 
                 FACE_X + EYE_SPACING - 20, FACE_Y - 50 - i, RED);
  }
  
  // Straight mouth
  tft.fillRect(FACE_X - 30, FACE_Y + 30, 60, 4, WHITE);
}

// 5. Neutral - Simple face
void drawNeutral() {
  // Eyes
  drawEye(FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE, true);
  drawEye(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, true);
  
  // Neutral mouth (line)
  tft.fillRect(FACE_X - 25, FACE_Y + 30, 50, 3, WHITE);
}

// 6. Winking - One eye closed
void drawWinking() {
  // Left eye winking (line)
  for(int i = 0; i < 3; i++) {
    tft.drawLine(FACE_X - EYE_SPACING - 15, FACE_Y - 28 + i, 
                 FACE_X - EYE_SPACING + 15, FACE_Y - 28 + i, YELLOW);
  }
  
  // Right eye open
  drawEye(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, true);
  
  // Playful smile
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 10, 25 + i, YELLOW);
  }
  tft.fillRect(FACE_X - 30, FACE_Y, 60, 15, BLACK);
}

// 7. Sleepy - Half closed eyes
void drawSleepy() {
  // Sleepy eyes (half circles)
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 28, EYE_SIZE - 5, WHITE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 28, EYE_SIZE - 5, WHITE);
  tft.fillRect(FACE_X - EYE_SPACING - 20, FACE_Y - 40, 40, 15, BLACK);
  tft.fillRect(FACE_X + EYE_SPACING - 20, FACE_Y - 40, 40, 15, BLACK);
  
  // Add "ZZZ"
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.setCursor(FACE_X + 50, FACE_Y - 60);
  tft.print("Z");
  tft.setCursor(FACE_X + 60, FACE_Y - 70);
  tft.setTextSize(1);
  tft.print("Z");
  tft.setCursor(FACE_X + 65, FACE_Y - 75);
  tft.print("z");
  
  // Small smile
  for(int i = 0; i < 2; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 15, 20 + i, WHITE);
  }
  tft.fillRect(FACE_X - 25, FACE_Y + 5, 50, 15, BLACK);
}

// 8. Confused - Asymmetric eyes and wavy mouth
void drawConfused() {
  // One eye higher than the other
  drawEye(FACE_X - EYE_SPACING, FACE_Y - 35, EYE_SIZE - 3, true);
  drawEye(FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, true);
  
  // Confused eyebrow
  for(int i = 0; i < 3; i++) {
    tft.drawLine(FACE_X - EYE_SPACING - 15, FACE_Y - 50 + i, 
                 FACE_X - EYE_SPACING + 15, FACE_Y - 45 + i, YELLOW);
  }
  
  // Wavy mouth
  for(int x = -20; x <= 20; x += 2) {
    int y = FACE_Y + 30 + sin(x * 0.3) * 5;
    tft.fillRect(FACE_X + x, y, 2, 2, WHITE);
  }
}

// 9. Excited - Wide eyes with sparkles
void drawExcited() {
  // Big shiny eyes
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE, YELLOW);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, YELLOW);
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 30, PUPIL_SIZE, BLACK);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 30, PUPIL_SIZE, BLACK);
  
  // Sparkles
  tft.fillRect(FACE_X - EYE_SPACING - 5, FACE_Y - 35, 3, 8, WHITE);
  tft.fillRect(FACE_X - EYE_SPACING - 9, FACE_Y - 31, 8, 3, WHITE);
  tft.fillRect(FACE_X + EYE_SPACING - 5, FACE_Y - 35, 3, 8, WHITE);
  tft.fillRect(FACE_X + EYE_SPACING - 9, FACE_Y - 31, 8, 3, WHITE);
  
  // Big smile
  for(int i = 0; i < 4; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 15, 35 + i, YELLOW);
  }
  tft.fillRect(FACE_X - 40, FACE_Y + 5, 80, 15, BLACK);
}

// 10. Love - Heart eyes
void drawLove() {
  // Heart eyes (left)
  drawHeart(FACE_X - EYE_SPACING, FACE_Y - 28, 12, MAGENTA);
  // Heart eyes (right)
  drawHeart(FACE_X + EYE_SPACING, FACE_Y - 28, 12, MAGENTA);
  
  // Smile
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 15, 28 + i, MAGENTA);
  }
  tft.fillRect(FACE_X - 33, FACE_Y + 5, 66, 15, BLACK);
}

// 11. Sick - X eyes and wavy mouth
void drawSick() {
  // X eyes
  for(int i = 0; i < 3; i++) {
    // Left eye
    tft.drawLine(FACE_X - EYE_SPACING - 10, FACE_Y - 35 + i, 
                 FACE_X - EYE_SPACING + 10, FACE_Y - 15 + i, GREEN);
    tft.drawLine(FACE_X - EYE_SPACING + 10, FACE_Y - 35 + i, 
                 FACE_X - EYE_SPACING - 10, FACE_Y - 15 + i, GREEN);
    // Right eye
    tft.drawLine(FACE_X + EYE_SPACING - 10, FACE_Y - 35 + i, 
                 FACE_X + EYE_SPACING + 10, FACE_Y - 15 + i, GREEN);
    tft.drawLine(FACE_X + EYE_SPACING + 10, FACE_Y - 35 + i, 
                 FACE_X + EYE_SPACING - 10, FACE_Y - 15 + i, GREEN);
  }
  
  // Sick mouth (wavy down)
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 60, 25 + i, GREEN);
  }
  tft.fillRect(FACE_X - 30, FACE_Y + 30, 60, 30, BLACK);
}

// 12. Thinking - Eyes looking up, hand to chin
void drawThinking() {
  // Eyes looking up
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE - 3, WHITE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE - 3, WHITE);
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 36, PUPIL_SIZE - 3, BLACK);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 36, PUPIL_SIZE - 3, BLACK);
  
  // Thinking mouth (small line)
  tft.fillRect(FACE_X - 15, FACE_Y + 25, 30, 2, WHITE);
  
  // Thought bubble
  tft.drawCircle(FACE_X + 50, FACE_Y - 70, 20, CYAN);
  tft.drawCircle(FACE_X + 50, FACE_Y - 70, 21, CYAN);
  tft.fillCircle(FACE_X + 35, FACE_Y - 50, 5, CYAN);
  tft.fillCircle(FACE_X + 25, FACE_Y - 40, 3, CYAN);
}

// Helper function to draw an eye
void drawEye(int x, int y, int size, bool withPupil) {
  tft.fillCircle(x, y, size, WHITE);
  if (withPupil) {
    tft.fillCircle(x, y, size - 10, BLACK);
  }
}

// Helper function to draw a heart
void drawHeart(int x, int y, int size, uint16_t color) {
  // Two circles for top of heart
  tft.fillCircle(x - size/2, y - size/3, size/2, color);
  tft.fillCircle(x + size/2, y - size/3, size/2, color);
  
  // Triangle for bottom of heart
  tft.fillTriangle(x - size, y - size/3, 
                   x + size, y - size/3, 
                   x, y + size, color);
}
