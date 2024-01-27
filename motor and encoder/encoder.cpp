# include "encoder.hpp"
# include <Arduino.h>

void Encoder::start(){
    encoderCounter = 0;
    int valA=0;
    float speed;
    int flag=0,pwm;
    Serial.begin (115200);  
    pinMode (encoderPinA, INPUT);   
    pinMode (encoderPinB, INPUT);
    attachInterrupt (digitalPinToInterrupt(encoderPinA), doEncoderA, CHANGE);
    attachInterrupt (digitalPinToInterrupt(encoderPinB), doEncoderB, CHANGE);
    attachInterrupt(0,timer,RISING); //"o" reffer to Pin 2,"1" reffer to Pin3
    starttime=millis();
    Serial.println(starttime); //they can be put into setup()
}

void Encoder::doEncoderA(){
    if (digitalRead(encoderPinA) == HIGH) {   
	    // check channel B to see which way encoder is turning  
	    if (digitalRead(encoderPinB) == LOW) {    
	      encoderCounter = encoderCounter + 1;         // CW  
	    }   
	    else {  
	      encoderCounter = encoderCounter - 1;         // CCW  
	    }  
	  }  
	  else                                            
	  {   
	    // check channel B to see which way encoder is turning    
	    if (digitalRead(encoderPinB) == HIGH) {     
	      encoderCounter = encoderCounter + 1;          // CW  
	    }   
	    else {  
	      encoderCounter = encoderCounter - 1;          // CCW  
	    }  
	  }  
	  //Serial.println (encoder0Pos, DEC);            
	  //this is test.
}
void Encoder::doEncoderB(){
    if (digitalRead(encoderPinB) == HIGH) {   
	    // check channel A to see which way encoder is turning  
	    if (digitalRead(encoderPinA) == LOW) {    
	      encoderCounter = encoderCounter + 1;         // CW  
	    }   
	    else {  
	      encoderCounter = encoderCounter - 1;         // CCW  
	    }  
	  }  
	  else                                            
	  {   
	    // check channel A to see which way encoder is turning    
	    if (digitalRead(encoderPinA) == HIGH) {     
	      encoderCounter = encoderCounter + 1;          // CW  
	    }   
	    else {  
	      encoderCounter = encoderCounter - 1;          // CCW  
	    }  
	  }  
	  //Serial.println (encoder0Pos, DEC);            
	  //this is test.
}
void Encoder::output_position(){
    double angle = encoderCounter*360/172032.0;//ppr=172032  
    Serial.print("angle = ");
    Serial,print(angle,2);
}
void Encoder::output_velocity(){
    if(flag==1)        
    { 
      speed=valA;
      Serial.print("pwn = "); //only out put pwm
      Serial.println(speed,3);
      valA=0;
      flag=0;
    }
}

void Encoder::timer(){
  valA++;
  stoptime=millis(); 
   if((stoptime-starttime)>100) //get speed every 100ms
   { 
    detachInterrupt(0); //turn off interrupt
    flag=1;
   }
}