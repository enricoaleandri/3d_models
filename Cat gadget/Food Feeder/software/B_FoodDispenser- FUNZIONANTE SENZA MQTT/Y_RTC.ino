
class Rtc{

  public:
  
  int days;
  int hours;
  int minutes;
  int seconds;
  int startingHour;


  unsigned long timeNow = 0;
  unsigned long timeLast = 0;

  int dailyErrorFast = 0; // set the average number of milliseconds your microcontroller's time is fast on a daily basis
  int dailyErrorBehind = 0; // set the average number of milliseconds your microcontroller's time is behind on a daily basis
  
  int correctedToday = 1; // do not change this variable, one means that the time has already been corrected today for the error in your boards crystal. This is true for the first day because you just set the time when you uploaded the sketch.  
  Rtc(){
  }
  void setup( int days, int startingHour, int minutes, int seconds)
  {
    this->days =days;
    this->startingHour = startingHour;
    this->hours = this->startingHour;
    this->minutes = minutes;
    this->seconds = seconds;
  }


  void loopTime(){
    

    timeNow = millis()/1000; // the number of milliseconds that have passed since boot
    seconds = timeNow - timeLast;//the number of seconds that have passed since the last time 60 seconds was reached.
    
      
    
    if (seconds == 60) {
      timeLast = timeNow;
      minutes = minutes + 1;
    }
    
    //if one minute has passed, start counting milliseconds from zero again and add one minute to the clock.
    
    if (minutes == 60){ 
      minutes = 0;
      hours = hours + 1;
    }
    
    // if one hour has passed, start counting minutes from zero and add one hour to the clock
    
    if (hours == 24){
      hours = 0;
      days = days + 1;
      }
    
      //if 24 hours have passed , add one day
    
    if (hours ==(24 - startingHour) && correctedToday == 0){
      delay(dailyErrorFast*1000);
      seconds = seconds + dailyErrorBehind;
      correctedToday = 1;
    }
    
    //every time 24 hours have passed since the initial starting time and it has not been reset this day before, add milliseconds or delay the progran with some milliseconds. 
    //Change these varialbes according to the error of your board. 
    // The only way to find out how far off your boards internal clock is, is by uploading this sketch at exactly the same time as the real time, letting it run for a few days 
    // and then determine how many seconds slow/fast your boards internal clock is on a daily average. (24 hours).
    
    if (hours == 24 - startingHour + 2) { 
      correctedToday = 0;
    }

  }
  void setDays(int days){
    this->days = days;
  }
  int getDays(){
    return this->days;
  }
  void setHours(int hours){
    this->hours = hours;
  }
  int getHours(){
    return this->hours;
  }
  void setMinutes(int minutes){
    this->minutes = minutes;
  }
  int getMinutes(){
    return this->minutes;
  }
  void setSeconds(int seconds){
    this->seconds = seconds;
  }
  int getSeconds(){
    return this->seconds;
  }
};

