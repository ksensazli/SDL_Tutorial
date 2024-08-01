# SDL2 Tutorial Project

## Overview
This project is a simple SDL2 tutorial demonstrating basic functionalities such as drawing shapes, displaying images, and playing audio. The program initializes SDL, creates a window and renderer, loads BMP images, draws a circle, line, and rectangle, and plays an audio file.

## Features
- **Drawing Shapes:** Draws a circle, line, and rectangle on the screen.
- **Image Display:** Loads and displays BMP images.
- **Audio Playback:** Plays a WAV audio file.
- **Event Handling:** Handles window events and keyboard input to exit the application.

## Prerequisites
- **SDL2:** Ensure SDL2 is installed on your system.
- **SDL2_image:** Needed for loading BMP images.
- **SDL2_mixer:** Required for playing audio files.

## Installation
1. **Clone the repository**
   ```bash
   git clone https://github.com/ksensazli/SDL_Tutorial.git
   cd SDL_Tutorial
   ```
2. **Build the Project**
   - Ensure you have a C++ compiler installed. Run the following commands:
     ```bash
     g++ -o sdl2_tutorial main.cpp -lSDL2 -lSDL2_image -lSDL2_mixer
     ```

## Usage
1. Run the Executable
   ```bash
   ./sdl2_tutorial
   ```
2. Controls
   - **ESC Key:** Exit the application.

## Code Overview
### Drawing a Circle
The draw_circle function is used to draw a circle on the screen at a specified location with a given radius and color.

### Playing Audio
The playAudio function initializes the SDL audio subsystem, loads a WAV file, and plays it.

### Main Function
- Initializes SDL and creates a window.
- Creates a renderer and loads BMP images.
- Draws shapes and images on the screen.
- Plays an audio file.
- Handles events to allow quitting the application.

### File Structure
```css
sdl2-tutorial-project/
├── main.cpp
├── example.wav
├── sample.bmp
├── button.bmp
└── README.md
```

### Troubleshooting
- Ensure SDL2, SDL2_image, and SDL2_mixer libraries are correctly installed and linked.
- Check file paths for BMP images and WAV audio to ensure they are correct.
