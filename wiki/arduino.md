Arduino is used for integrating qcw with external devices. It reads the status of the key and sends it to PC using the embedded serial port, it produces the sound of manipulation using a small speaker and it shows which key is pressed, if using a paddle key, with 2 leds.

# External circuit
Altough the included Arduino sketch is designed for using this system even without a PC, using just an external power supply (like a simple USB powerbank), it requires to build a simple circuit with few resistors and/or leds to grant proper voltage levels on used pins and to display key pressing informations.

All input pins require a pull-down resistor between arduino pin and ground to avoid floating pin voltage.

Output sound is produced generating a squared wave using a digital output pin and introducing a variable delay between high and low level to change the output frequency. In order to connect a simple 4 or 8 ohm speaker directly to the output pin you must use a resistor to ensure a small current drain from the Arduino pin. At least a 100 omh resistor must be used to ensure a current below 40 mA, which is the maximum output current of an Arduino output pin.

# Pins
At the top of the sketch source code there are some macros used for defining pin numbers.
Default values are listed here:

Feature|Default pin|Description
-|-|-
LED_GENERIC|13|ON when sound outputs, OFF when there is no sound
LED_DOT|6|Blinks when the DOT pad or straight key is pressed
LED_DASH|5|Blinks when the DASH pad or straight key is pressed
OUTPUT_SOUND|7|Sound output
TONE|A0|*Analog input* pin used for changing output note frequency
TONE|A4|*Analog input* pin used for changing speed of automatic keyer (used with paddle key)
KEY_DOT|3|Input pin for DOT paddle key
KEY DASH|4|Input pin for DASH paddle key
KEY_MANUAL|2|Input pin used for sraight key

# Schemas
## Input pin
![Input pin](https://raw.githubusercontent.com/sardylan/qcw/master/wiki/images/input-pin.png "Input pin example")

This is an example on how to wire an external key with the input pin on arduino, using a pull-down resistor to avoid floating ping voltages.

## Analog input pin
![Analog Input pin](https://raw.githubusercontent.com/sardylan/qcw/master/wiki/images/analog-input.png "Analog input pin example")

This schema represents how to wire a potentiometer in an analog-input pin using +5V and GND as maximum and minimum voltage.

## Output led
![Output led](https://raw.githubusercontent.com/sardylan/qcw/master/wiki/images/output-led.png "Output LED")

This schema descrive how to wire a LED to a digital output pin.

## Output speaker
![Output speaker](https://raw.githubusercontent.com/sardylan/qcw/master/wiki/images/output-speaker.png "Output speaker")

This schema explains how to connect a speaker directly on an output digital pin.
