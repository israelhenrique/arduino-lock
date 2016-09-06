#include <Stepper.h> 
 
const int stepsPerRevolution = 500; 
const int ldrPin = 5;
const int ledPin = 13;
int ldrValor = 0;
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper myStepper(stepsPerRevolution, 8,10,9,11); 
  
void setup() 
{ 
 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(60);
 pinMode(ledPin,OUTPUT);
 Serial.begin(9600);
} 
  
void loop() 
{ 
 ldrValor = analogRead(ldrPin);
 Serial.println(ldrValor);
 if ( ldrValor < 820)
   myStepper.step(682); 
 delay(10); 
 
}
