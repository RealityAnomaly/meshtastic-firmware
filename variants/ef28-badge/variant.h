//#define LED_PIN LED
#define HAS_BUTTON 0

// Enable secondary bus for external periherals
// #define I2C_SDA1 SDA
// #define I2C_SCL1 SCL

// #define ADC_CTRL 37
// #define ADC_CTRL_ENABLED LOW
// #define BATTERY_PIN 10 // A battery voltage measurement pin, voltage divider connected here to measure battery voltage
// #define ADC_CHANNEL ADC1_GPIO1_CHANNEL
// #define ADC_ATTENUATION ADC_ATTEN_DB_2_5 // lower dB for high resistance voltage divider
// #define ADC_MULTIPLIER 4.9 * 1.045

#define USE_SX1262

// all good?
#define LORA_SCK 17
#define LORA_MISO 18
#define LORA_MOSI 8
#define LORA_CS 47 // 2 on header, in parallel with SAO
#define LORA_RESET 6
#define LORA_DIO1 4 // SX1262 IRQ

#define SX126X_CS LORA_CS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY 7
#define SX126X_RESET LORA_RESET
#define SX126X_RXEN 5
#define SX126X_TXEN RADIOLIB_NC // connected to DIO2

// DIO2 on SX1262 connected to TXEN, RXEN connected to GPIO 5
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
