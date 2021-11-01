// Mini Pumpkin led light
// Author: Pbaodoge
//Version : v0.3.5
//adjusting rgb led by using 5 buttons
//PINS: rgb led: 13, 12, 11
//buttons: button 10, 9, 8, 7, 6
//buzzer pin : 4


    //include Arduino.h only works on VS code platform IO
    //PLEASE REMOVE THIS IF YOU ARE USING ARDUINO IDE AND ALSO REPLACE .cpp as .ino file

    #include <Arduino.h>

#define rled 13
#define gled 12
#define bled 11
#define bz 4


#define rbutton 10
#define gbutton 9
#define bbutton 8

//buzzer button
#define bzbutton 7
#define pumpkinmode 6

    float a = 0;
    float b = 0;
    float c = 0;

    int counter = 0;


//change this if you wanted to increase the output brightness
const int interval = 7;

void rgbled(int r, int g, int b){
  //value from 0 to 255 driven by analogWrite function
  analogWrite(rled, r);
  analogWrite(gled, g);
  analogWrite(bled, b);

}


void setup() {
       //pins declarations

       pinMode(rled, OUTPUT);
       pinMode(gled, OUTPUT);
       pinMode(bled, OUTPUT);
       
       pinMode(rbutton, INPUT_PULLUP);
       pinMode(gbutton, INPUT_PULLUP);
       pinMode(bbutton, INPUT_PULLUP);
       pinMode(bzbutton, INPUT_PULLUP);
       pinMode(pumpkinmode, INPUT_PULLUP);
       Serial.begin(9600);
    
}

void loop() {
       

      int bState1 = digitalRead(rbutton);
      int bState2 = digitalRead(gbutton);
      int bState3 = digitalRead(bbutton);

      int bState4 = digitalRead(bzbutton);
      int bState5 = digitalRead(pumpkinmode);
     //reading state
     if(bState5 == LOW){

       counter = counter + 1;
       delay(300);


     }

          if(counter == 0){

            rgbled(a, b, c);

          }

     else if(counter == 1){
        rgbled(255, 120, 0); //yellow mode

     }

     else if(counter == 2){
       rgbled(255, 255, 255); //white mode

     }

     else if(counter == 3){
       rgbled(0, 255, 255); //cyan mode

     }

     //limit
     else if(counter >= 4){
    //return to 0
       counter = 0;

     }

     if(bState1 == 0){

        a = a + interval;
        rgbled(a, b, c);
            delay(1);

          if(a > 255){
          a = 0;
          rgbled(a, b, c);
        }
     }

     if(bState2 == 0){

       b = b + interval;
       rgbled(a, b, c);
           delay(1);

          if(b > 255){
          b = 0;
          rgbled(a, b, c);
        }
     }
   
    if(bState3 == 0){

      c = c + interval;
      rgbled(a, b, c);
          delay(1);

          if(c > 255){
          c = 0;
          rgbled(a, b, c);
        }
    }

    if(bState4 == 0){

        tone(bz, 1000, 500);

    }

    else{

      tone(bz, 1, 100);

    }
       //for testing
       Serial.println(a); //display a value
       Serial.println(b); //display b value
       Serial.println(c); //display c value

    delay(20);

}
