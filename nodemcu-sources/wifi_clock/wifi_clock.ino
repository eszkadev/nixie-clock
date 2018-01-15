/*
 * Copyright (c) 2018 Szymon Kłos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;
char SSID[] = "SSID";
char PASSWORD[] = "PASSWORD";

void setup() {
    Serial.begin(9600);
    delay(10);

    // Output for led
    pinMode(2, OUTPUT);

    // We start by connecting to a WiFi network
    WiFiMulti.addAP(SSID, PASSWORD);

    delay(500);
}


void loop() {
  // Wait for WiFi...
  while(WiFiMulti.run() != WL_CONNECTED) {
      digitalWrite(2, HIGH);
      delay(500);
  }
  digitalWrite(2, LOW);

  String current_time = getTimeFromDate(getDate());
  int index_separator = current_time.indexOf(':');
  int hour = current_time.substring(0, index_separator).toInt();
  hour++;
  String correct_time = String(hour) + current_time.substring(index_separator);
  Serial.print('s');
  Serial.println(correct_time);
  delay(5000);
}

String getDate() {
  WiFiClient client;

  while (!!!client.connect("google.com", 80));
  client.print("HEAD / HTTP/1.1\r\n\r\n");

  while(!!!client.available()) {
     yield();
  }

  while(client.available()){
    if (client.read() == '\n') {   
      if (client.read() == 'D') {   
        if (client.read() == 'a') {   
          if (client.read() == 't') {   
            if (client.read() == 'e') {   
              if (client.read() == ':') {   
                client.read();
                String theDate = client.readStringUntil('\r');
                client.stop();
                return theDate;
              }
            }
          }
        }
      }
    }
  }
}

String getTimeFromDate(String date) {
  return date.substring(17, 25);
}

