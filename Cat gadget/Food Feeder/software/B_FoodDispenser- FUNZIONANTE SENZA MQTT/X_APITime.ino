

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;

class APITime{

public:

  String timeNow;
  String url = "http://www.timeapi.org/cet/now?format=%25d%23%25H%23%25M%23%25S";

  APITime(){
    
    http.begin(url); //HTTP
   
    int httpCode = http.GET();
    if(httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      printText("[HTTP] GET... code: %d\n"+ httpCode);
      // file found at server
      if(httpCode == HTTP_CODE_OK) {
          this->timeNow =  http.getString();
      }
    } else {
        printText("[HTTP] GET... failed, error: %s\n"+ String(http.errorToString(httpCode).c_str()));
    }

    http.end();
  }
  
  void setup(){
    
  }
  
  String getTime(){
    return this->timeNow;
  }

  void updateTime(){
    
    http.begin(url); //HTTP
   
    int httpCode = http.GET();
    if(httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      printText("[HTTP] GET... code: %d\n"+ httpCode);
      // file found at server
      if(httpCode == HTTP_CODE_OK) {
          this->timeNow =  http.getString();
      }
    } else {
        printText("[HTTP] GET... failed, error: %s\n"+ String(http.errorToString(httpCode).c_str()));
    }

    http.end();
  }
};

