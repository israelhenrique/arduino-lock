#include <Stepper.h> 
 
const int stepsPerRevolution = 500; 
const int ldrPin = 5;
const int buttonPin = 2;
int ldrValor = 0;
int stepperOn = 0;
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper myStepper(stepsPerRevolution, 8,10,9,11); 
 
int isOpen(int value){

  if (value > 820)
    return 0;
  else
    return 1;
}

void setup() 
{ 
 //Determina a velocidade inicial do motor 
 myStepper.setSpeed(60);
 pinMode(buttonPin,INPUT);
 Serial.begin(9600);
} 
  
void loop() 
{ 
 ldrValor = analogRead(ldrPin);
 Serial.println(ldrValor);
 int buttonValue = digitalRead(buttonPin);
 
 if(isOpen(ldrValor) && buttonValue == HIGH)
   stepperOn = 1;
 else if(!isOpen(ldrValor))
   stepperOn = 0;
 
 if (stepperOn)
   myStepper.step(682); 
 
 delay(10); 
 
}
