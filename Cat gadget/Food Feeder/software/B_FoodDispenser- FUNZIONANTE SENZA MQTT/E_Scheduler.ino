

class Scheduler{
  public:
  Task tasks[3] = {Task( "", 0, 0, 0),
                   Task( "", 0, 0, 0),
                   Task( "", 0, 0, 0)};


  Scheduler(){
    }

  void setup(){
   
   
  }

  void updateTask(int index, Task& task){
    this->tasks[index] = task;
  }
  Task getTask(int index){
    return this->tasks[index];
  }

  void checkTask(int hour, int minute, int seconds){

    for(int i = 0; i<sizeof(this->tasks);i++){
     
        if(this->tasks[i].getHour() == hour && this->tasks[i].getMinute() == minute &&  seconds == 0){
   
          this->tasks[i].runTask();
        }
      
    }
  }
  
};

