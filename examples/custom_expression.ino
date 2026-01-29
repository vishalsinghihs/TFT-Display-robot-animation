/*
 * Custom Expression Example
 * 
 * This example shows how to create your own custom facial expression
 * Copy this template and modify to create new expressions
 */

// Example: Create a "Crying" expression
void drawCrying() {
  // Sad eyes
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 25, EYE_SIZE - 5, WHITE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 5, WHITE);
  tft.fillCircle(FACE_X - EYE_SPACING, FACE_Y - 25, PUPIL_SIZE - 3, BLUE);
  tft.fillCircle(FACE_X + EYE_SPACING, FACE_Y - 25, PUPIL_SIZE - 3, BLUE);
  
  // Tears (blue drops)
  for(int i = 0; i < 3; i++) {
    // Left tear
    tft.fillCircle(FACE_X - EYE_SPACING - 10, FACE_Y - 10 + (i * 12), 3, CYAN);
    // Right tear
    tft.fillCircle(FACE_X + EYE_SPACING + 10, FACE_Y - 10 + (i * 12), 3, CYAN);
  }
  
  // Open crying mouth
  for(int i = 0; i < 3; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 60, 20 + i, WHITE);
  }
  tft.fillRect(FACE_X - 25, FACE_Y + 30, 50, 30, BLACK);
}

// Example: Create a "Cool" expression (with sunglasses)
void drawCool() {
  // Sunglasses (rectangles)
  tft.fillRect(FACE_X - EYE_SPACING - 20, FACE_Y - 35, 40, 15, BLACK);
  tft.drawRect(FACE_X - EYE_SPACING - 20, FACE_Y - 35, 40, 15, WHITE);
  
  tft.fillRect(FACE_X + EYE_SPACING - 20, FACE_Y - 35, 40, 15, BLACK);
  tft.drawRect(FACE_X + EYE_SPACING - 20, FACE_Y - 35, 40, 15, WHITE);
  
  // Bridge
  for(int i = 0; i < 3; i++) {
    tft.drawLine(FACE_X - EYE_SPACING + 20, FACE_Y - 28 + i,
                 FACE_X + EYE_SPACING - 20, FACE_Y - 28 + i, WHITE);
  }
  
  // Cool smile
  for(int i = 0; i < 2; i++) {
    tft.drawCircle(FACE_X, FACE_Y + 20, 25 + i, WHITE);
  }
  tft.fillRect(FACE_X - 30, FACE_Y + 10, 60, 15, BLACK);
}

// Example: Create a "Dizzy" expression
void drawDizzy() {
  // Spiral eyes
  for(int angle = 0; angle < 360; angle += 20) {
    float rad = angle * 3.14159 / 180.0;
    int radius = 5 + (angle / 60);
    int x1 = FACE_X - EYE_SPACING + cos(rad) * radius;
    int y1 = FACE_Y - 30 + sin(rad) * radius;
    tft.fillCircle(x1, y1, 2, YELLOW);
    
    int x2 = FACE_X + EYE_SPACING + cos(rad) * radius;
    int y2 = FACE_Y - 30 + sin(rad) * radius;
    tft.fillCircle(x2, y2, 2, YELLOW);
  }
  
  // Wavy dizzy mouth
  for(int x = -25; x <= 25; x += 2) {
    int y = FACE_Y + 30 + sin(x * 0.4) * 8;
    tft.fillRect(FACE_X + x, y, 2, 2, YELLOW);
  }
  
  // Stars around head
  tft.setCursor(FACE_X - 60, FACE_Y - 60);
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.print("*");
  tft.setCursor(FACE_X + 50, FACE_Y - 60);
  tft.print("*");
}

/*
 * To add your custom expression to the main sketch:
 * 
 * 1. Copy your function to robot_facial_expressions.ino
 * 2. Increase NUM_EXPRESSIONS constant
 * 3. Add the name to expressionNames array
 * 4. Add a case in the displayExpression() switch statement
 * 
 * Example:
 *   const int NUM_EXPRESSIONS = 13;  // was 12
 *   const char* expressionNames[] = {
 *     ..., "Crying"  // Add your expression name
 *   };
 *   
 *   In displayExpression():
 *     case 12: drawCrying(); break;
 */
