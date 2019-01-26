#include <WiFi.h>
#include <HTTPClient.h>
#include <M5Stack.h>

//Enter your SSID information here
const char* ssid = "SSID";
const char* password =  "PASSWORD";
 
void setup() {
   // init lcd, serial, not init sd card
  M5.begin(true, false, true);
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.println("ROVER CAR");
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Connecting to WIFI...");
  M5.Lcd.setTextColor(RED);

  // init wifi client and establishing a connection
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
  M5.Lcd.println("\nConnection established!");
  delay(1000);
}
 
void loop() {
  M5.update();
  
  // if want use Releasefor; suggest use Release in press event
  if (M5.BtnA.isPressed()) {
    M5.Lcd.print("Left");
    send_command("left");
  } else if (M5.BtnB.isPressed()) {
    M5.Lcd.print("Forward");
    send_command("forward");
  } else if (M5.BtnC.isPressed()) {
    M5.Lcd.print("Right");
    send_command("right");
  } else {
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
    send_command("stop");
  }
 
}


void send_command(String command)
{
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
    String request="http://192.168.0.35/"+command;
    http.begin(request); //Specify the URL
    int httpCode = http.GET(); //Make the request
// To check for returning payloads, if any    
// 
//    if (httpCode > 0) { //Check for the returning code
// 
//        String payload = http.getString();
//        Serial.println(httpCode);
//        Serial.println(payload);
//      }
// 
//    else {
//      Serial.println("Error on HTTP request");
//    }
// 
    http.end(); //Free the resources
  }
 
}
