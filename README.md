# M5Stack-Car
A car controlled by an M5Stack watch.

## Installation Steps
- Install Arduino v1.8 (or higher).

### For the ESP-12E Controller (Car)
- Start Arduino and open rover/rover.ino .
- Open Preferences window and enter the urls http://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field.
- Open Boards Manager from Tools > Board menu and install the esp32 and esp8266 platforms (and don't forget to select your ESP-12E board from Tools > Board menu after installation).
- Change the SSID details in the code.
- Select the right serial port and burn it!

### For the M5Stack (Watch)
- Open m5stack/m5stack.ino and change your SSID details in the code.
- After carrying out the steps for the ESP-12E board mentioned above, select the M5Stack-Core-ESP32 board from the Boards Managers.
- Install the M5Stack Core Development library from Tools > Manage Libraries.
- Run this in a terminal : ```pip install esptool pyserial```
- Burn it!
