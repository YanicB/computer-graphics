# 🧭 SimpleView — 3D Object Viewer

### OpenGL & C++ Implementation of Transformations and Hierarchical Modeling

---

## 🧩 Overview

**SimpleView** is a lightweight 3D graphics viewer built with **C++**, **OpenGL**, and **GLUT**.  
It allows users to create, transform, and view 3D objects using an interactive mouse and menu system.

The project demonstrates how translation, rotation, and scaling work across different coordinate systems — Model, World, and View (Camera) — while following an object-oriented design approach.

---

## ✨ Features

- **3D Object Rendering:** Cube, Pyramid, and House objects  
- **Transformations:**
  - Translation, rotation, and scaling in Model (MCS) and World (WCS) coordinates  
  - Camera rotation and translation in View (VCS) coordinates  
- **Hierarchical Modeling:** The House object is built by combining a cube and pyramid  
- **Interactive Controls:** Menu-based transformations and camera adjustments using the mouse  
- **Matrix Operations:** Custom 4×4 matrix class supporting transpose, normalization, and rotation  
- **Clean OOP Architecture:** Classes for Matrix, Vector, Shape, Camera, and World management  

---

## 🖱️ Controls

Right-click anywhere in the OpenGL window to open the menu:

- **Reset** – Restore initial camera and object positions  
- **Select Object** – Choose between Cube, Pyramid, or House  
- **MCS Transformations** – Rotate or scale an object in local coordinates  
- **WCS Transformations** – Translate or rotate an object in world space  
- **VCS Transformations** – Move or rotate the camera, or adjust near/far planes  

Mouse dragging applies the selected transformation.

---

## ⚙️ Setup & Build

### Prerequisites
- **C++ compiler** (GCC, Clang, or MSVC)
- **OpenGL** and **GLUT/freeGLUT** libraries installed

### Build Instructions
```bash
g++ src/*.cpp -lGL -lGLU -lglut -o SimpleView
./SimpleView


