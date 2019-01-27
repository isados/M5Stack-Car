# M5Stack-Car
A car controlled by an M5Stack-Core watch.

## Installation Steps
- Install Arduino v1.8 (or higher).

### For the ESP32
- Start Arduino and open Preferences window.
- Enter the urls https://dl.espressif.com/dl/package_esp32_index.json into Additional Board Manager URLs field.
- Open Boards Manager from Tools > Board menu and install esp32 platform (and don't forget to select your ESP32 board from Tools > Board menu after installation).

Arduino Uno Wifi Dev Ed Library
- Select ESP32 board from Tools.
- Open rover/rover.ino and change the SSID details.
- Select the right serial port and burn it!

### For the M5Stack
- After the steps for the ESP32 board mentioned above, select the M5Stack-Core-ESP32 board.
- Open m5stack/m5stack.ino and burn the code.
