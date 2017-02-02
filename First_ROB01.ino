#define lmotorf 4
#define lmotorb 5
#define rmotorf 2
#define rmotorb 3
/*#define irs 1
#define irs 2
#define irs 3
#define irs 4
*/
void irmLeft()
 
      {
        digitalWrite(lmotorf,LOW);
        digitalWrite(rmotorf,HIGH);

        digitalWrite(lmotorb,HIGH);///////me wheel eka passata kerakeddin anik wheel eka
        digitalWrite(rmotorb,LOW);     
        Serial.println("left");             
      }



void  irmForward()
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
    Serial.println("Forward");
    }

  void irmRight()
    
    {
      digitalWrite(lmotorf,HIGH);
      digitalWrite(rmotorf,LOW);

      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,HIGH);///////me wheel eka passata kerakeddin anik wheel eka
                                 //issarahata kerakena nisa RIGHT pattata harenawa
      Serial.println("Right");
      }

  
   void none ()
      {
        digitalWrite(lmotorf,LOW);
        digitalWrite(rmotorf,LOW);
        
        digitalWrite(lmotorb,LOW);
        digitalWrite(rmotorb,LOW);
        Serial.println("None");
        }

void setup() {
  // put your setup code here, to run once:
pinMode(lmotorf,OUTPUT);
pinMode(rmotorf,OUTPUT);
pinMode(lmotorb,OUTPUT);
pinMode(rmotorb,OUTPUT);

pinMode(32,INPUT);
pinMode(33,INPUT);
pinMode(34,INPUT);
pinMode(35,INPUT);
Serial.begin(9600);
 
}

//LOW-->white
//HIGH-->black

void loop() {
  // put your main code here, to run repeatedly:

  int l1sensor=digitalRead(32);
  int r1sensor=digitalRead(35);

  int l2sensor=digitalRead(33);
  int r2sensor=digitalRead(34);


/*  int l1sensor=6;
  int r1sensor=7;

  int l2sensor=5;
  int r2sensor=4;
*/    
      if((l1sensor==LOW)||(l2sensor==LOW))//both sensor on white//go forward
      {
         irmForward();
      }
      else if((r1sensor==LOW)||(r2sensor==LOW))//both sensor on white//go forward
      {
         irmForward();
      }
      else if((l1sensor==HIGH)||(l2sensor==HIGH))//RIGHT sensor in black line//turn RIGHT
      {
        irmRight();
        irmForward();
      }
       else if((r1sensor==HIGH)||(r2sensor==HIGH))     //LEFT sensor on black line//turn LEFT
     {
      irmLeft();
      irmForward();
     }
       else    //both sensor on white//go forward
      {
      irmForward();
     }

}


