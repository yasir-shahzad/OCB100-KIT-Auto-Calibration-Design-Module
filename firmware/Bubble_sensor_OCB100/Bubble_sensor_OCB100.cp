#line 1 "E:/mastermind/PCB/BubbleSensor/Code/Bubble_sensor_OCB100/Bubble_sensor_OCB100.c"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 23 "E:/mastermind/PCB/BubbleSensor/Code/Bubble_sensor_OCB100/Bubble_sensor_OCB100.c"
typedef unsigned char uint8_t;

sbit LED1_PIN at GPIO.B1;
sbit CALI_PIN at GPIO.B3;
sbit LED2_PIN at GPIO.B5;

uint8_t i = 0;
float voltage = 0;
float target_voltage = 0;
unsigned int dutyCycle = 0;

 _Bool  calibrationSuccess =  0 ;
float closest_voltage = 0;
unsigned int closest_dutyCycle = 0;


void init(void);
void calibrate(void);
float readVoltage(uint8_t);

void main(void)
{
 init();


 dutyCycle = EEPROM_Read( 0x02 );

 PWM1_Init( 10000 );
 PWM1_set_Duty(dutyCycle);
 PWM1_Start();

 while (1)
 {
 if (CALI_PIN == 0) {
 Delay_ms(10);
 if (CALI_PIN == 0) {
 calibrate();
 }
 }
 }
}

void init(void)
{
 TRISIO = 0b00011001;
 ANSEL = 0b00010001;
 CMCON0 = 0x07;
 ADC_Init();
 LED1_PIN = 0;
 LED2_PIN = 0;
}
#line 84 "E:/mastermind/PCB/BubbleSensor/Code/Bubble_sensor_OCB100/Bubble_sensor_OCB100.c"
void calibrate(void)
{
 i = 0;
 LED1_PIN = 0;
 LED2_PIN = 0;
 dutyCycle = 0;

 calibrationSuccess =  0 ;
 closest_voltage = 0;
 closest_dutyCycle = 0;

 target_voltage = readVoltage(4);



 while (i <  150 )
 {

 PWM1_set_Duty(dutyCycle);
 Delay_ms(30);


 voltage = readVoltage(0);


 if (abs(target_voltage - voltage) < abs(target_voltage - closest_voltage) || i == 0)
 {
 closest_voltage = voltage;
 closest_dutyCycle = dutyCycle;
 }


 if (voltage < target_voltage) {
 dutyCycle++;
 }
 else if (voltage > target_voltage) {

 if (abs(target_voltage - closest_voltage) < abs(target_voltage - voltage)) {
 calibrationSuccess =  1 ;
 break;
 }
 else {
 dutyCycle--;
 }
 }

 i++;
 }


 PWM1_set_Duty(closest_dutyCycle);

 if (calibrationSuccess ==  1 ) {

 for (i = 0; i < 4; i++) {
 LED2_PIN = !LED2_PIN;
 Delay_ms(250);
 }
 EEPROM_Write( 0x02 , dutyCycle);
 } else {
 LED1_PIN = 1;
 }
}

float readVoltage(uint8_t adcChannel)
{
 return ADC_Read(adcChannel) * (5.0 / 1023.0);
}
