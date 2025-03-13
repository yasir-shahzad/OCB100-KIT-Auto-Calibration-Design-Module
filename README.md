# OCB100-KIT Auto-Calibration Design Module

[![Discord](https://img.shields.io/discord/1098363068435681290?style=social&logo=discord&label=COMMUNITY)](https://discord.gg/HtTujA2N)
[![Ko-fi](https://img.shields.io/badge/Support%20on%20Ko--fi-F16061?style=flat&logo=kofi&logoColor=white&labelColor=%23FF5E5B)](https://ko-fi.com/creapunk)

The **OCB100-KIT Auto-Calibration Design Module** is a comprehensive solution designed to automate the calibration process for bubble sensors. By dynamically adjusting system parameters to match the target values, this module ensures accurate performance without requiring manual intervention. It provides an intuitive platform for automatic parameter tuning, making it ideal for applications requiring high precision and reliability.

---

- ## Key Features
- 🎯 **Automatic Calibration:** Dynamically fine-tunes parameters to precisely match target values.  
- 💾 **Integrated Firmware:** Modular and reusable firmware for seamless customization and updates.  
- 🔧 **Hardware Design:** Complete schematics and PCB layouts for effortless integration.  
- 📖 **User-Friendly Documentation:** Step-by-step manuals and calibration guides for smooth setup.  
- 🚀 **Open Source:** MIT-licensed, fostering community contributions and innovation.  

## Applications  

- 🏥 **Medical Devices:** Ensures precise fluid monitoring in IV drips and dialysis machines.  
- 🏭 **Industrial Automation:** Enhances liquid level detection in manufacturing processes.  
- 🚗 **Automotive Systems:** Supports fuel and coolant level sensing for optimal performance.  
- 🔬 **Laboratory Equipment:** Provides high-precision calibration for scientific instruments.     
- 🌱 **Environmental Monitoring:** Detects liquid levels in water treatment and irrigation systems.  




[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC_BY--NC--SA_4.0-lightgrey.svg)](license.md)


## Repository Structure

- **[`wiki`](wiki)**: includes design documentation and other information
- **[`hardware`](hardware)**: contains design source files, manufacturing files, schematics, block diagrams and 3D models
- **[`firmware`](https://github.com/creapunk/TunePulse)**: [to be updated as the project evolves]

## Hardware Versions

#### [NEMA17 dedicated drivers](./wiki/CLN17/readme.md)

- **[`V1.5`](hardware/CLN17/V1.5)** [tested]: cost-efficient version [[wiki]](./wiki/CLN17/V1.5/specification.md)

  ![Preview](wiki/assets/CLN17/V1.5/CLN17-V1.5-PHOTO.JPG)

  > - **Key info:** TMC2209 based, 5-25V 1.4A<sub>RMS</sub>, 15bit position feedback, single-sided assembly
  >- **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, USART, I2C, SPI, ABZ
  > - **Release of source files:** Released

  

- **[`V2.0`](hardware/CLN17/V2.0)** [tested]: high voltage version [[wiki]](./wiki/CLN17/V2.0/specification.md)

![Preview](wiki/assets/CLN17/V2.0/CLN17-V2.0-PHOTO.JPG)
  > - **Key info:** DRV8844 based, 8-48V 1.75A<sub>RMS</sub>, 15bit position feedback, single-sided assembly
  >- **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, USART, I2C, SPI, ABZ
  > - **Release of source files:** April 2024 (post BETA)


##### OBSOLETE 

**[`CLN17 V1.0`](hardware/CLN17/V1.0)** [obsolete]: pilot version [[wiki]](./wiki/CLN17/V1.0/specification.md)

***Important Note:** Obsolete designs will not be supported in future*

#### NEMA23 and NEMA34 dedicated drivers

- **[`V0.1`](hardware/CLN17/V1.5)** [in design]: powerful and versatile [[wiki]](./wiki/CLN234/V0.1/specification.md)

	> **Key info:** external MOSFETs, 6-52V 10A<sub>RMS</sub>, 16bit/21bit position feedback
	>
	> **Supported interfaces:** STEP-DIR-EN, USB, CAN-FD, USART, I2C, SPI, ABZ

#### Modular drivers dedicated for embedded systems

Jump to the [RadiX project repository](https://github.com/creapunk/RadiX)

------

## Hardware Development Roadmap

- **[April 2024]** - BETA LAUNCH for CLN17 V2.0, source files release
- **[April 2024]** - CLN234 design for Nema23, Nema34 and Nema42
- **[June 2024]** - CLN14 for Nema14 miniature motors

***Important Note:** If critical problems will be revealed, the schedule will be updated*

## Supporting the Project

If this project resonates with you, please consider the following ways to support its development:

- **[Ko-fi](https://ko-fi.com/creapunk):** Preferred for membership subscription and one-time donation
- **[Patreon](https://patreon.com/creapunk):** Alternative platform with higher fees
- **Join [Discord community](https://discord.gg/V4aJdTja8v):** Stay updated, engage in discussions, and contribute to the project

**Your contribution, regardless of size, is greatly appreciated!** 

*A heartfelt thank you to [everyone who supports this project](sponsors.md)!*












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






































---




