"""
Robot Facial Expression Simulator
A Python visualization of the robot expressions for testing without hardware

Requirements:
pip install pygame

Usage:
python simulator.py
"""

try:
    import pygame
    import math
    import time
except ImportError:
    print("Error: pygame is required. Install with: pip install pygame")
    exit(1)

# Initialize Pygame
pygame.init()

# Screen settings
SCREEN_WIDTH = 240
SCREEN_HEIGHT = 320
SCALE = 2  # Scale up for better visibility
screen = pygame.display.set_mode((SCREEN_WIDTH * SCALE, SCREEN_HEIGHT * SCALE))
pygame.display.set_caption("Robot Face Simulator")

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)
YELLOW = (255, 255, 0)
ORANGE = (255, 165, 0)

# Face parameters
FACE_X = SCREEN_WIDTH // 2
FACE_Y = SCREEN_HEIGHT // 2
EYE_SPACING = 40
EYE_SIZE = 20
PUPIL_SIZE = 10

# Expression names
EXPRESSION_NAMES = [
    "Happy", "Sad", "Surprised", "Angry",
    "Neutral", "Winking", "Sleepy", "Confused",
    "Excited", "Love", "Sick", "Thinking"
]

def scale_coord(x, y):
    """Scale coordinates for display"""
    return int(x * SCALE), int(y * SCALE)

def scale_size(size):
    """Scale size for display"""
    return int(size * SCALE)

def draw_circle(surface, color, center, radius, width=0):
    """Draw scaled circle"""
    pygame.draw.circle(surface, color, scale_coord(*center), scale_size(radius), scale_size(width))

def draw_rect(surface, color, rect):
    """Draw scaled rectangle"""
    x, y, w, h = rect
    scaled_rect = pygame.Rect(x * SCALE, y * SCALE, w * SCALE, h * SCALE)
    pygame.draw.rect(surface, color, scaled_rect)

def draw_line(surface, color, start, end, width=1):
    """Draw scaled line"""
    pygame.draw.line(surface, color, scale_coord(*start), scale_coord(*end), scale_size(width))

def clear_face(surface):
    """Clear the face area"""
    draw_rect(surface, BLACK, (0, 40, SCREEN_WIDTH, SCREEN_HEIGHT - 40))

def draw_eye(surface, x, y, size, with_pupil=True):
    """Draw a standard eye"""
    draw_circle(surface, WHITE, (x, y), size)
    if with_pupil:
        draw_circle(surface, BLACK, (x, y), size - 10)

def draw_heart(surface, x, y, size, color):
    """Draw a heart shape"""
    # Two circles for top
    draw_circle(surface, color, (x - size//2, y - size//3), size//2)
    draw_circle(surface, color, (x + size//2, y - size//3), size//2)
    # Triangle for bottom
    points = [
        scale_coord(x - size, y - size//3),
        scale_coord(x + size, y - size//3),
        scale_coord(x, y + size)
    ]
    pygame.draw.polygon(surface, color, points)

def draw_happy(surface):
    """Happy expression"""
    draw_eye(surface, FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE, True)
    draw_eye(surface, FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, True)
    
    # Smile
    for i in range(3):
        draw_circle(surface, WHITE, (FACE_X, FACE_Y + 10), 30 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 35, FACE_Y, 70, 15))

def draw_sad(surface):
    """Sad expression"""
    draw_circle(surface, WHITE, (FACE_X - EYE_SPACING, FACE_Y - 25), EYE_SIZE - 5)
    draw_circle(surface, WHITE, (FACE_X + EYE_SPACING, FACE_Y - 25), EYE_SIZE - 5)
    draw_circle(surface, BLACK, (FACE_X - EYE_SPACING, FACE_Y - 25), PUPIL_SIZE - 3)
    draw_circle(surface, BLACK, (FACE_X + EYE_SPACING, FACE_Y - 25), PUPIL_SIZE - 3)
    
    # Frown
    for i in range(3):
        draw_circle(surface, WHITE, (FACE_X, FACE_Y + 60), 30 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 35, FACE_Y + 30, 70, 30))

def draw_surprised(surface):
    """Surprised expression"""
    draw_circle(surface, WHITE, (FACE_X - EYE_SPACING, FACE_Y - 30), EYE_SIZE + 5)
    draw_circle(surface, WHITE, (FACE_X + EYE_SPACING, FACE_Y - 30), EYE_SIZE + 5)
    draw_circle(surface, BLACK, (FACE_X - EYE_SPACING, FACE_Y - 30), PUPIL_SIZE + 5)
    draw_circle(surface, BLACK, (FACE_X + EYE_SPACING, FACE_Y - 30), PUPIL_SIZE + 5)
    
    # Open mouth
    draw_circle(surface, WHITE, (FACE_X, FACE_Y + 30), 15)
    draw_circle(surface, BLACK, (FACE_X, FACE_Y + 30), 12)
    draw_circle(surface, RED, (FACE_X, FACE_Y + 30), 8)

def draw_angry(surface):
    """Angry expression"""
    draw_eye(surface, FACE_X - EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, True)
    draw_eye(surface, FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, True)
    
    # Angry eyebrows
    for i in range(4):
        draw_line(surface, RED, (FACE_X - EYE_SPACING - 20, FACE_Y - 40 - i),
                 (FACE_X - EYE_SPACING + 20, FACE_Y - 50 - i), 1)
        draw_line(surface, RED, (FACE_X + EYE_SPACING + 20, FACE_Y - 40 - i),
                 (FACE_X + EYE_SPACING - 20, FACE_Y - 50 - i), 1)
    
    # Straight mouth
    draw_rect(surface, WHITE, (FACE_X - 30, FACE_Y + 30, 60, 4))

def draw_neutral(surface):
    """Neutral expression"""
    draw_eye(surface, FACE_X - EYE_SPACING, FACE_Y - 30, EYE_SIZE, True)
    draw_eye(surface, FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, True)
    draw_rect(surface, WHITE, (FACE_X - 25, FACE_Y + 30, 50, 3))

def draw_winking(surface):
    """Winking expression"""
    # Winking eye
    for i in range(3):
        draw_line(surface, YELLOW, (FACE_X - EYE_SPACING - 15, FACE_Y - 28 + i),
                 (FACE_X - EYE_SPACING + 15, FACE_Y - 28 + i), 1)
    
    # Open eye
    draw_eye(surface, FACE_X + EYE_SPACING, FACE_Y - 30, EYE_SIZE, True)
    
    # Smile
    for i in range(3):
        draw_circle(surface, YELLOW, (FACE_X, FACE_Y + 10), 25 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 30, FACE_Y, 60, 15))

def draw_sleepy(surface):
    """Sleepy expression"""
    draw_circle(surface, WHITE, (FACE_X - EYE_SPACING, FACE_Y - 28), EYE_SIZE - 5)
    draw_circle(surface, WHITE, (FACE_X + EYE_SPACING, FACE_Y - 28), EYE_SIZE - 5)
    draw_rect(surface, BLACK, (FACE_X - EYE_SPACING - 20, FACE_Y - 40, 40, 15))
    draw_rect(surface, BLACK, (FACE_X + EYE_SPACING - 20, FACE_Y - 40, 40, 15))
    
    # ZZZ
    font = pygame.font.Font(None, scale_size(20))
    z_surface = font.render("ZZZ", True, CYAN)
    screen.blit(z_surface, scale_coord(FACE_X + 50, FACE_Y - 65))
    
    # Small smile
    for i in range(2):
        draw_circle(surface, WHITE, (FACE_X, FACE_Y + 15), 20 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 25, FACE_Y + 5, 50, 15))

def draw_confused(surface):
    """Confused expression"""
    draw_eye(surface, FACE_X - EYE_SPACING, FACE_Y - 35, EYE_SIZE - 3, True)
    draw_eye(surface, FACE_X + EYE_SPACING, FACE_Y - 25, EYE_SIZE - 3, True)
    
    # Wavy mouth
    for x in range(-20, 21, 2):
        y = int(FACE_Y + 30 + math.sin(x * 0.3) * 5)
        draw_rect(surface, WHITE, (FACE_X + x, y, 2, 2))

def draw_excited(surface):
    """Excited expression"""
    draw_circle(surface, YELLOW, (FACE_X - EYE_SPACING, FACE_Y - 30), EYE_SIZE)
    draw_circle(surface, YELLOW, (FACE_X + EYE_SPACING, FACE_Y - 30), EYE_SIZE)
    draw_circle(surface, BLACK, (FACE_X - EYE_SPACING, FACE_Y - 30), PUPIL_SIZE)
    draw_circle(surface, BLACK, (FACE_X + EYE_SPACING, FACE_Y - 30), PUPIL_SIZE)
    
    # Sparkles
    draw_rect(surface, WHITE, (FACE_X - EYE_SPACING - 5, FACE_Y - 35, 3, 8))
    draw_rect(surface, WHITE, (FACE_X - EYE_SPACING - 9, FACE_Y - 31, 8, 3))
    
    # Big smile
    for i in range(4):
        draw_circle(surface, YELLOW, (FACE_X, FACE_Y + 15), 35 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 40, FACE_Y + 5, 80, 15))

def draw_love(surface):
    """Love expression"""
    draw_heart(surface, FACE_X - EYE_SPACING, FACE_Y - 28, 12, MAGENTA)
    draw_heart(surface, FACE_X + EYE_SPACING, FACE_Y - 28, 12, MAGENTA)
    
    # Smile
    for i in range(3):
        draw_circle(surface, MAGENTA, (FACE_X, FACE_Y + 15), 28 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 33, FACE_Y + 5, 66, 15))

def draw_sick(surface):
    """Sick expression"""
    # X eyes
    for i in range(3):
        draw_line(surface, GREEN, (FACE_X - EYE_SPACING - 10, FACE_Y - 35 + i),
                 (FACE_X - EYE_SPACING + 10, FACE_Y - 15 + i), 1)
        draw_line(surface, GREEN, (FACE_X - EYE_SPACING + 10, FACE_Y - 35 + i),
                 (FACE_X - EYE_SPACING - 10, FACE_Y - 15 + i), 1)
        draw_line(surface, GREEN, (FACE_X + EYE_SPACING - 10, FACE_Y - 35 + i),
                 (FACE_X + EYE_SPACING + 10, FACE_Y - 15 + i), 1)
        draw_line(surface, GREEN, (FACE_X + EYE_SPACING + 10, FACE_Y - 35 + i),
                 (FACE_X + EYE_SPACING - 10, FACE_Y - 15 + i), 1)
    
    # Sick mouth
    for i in range(3):
        draw_circle(surface, GREEN, (FACE_X, FACE_Y + 60), 25 + i, 1)
    draw_rect(surface, BLACK, (FACE_X - 30, FACE_Y + 30, 60, 30))

def draw_thinking(surface):
    """Thinking expression"""
    draw_circle(surface, WHITE, (FACE_X - EYE_SPACING, FACE_Y - 30), EYE_SIZE - 3)
    draw_circle(surface, WHITE, (FACE_X + EYE_SPACING, FACE_Y - 30), EYE_SIZE - 3)
    draw_circle(surface, BLACK, (FACE_X - EYE_SPACING, FACE_Y - 36), PUPIL_SIZE - 3)
    draw_circle(surface, BLACK, (FACE_X + EYE_SPACING, FACE_Y - 36), PUPIL_SIZE - 3)
    
    # Mouth
    draw_rect(surface, WHITE, (FACE_X - 15, FACE_Y + 25, 30, 2))
    
    # Thought bubble
    draw_circle(surface, CYAN, (FACE_X + 50, FACE_Y - 70), 20, 1)
    draw_circle(surface, CYAN, (FACE_X + 35, FACE_Y - 50), 5)
    draw_circle(surface, CYAN, (FACE_X + 25, FACE_Y - 40), 3)

# Expression drawing functions
expressions = [
    draw_happy, draw_sad, draw_surprised, draw_angry,
    draw_neutral, draw_winking, draw_sleepy, draw_confused,
    draw_excited, draw_love, draw_sick, draw_thinking
]

def main():
    clock = pygame.time.Clock()
    current_expression = 0
    last_change = time.time()
    running = True
    
    font = pygame.font.Font(None, scale_size(24))
    
    print("Robot Face Simulator")
    print("Press SPACE to cycle expressions manually")
    print("Press Q to quit")
    print("-" * 40)
    
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    running = False
                elif event.key == pygame.K_SPACE:
                    current_expression = (current_expression + 1) % len(expressions)
                    last_change = time.time()
        
        # Auto-cycle every 3 seconds
        if time.time() - last_change > 3:
            current_expression = (current_expression + 1) % len(expressions)
            last_change = time.time()
        
        # Clear screen
        screen.fill(BLACK)
        
        # Draw expression name
        name_surface = font.render(EXPRESSION_NAMES[current_expression], True, WHITE)
        screen.blit(name_surface, scale_coord(10, 10))
        
        # Draw current expression
        clear_face(screen)
        expressions[current_expression](screen)
        
        # Draw instructions
        small_font = pygame.font.Font(None, scale_size(16))
        inst_surface = small_font.render("SPACE: Next | Q: Quit", True, WHITE)
        screen.blit(inst_surface, scale_coord(10, SCREEN_HEIGHT - 20))
        
        pygame.display.flip()
        clock.tick(30)
    
    pygame.quit()

if __name__ == "__main__":
    main()
