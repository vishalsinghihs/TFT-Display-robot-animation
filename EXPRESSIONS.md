# Facial Expressions Reference

This document describes the visual characteristics of each of the 12 robot facial expressions.

## 1. Happy 😊
**Description:** A cheerful, welcoming expression
- **Eyes:** Round, open circles with centered pupils
- **Mouth:** Wide upward curve (smile)
- **Color:** White with black pupils
- **Use Case:** Greeting, positive feedback, success messages

**Key Features:**
```
    ●   ●     <- Round eyes
   ∪‿∪∪‿∪     <- Smiling mouth
```

---

## 2. Sad 😢
**Description:** Melancholic, downcast expression
- **Eyes:** Smaller circles with pupils, slightly droopy
- **Mouth:** Downward curve (frown)
- **Eyebrows:** Angled upward (cyan/blue)
- **Color:** White/cyan accents
- **Use Case:** Error messages, low battery, failure states

**Key Features:**
```
   ⌣ ● ⌣     <- Sad eyebrows and droopy eyes
    ‿‿‿      <- Frowning mouth
```

---

## 3. Surprised 😮
**Description:** Shocked or amazed expression
- **Eyes:** Large, wide open circles
- **Pupils:** Larger than normal
- **Mouth:** Open circle
- **Color:** White eyes, red inside mouth
- **Use Case:** Unexpected events, sensor detection, alerts

**Key Features:**
```
    ●   ●     <- Large wide eyes
      ○       <- Open round mouth
```

---

## 4. Angry 😠
**Description:** Aggressive or frustrated expression
- **Eyes:** Normal circles with pupils
- **Eyebrows:** Angled sharply downward toward center (red)
- **Mouth:** Straight horizontal line
- **Color:** Red eyebrows, white elements
- **Use Case:** Warning states, obstacles detected, errors

**Key Features:**
```
  ⩗ ●   ● ⩖   <- Angry angled eyebrows
    ―――――     <- Straight mouth
```

---

## 5. Neutral 😐
**Description:** Calm, default resting state
- **Eyes:** Standard round circles with pupils
- **Mouth:** Simple horizontal line
- **Color:** White/standard
- **Use Case:** Idle state, waiting, standby mode

**Key Features:**
```
    ●   ●     <- Normal eyes
     ―――      <- Neutral mouth line
```

---

## 6. Winking 😉
**Description:** Playful, knowing expression
- **Left Eye:** Closed (horizontal line) - yellow
- **Right Eye:** Open circle
- **Mouth:** Slight smile
- **Color:** Yellow accents for playfulness
- **Use Case:** Acknowledgment, playful responses, Easter eggs

**Key Features:**
```
    ―   ●     <- One closed, one open
   ∪‿∪∪‿∪     <- Playful smile
```

---

## 7. Sleepy 😴
**Description:** Tired, low-energy state
- **Eyes:** Half-closed (top covered)
- **Mouth:** Small gentle smile
- **Additional:** "ZZZ" floating animation
- **Color:** White with cyan "Z"s
- **Use Case:** Sleep mode, low power, standby

**Key Features:**
```
  ▂▂▂ ▂▂▂    <- Half-closed eyes
     ‿‿      <- Small smile
  Z Z z      <- Sleep indicators
```

---

## 8. Confused 😕
**Description:** Uncertain or puzzled expression
- **Eyes:** Asymmetric - one higher than the other
- **Eyebrow:** One raised (yellow)
- **Mouth:** Wavy line
- **Color:** Yellow accents
- **Use Case:** Unclear input, ambiguous situations

**Key Features:**
```
   ⌣ ●
      ● ―    <- Asymmetric eyes
    ≈≈≈≈     <- Wavy mouth
```

---

## 9. Excited 🤩
**Description:** Enthusiastic, energetic expression
- **Eyes:** Large circles with sparkles/stars (yellow)
- **Mouth:** Wide, large smile
- **Additional:** Star shapes near eyes
- **Color:** Yellow/gold tones
- **Use Case:** Success, achievements, high engagement

**Key Features:**
```
  * ●   ● *  <- Eyes with sparkles
   ∪∪∪∪∪∪∪   <- Big wide smile
```

---

## 10. Love 😍
**Description:** Affectionate, adoring expression
- **Eyes:** Heart shapes (magenta/pink)
- **Mouth:** Warm smile
- **Color:** Magenta/pink theme
- **Use Case:** Positive feedback, favorites, appreciation

**Key Features:**
```
    ♥   ♥     <- Heart-shaped eyes
   ∪‿∪∪‿∪     <- Loving smile
```

---

## 11. Sick 🤢
**Description:** Unwell, malfunctioning state
- **Eyes:** X marks
- **Mouth:** Downward wavy line
- **Color:** Green tint
- **Use Case:** System errors, sensor failures, diagnostics

**Key Features:**
```
    ✗   ✗     <- X eyes
     ∿∿∿      <- Sick wavy mouth
```

---

## 12. Thinking 🤔
**Description:** Contemplative, processing expression
- **Eyes:** Looking upward (pupils at top)
- **Mouth:** Small neutral line
- **Additional:** Thought bubble with circles
- **Color:** White/cyan accents
- **Use Case:** Processing, calculating, decision making

**Key Features:**
```
    ○   ○     <- Eyes looking up
  ●           
 ●    ―――     <- Thought bubble and mouth
○              
```

---

## Expression Timing

In the default sketch, each expression is displayed for **3 seconds** before transitioning to the next. This can be customized in the code.

## Color Palette Reference

| Expression | Primary Color | Accent Color |
|------------|--------------|--------------|
| Happy      | White        | Black        |
| Sad        | White        | Cyan         |
| Surprised  | White        | Red          |
| Angry      | White        | Red          |
| Neutral    | White        | Black        |
| Winking    | Yellow       | Yellow       |
| Sleepy     | White        | Cyan         |
| Confused   | Yellow       | Yellow       |
| Excited    | Yellow       | Yellow       |
| Love       | Magenta      | Magenta      |
| Sick       | Green        | Green        |
| Thinking   | White        | Cyan         |

## Animation Sequence

The expressions cycle in order:
1. Happy → 2. Sad → 3. Surprised → 4. Angry → 5. Neutral → 6. Winking → 
7. Sleepy → 8. Confused → 9. Excited → 10. Love → 11. Sick → 12. Thinking → (repeat)

## Customization Ideas

### Personality Variations
- **Energetic Robot:** Focus on Happy, Excited, Winking
- **Serious Robot:** Use Neutral, Thinking, Angry more
- **Friendly Robot:** Emphasize Happy, Love, Winking
- **Nervous Robot:** Show Confused, Surprised, Sleepy

### Context-Aware Expressions
- **Button Press:** Happy or Winking
- **Obstacle Detected:** Surprised or Angry
- **Low Battery:** Sad or Sleepy
- **Task Complete:** Excited or Happy
- **Error State:** Sick or Angry
- **Idle/Waiting:** Neutral or Thinking

### Expression Combinations
Create more complex behaviors by sequencing expressions:
- **Wake Up:** Sleepy → Surprised → Happy
- **Realize Mistake:** Happy → Confused → Sad
- **Get Excited:** Neutral → Thinking → Excited
- **Feel Better:** Sick → Sad → Neutral → Happy

---

## Technical Drawing Details

### Face Coordinates (240x320 screen)
- **Center:** X=120, Y=160
- **Eye Spacing:** 40 pixels apart
- **Eye Size:** 20 pixel radius
- **Pupil Size:** 10 pixel radius

### Standard Proportions
- Eyes positioned at Y-30 from center
- Mouth positioned at Y+15 to Y+30 from center
- Eyebrows at Y-45 to Y-50 from center

---

For implementation details, see the `robot_facial_expressions.ino` file.
