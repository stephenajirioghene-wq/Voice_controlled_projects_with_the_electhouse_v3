# Voice Controlled Projects with the Elechouse V3

This repository contains an OOP-based Arduino project template for building voice-controlled systems using the **Elechouse Voice Recognition Module V3**.  
It provides a simple and reusable framework to train and load pairs of voice commands at the push of a button, making it easy to extend into any Arduino voice-controlled application.  

---

# Features
- Object-oriented C++ design for Arduino projects  
- Supports Elechouse Voice Recognition Module V3
- Train and load voice commands dynamically (pair of commands)  
- Minimal structure: focus on your own custom code  
- Extendable for multiple Arduino projects (motors, LEDs, relays, etc.)  

---

##  Project Structure
```
vr/
├── Readme...vr module.txt     # Notes/documentation
└── code/
    └── vr module structure/
        └── structure.ino            # Main Arduino sketch (template)
```

---

## Requirements
- Arduino IDE (or PlatformIO)  
- Elechouse Voice Recognition Module V3  
- Arduino-compatible board (e.g., Uno, Mega, Nano)  
- Jumper wires and breadboard 
- Push button or capacitive touch switch 

---

##  Hardware Setup
1. Connect the Elechouse V3 module to the Arduino using serial pins:  
   - VCC - 5V 
   - GND - GND  
   - TX, RX - any data pins of your choice 
   -  pins 2 or 3( any interrupt enabled pin)
2. Upload the provided structure.ino sketch to your Arduino.  
3. Use the push button to train and load voice commands.  

---

## 📖 Usage
- Clone the repository:  
  ```bash
  git clone https://github.com/yourusername/Voice_controlled_projects_with_the_elechouse_v3.git
  ```
- Open the "vr\code\vr module structure\structure.ino" file in Arduino IDE.  
- Compile and upload to your Arduino board.  
- Extend the sketch by adding your own actions for recognized commands.  

---


## 📚 References
- [Elechouse Voice Recognition V3 Documentation](http://www.elechouse.com/elechouse/images/product/VR3/VR3%20manual.pdf)  
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)  

---

## 📜 License
This project is open-source under the MIT License.  
