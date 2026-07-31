# 🐍 Snake Game (C++ / SFML)

A modern implementation of the classic **Snake** game developed in **C++** using the **SFML** multimedia library. The project focuses on clean code organization, object-oriented programming, and game development fundamentals.

---

## 📸 Preview

> *(Add screenshots or a gameplay GIF here.)*

---

## ✨ Features

- Classic Snake gameplay
- Smooth real-time movement
- Food generation at random positions
- Score tracking
- Collision detection
- Game Over state
- Modular object-oriented architecture
- Cross-platform development with SFML

---

## 🛠 Technologies

- C++17
- SFML 2.6
- Visual Studio 2022

---

## 📂 Project Structure

```text
SnakeGame/
│
├── assets/          # Fonts, textures and resources
├── include/         # Header files
├── src/             # Source files
├── README.md
└── SnakeGame.sln
```

---

## 🚀 Getting Started

### Requirements

- Visual Studio 2022
- SFML 2.6.x
- C++17 compatible compiler

### Build

1. Clone the repository

```bash
git clone https://github.com/bAbderraouf/snakeGame.git
```

2. Open the solution with Visual Studio.

3. Configure the SFML include, library and DLL paths.

4. Build and run the project.

---

## 🎮 Controls

| Key | Action |
|------|--------|
| ↑ | Move Up |
| ↓ | Move Down |
| ← | Move Left |
| → | Move Right |

---

## 🏗 Project Objectives

This project was developed to practice:

- Object-Oriented Programming (OOP)
- Game loop architecture
- Event handling
- Collision detection
- Resource management
- Modular C++ project organization
- SFML graphics programming

---

## 📈 Future Improvements

- Main menu
- Pause feature
- High score system
- Sound effects
- Background music
- Difficulty levels
- Animated graphics

---

## 👤 Author

**Abderraouf B.**

GitHub: https://github.com/bAbderraouf

---

## 📄 License

This project is released for educational and learning purposes.

## SFML Setup (Visual Studio 2022)

### 1. Download SFML

Download **SFML 2.6.2** for **Visual Studio 2022** (32-bit or 64-bit depending on your project configuration).

### 2. Extract the archive

Extract the downloaded SFML archive to a location of your choice, for example:

```text
C:\SFML-2.6.2
```

---

### 3. Configure your Visual Studio project

#### Include Directories

**Project → Properties → C/C++ → General → Additional Include Directories**

```text
$(ProjectDir)\include;
C:\SFML-2.6.2\include;
```

---

#### Library Directories

**Project → Properties → Linker → General → Additional Library Directories**

```text
C:\SFML-2.6.2\lib
```

---

#### Linker Dependencies

**Project → Properties → Linker → Input → Additional Dependencies**

For **Release**:

```text
sfml-graphics.lib
sfml-window.lib
sfml-system.lib
sfml-audio.lib
```

For **Debug**, use the debug libraries instead:

```text
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
```

---

### 4. Copy the required DLL files

Copy the required DLL files from:

```text
SFML\bin
```

to your application's output directory (for example `x64/Debug` or `x64/Release`).

```
SFML/bin
    ↓
Project/x64/Debug/
```

> **Note:** If you are building in **Debug**, copy the `*-d-2.dll` files.  
> If you are building in **Release**, copy the standard `.dll` files.
