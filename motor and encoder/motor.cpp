#include "motor.hpp"

#include <Arduino.h>
//"INR1" means the first pin ofright motor

namespace motor{

Motor::Motor(int time)
{t = time;};

void Motor::ahead(int t)
{
    pinMode(IN_R1,HIGH);
    pinMode(IN_R2,LOW);
    pinMode(EA_R,HIGH);
    pinMode(IN_L1,HIGH);
    pinMode(IN_L2,LOW);
    pinMode(EA_L,HIGH);
}

void Motor::left(int t)
{ 
    pinMode(IN_R1,HIGH);
    pinMode(IN_R2,LOW);
    pinMode(EA_R,HIGH);
    pinMode(IN_L1,LOW);
    pinMode(IN_L2,HIGH);
    pinMode(EA_L,HIGH);
}

void Motor::right(int t)
{
    pinMode(IN_R1,LOW);
    pinMode(IN_R2,HIGH);
    pinMode(EA_R,HIGH);
    pinMode(IN_L1,LOW);
    pinMode(IN_L2,HIGH);
    pinMode(EA_L,HIGH);
}

void Motor::back(int t)
{
    pinMode(IN_R1,LOW);
    pinMode(IN_R2,HIGH);
    pinMode(EA_R,HIGH);
    pinMode(IN_L1,LOW);
    pinMode(IN_L2,HIGH);
    pinMode(EA_L,HIGH);
}

void Motor::stop(int t)
{
    pinMode(IN_R1,LOW);
    pinMode(IN_R2,LOW);
    pinMode(EA_R,LOW);
    pinMode(IN_L1,LOW);
    pinMode(IN_L2,LOW);
    pinMode(EA_L,LOW);
}
}