
#include <Servo.h> 
Servo myservo;

class Task{
public:
  int hour;
  int minute;
  String name;
  int grams;

  Task(String name, int hour, int minute, int grams){
    this->name = name;
    this->hour = hour;
    this->minute = minute;
    this->grams = grams;
  }

  void setup(){
    
  }

  void runTask(){
    //move servomotor for 
    printText("running task "+this->name);
    for(int times = 0; times <= grams/2;times++)
    {
      for(int pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(5);                       // waits 15ms for the servo to reach the position 
      } 
    }
  }


  void setName(String name){
    this->name = name;
  }
  String getName(){
    return this->name;
  }
  void setHour(int hour){
    this->hour = hour;
  }
  int getHour(){
    return this->hour;
  }
  void setMinute(int minute){
    this->minute = minute;
  }
  int getMinute(){
    return this->minute;
  }
  void setGrams(int grams){
    this->grams = grams;
  }
  int getGrams(){
    return this->grams;
  }
};
