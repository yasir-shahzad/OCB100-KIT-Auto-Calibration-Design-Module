/****************************************
 * File: Bubble_sensor_OCB100.c
 * Author: Yasir Shahzad
 * Email: yasirshahzad918@gmail.com
 * Company: Mastermind Technologies
 * Created: January 21, 2025
 * Version: 1.0
 * Description: 
 *      This file contains the main program for controlling a bubble sensor
 *      using PWM signals to calibrate and adjust output voltages. The code 
 *      initializes hardware peripherals, reads voltage sensors, and stores 
 *      calibration data in EEPROM.
 *      
 * License: MIT License
 ****************************************/

#include <stdbool.h>

#define PWM_FREQ           10000 // 10kHz PWM frequency
#define NVM_ADDRESS        0x02  // Non-Voltatile memory Address
#define MAX_CAL_ATTEMPTS   150   // Number of attempts to calibrate

typedef unsigned char uint8_t;

sbit LED1_PIN at GPIO.B1;
sbit CALI_PIN at GPIO.B3;
sbit LED2_PIN at GPIO.B5;

uint8_t i = 0;
float voltage = 0;
float target_voltage = 0;
unsigned int dutyCycle = 0;

bool calibrationSuccess = false;    // Flag for successful calibration
float closest_voltage = 0;          // Store the closest voltage to the target
unsigned int closest_dutyCycle = 0; // Store the duty cycle for the closest voltage

// Function prototypes.
void init(void);
void calibrate(void);
float readVoltage(uint8_t);

void main(void)
{
    init();

    // Load previous dutyCycle value from EEPROM
    dutyCycle = EEPROM_Read(NVM_ADDRESS);

    PWM1_Init(PWM_FREQ);
    PWM1_set_Duty(dutyCycle); // 0 to 255
    PWM1_Start();

    while (1)
    {
        if (CALI_PIN == 0) {
            Delay_ms(10); // Short debounce delay
            if (CALI_PIN == 0) {
                calibrate();
            }
        }
    }
}

void init(void)
{
    TRISIO = 0b00011001; // GP0 and GP3 as inputs, others as outputs
    ANSEL  = 0b00010001; // AN0, AN4 (GP0 & GP4) as analog input
    CMCON0 = 0x07;       // Disable comparators
    ADC_Init();          // Initialize ADC
    LED1_PIN = 0;
    LED2_PIN = 0;
}

/**
 * @brief Calibrates the output voltage to match the target using PWM.
 *
 * Reads the target voltage from ADC and iteratively adjusts the PWM duty cycle 
 * to achieve the closest match. Saves the final duty cycle to EEPROM on success 
 * and indicates status using LEDs (LED2 for success, LED1 for failure).
 */
void calibrate(void)
{
    i = 0;
    LED1_PIN = 0;
    LED2_PIN = 0;
    dutyCycle = 0;

    calibrationSuccess  = false;  // Flag for successful calibration
    closest_voltage = 0;          // Store the closest voltage to the target
    closest_dutyCycle = 0;        // Store the duty cycle for the closest voltage

    target_voltage = readVoltage(4);  // Read the target voltage from ADC channel 4



    while (i < MAX_CAL_ATTEMPTS)
    {
        // Set current PWM duty cycle
        PWM1_set_Duty(dutyCycle);
        Delay_ms(30);

        // Read current voltage
        voltage = readVoltage(0);  // Read the voltage from ADC channel 0

        // Check if current voltage is closer to target voltage
        if (abs(target_voltage - voltage) < abs(target_voltage - closest_voltage) || i == 0)
        {
            closest_voltage = voltage;
            closest_dutyCycle = dutyCycle;
        }

        // Adjust duty cycle to move closer to the target voltage
        if (voltage < target_voltage) {
            dutyCycle++; // Increase duty cycle
        }
        else if (voltage > target_voltage) {
            // Check if decreasing duty cycle gets closer to the target voltage
            if (abs(target_voltage - closest_voltage) < abs(target_voltage - voltage)) {
                calibrationSuccess  = true;
                break; // Stop further adjustments if closest is found
            }
            else {
                dutyCycle--; // Decrease duty cycle
            }
        }

        i++;
    }

    // Finalize calibration and validate results
    PWM1_set_Duty(closest_dutyCycle);
    dutyCycle = closest_dutyCycle;

    if (calibrationSuccess  == true) {
        // Blink LED2 to indicate success
        for (i = 0; i < 4; i++) {
            LED2_PIN = !LED2_PIN;
            Delay_ms(250);
        }
        EEPROM_Write(NVM_ADDRESS, dutyCycle); //success
    } else {
        LED1_PIN = 1;  // Turn on LED1 to indicate failure
    }
}

float readVoltage(uint8_t adcChannel)
{
    return ADC_Read(adcChannel) * (5.0 / 1023.0);
}
