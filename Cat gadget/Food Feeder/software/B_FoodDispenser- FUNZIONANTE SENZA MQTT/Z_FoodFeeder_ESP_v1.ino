


 
/**
const char* ssid     = "VodafoneMobileWiFi-0EB789";
const char* password = "0615141181";
*/

const char* ssid     = "enrico e  antani";
const char* password = "aleandri";


//Accuracy settings
Rtc rtc_timer;
APITime apitime;

Scheduler scheduler;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  myservo.attach(2);  // attaches the servo on GIO2 to the servo object 

  display.display();


  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.

  WiFi.begin(ssid, password);
  
  display.clearDisplay();
  display.setCursor(0,0);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
    display.display();
  }

  IPAddress _address = WiFi.localIP();
  printText("WiFi connected \nIP address: "+_address.toString());  
  apitime = APITime(); // GET current time from server returning a string linke 12#19#25#17 DAY#HOUR#MINUTE#SECONDS
  //apitime.setup();
  
  printText("APITime created");
  //apitime.updateTime();
  
  //printText("APITime UPDATED");
  
  String TimeNow = apitime.getTime();
  String d =  TimeNow.substring(0,2);
  String h =  TimeNow.substring(3,5);
  String m =  TimeNow.substring(6,8);
  String s =  TimeNow.substring(9,11);
  
  printText("Time getted : "+TimeNow);
  rtc_timer = Rtc();
  printText("Rtc created");
  rtc_timer.setup(d.toInt(), h.toInt(),m.toInt(),s.toInt());

  printText("setup RTC DONE");
  scheduler = Scheduler();
  scheduler.setup();
  
  printText("Scheduler created");
  Task task = Task( "spuntino notturno", 0, 50, 20);
  scheduler.updateTask(0, task);
  task = Task( "Cena de stocazzo", 19, 28, 20);
  scheduler.updateTask(1, task);
  task = Task( "Pranzo", 19, 29, 20);
  scheduler.updateTask(2, task);
  
  printText("Tasks created");

  // Clear the buffer.
  display.clearDisplay();

}


void loop() {
  // put your main code here, to run repeatedly:

//let the sketch know that a new day has started for what concerns correction, if this line was not here the arduiono
// would continue to correct for an entire hour that is 24 - startingHour. 
  rtc_timer.loopTime();

  


  int seconds = rtc_timer.getSeconds();
  int minutes = rtc_timer.getMinutes();
  int hours = rtc_timer.getHours();
  int days = rtc_timer.getDays();


  
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  scheduler.checkTask(rtc_timer.getHours(), rtc_timer.getMinutes(), rtc_timer.getSeconds());
  display.println("The time is:");
  //display.print(days);
  //display.print(":");
  display.print(hours);
  display.print(":");
  display.print(minutes);
  display.print(":"); 
  display.println(seconds); 

  display.display();
  display.clearDisplay();
  

 

}




