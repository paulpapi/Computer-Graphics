# Computer Graphics Exercises

## Overview
This repository contains various computer graphics exercises focused on fundamental rendering techniques, OpenGL programming, and visualization strategies.

## Exercises

### 1. **Basic OpenGL Setup**
- Initialize an OpenGL window using GLFW and GLEW.
- Configure a basic rendering loop.
- Handle input controls for interaction.

### 2. **Vertex Shader and Fragment Shader**
- Create a simple vertex shader to manipulate object positions.
- Implement a fragment shader for basic color processing.

### 3. **Transformations and Matrix Scaling**
- Apply translation, rotation, and scaling transformations.
- Understand matrix multiplications in OpenGL.

### 4. **Clipping Algorithms**
- Explore Cohen-Sutherland and Liang-Barsky clipping techniques.
- Implement viewport clipping within OpenGL.

### 5. **Pseudo Color Processing**
- Convert grayscale images into pseudo-color representations.
- Apply color mapping techniques for visualization.

### 6. **Camera Controls with `gluLookAt`**
- Implement dynamic camera movement using `gluLookAt`.
- Explore perspective and orthographic projections.

## Dependencies
Ensure the following libraries are installed:
- OpenGL
- GLFW
- GLEW
- GLM (for matrix operations)

## Usage
Compile and run the exercises using:
```sh
g++ -o graphics_exercise exercise.cpp -lglfw -lGLEW -lGL
./graphics_exercise
