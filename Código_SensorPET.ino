#include <LiquidCrystal.h>
#define buz 10                   //pino do Buzzer
LiquidCrystal lcd(2,3,4,5,6,7);  //pinos do display
#define LedVermelho A3           //pino do led vermelho
#define LedAmarelo A2            //pino do led amarelo
#define LedVerde A1              //pino do led verde
#define LedAzul A0               //pino do led azul
#define gatilho 9                //pino do trigger do sensor ultrassonico
#define echo 8                   //pino do echo do sensor ultrassonico
float tempo;                     //variavel que armazena o tempo dos sinais do ultrassonico
float cm;                        //variavel usada para armazenar o valor em cm da distancia
int re=0;                        //variavel usada para controlar a frequencia do buzzer



void setup(){
	lcd.begin(16,2);
  	pinMode(LedVermelho, OUTPUT);
  	pinMode(LedAmarelo, OUTPUT);
  	pinMode(LedVerde, OUTPUT);
  	pinMode(LedAzul, OUTPUT);
	pinMode(gatilho,OUTPUT); 
	digitalWrite(gatilho,LOW);
	delay(10);
	pinMode(echo,INPUT);
	Serial.begin(9600);  
}

void ligarLED(int cm);              //funcao usada para controlar os leds que 
                                    //ligam de acordo com a distancia

void loop(){

	digitalWrite(gatilho, HIGH);
	delay(10);
	digitalWrite(gatilho, LOW);
  
	tempo = pulseIn(echo, HIGH);
	cm = tempo / 29.4 / 2;
  	ligarLED(cm);
  
  	if(cm<100){
    	re=cm-100;
    	re=re*-25;
    	//tone(buz,re,500);
      	delay(75);
  	}
  	else{noTone(buz);
        delay(75);
	}
	
	lcd.setCursor(5, 0);
	lcd.print(cm);
	lcd.print("Cm");
}

void ligarLED(int cm){
  	if(cm>=75 && cm<=100){
  		digitalWrite(LedVermelho, LOW);
      	digitalWrite(LedAmarelo, LOW);
      	digitalWrite(LedVerde, LOW);
      	digitalWrite(LedAzul, HIGH);
  	}
    else if(cm>=50 && cm<75){
  		digitalWrite(LedVermelho, LOW);
      	digitalWrite(LedAmarelo, LOW);
      	digitalWrite(LedVerde, HIGH);
      	digitalWrite(LedAzul, LOW);
  	}
    else if(cm>=25 && cm<50){
  		digitalWrite(LedVermelho, LOW);
      	digitalWrite(LedAmarelo, HIGH);
      	digitalWrite(LedVerde, LOW);
      	digitalWrite(LedAzul, LOW);
  	}
    else if(cm>=0 && cm<25){
  		digitalWrite(LedVermelho, HIGH);
      	digitalWrite(LedAmarelo, LOW);
      	digitalWrite(LedVerde, LOW);
      	digitalWrite(LedAzul, LOW);
    }else {
    	digitalWrite(LedVermelho, LOW);
      	digitalWrite(LedAmarelo, LOW);
      	digitalWrite(LedVerde, LOW);
      	digitalWrite(LedAzul, LOW);
    }
}
  	