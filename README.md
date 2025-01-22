# OCB100-KIT Auto-Calibration Design Module

The **OCB100-KIT Auto-Calibration Design Module** is a comprehensive solution designed to automate the calibration process for bubble sensors. By dynamically adjusting system parameters to match the target values, this module ensures accurate performance without requiring manual intervention. It provides an intuitive platform for automatic parameter tuning, making it ideal for applications requiring high precision and reliability.

---

## **Features**
- **Automatic Calibration**: Dynamically adjusts parameters to match the target values.
- **Integrated Firmware**: Includes modular and reusable firmware for easy customization.
- **Hardware Design**: Complete hardware schematics and PCB layouts for seamless integration.
- **User-Friendly Documentation**: Detailed user manuals and calibration procedures for smooth setup and operation.
- **Open Source**: Provided under the MIT License, encouraging contributions and collaborations.

---

## **Repository Structure**
```plaintext
OCB100-KIT-Auto-Calibration-Design-Module/
│
├── documents/
│   ├── specifications.pdf          # Detailed technical specifications
│   ├── user_manual.pdf             # User guide for OCB100 usage
│   └── calibration_procedures.md   # Calibration procedures and steps
│
├── firmware/
│   ├── Bubble_sensor_OCB100/
│   │   ├── main.c                  # Main firmware code
│   │   ├── utils.h                 # Utility functions and definitions
│   │   └── calibration.c           # Calibration-specific firmware
│   └── README.md                   # Firmware-related documentation
│
├── hardware/
│   ├── schematics/
│   │   ├── OCB100_Schematic.pdf    # Circuit schematic for the hardware
│   │   └── OCB100_BOM.xlsx         # Bill of Materials (BOM)
│   └── PCB/
│       ├── OCB100_PCB_Layout.pdf   # PCB layout design
│       └── Gerber_Files.zip        # Gerber files for PCB manufacturing
│
├── images/
│   ├── hardware_demo.jpg           # Image of hardware setup
│   ├── firmware_workflow.png       # Firmware workflow visualization
│   └── calibration_diagram.png     # Calibration process illustration
│
├── LICENSE                         # License for the project
└── README.md                       # Project overview and usage instructions
