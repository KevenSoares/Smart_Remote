/* Avaliação Parcial 2
 *  Autores:Ester de Carvalho,Igor Benayon, Keven Soares, Mauricio Calheiro, Monique Silva, Renan Castiel 
 */
/*
 * Inclusão de bibliotecas necessárias para a implementação do projeto
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

IRsend irsend;

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE); // Foi utilizado um display LCD I2C

int segLDR = 0, segPIR = 0;


short timeset = 2;           // variável que acumula quantidade de tempos de aula que o ar permanece ligado
bool flag = false;         // variável que guarda o estado de ativação do ar

void(* resetFunc) (void) = 0; // função de software reset do arduino

void setup() // inicializações do sistema
{
  pinMode(8,INPUT_PULLUP); // inicialização do botão de ON/OFF
  
  pinMode(2,INPUT_PULLUP);     // o botão de incrementar quantidade de tempo foi feito via interrupção
  attachInterrupt(digitalPinToInterrupt(2), timeSet, LOW);
  
  pinMode(7,INPUT);           //Sensor de presença
  
  lcd.begin (16,2);           //Inicialização do LCD
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("  Init System   ");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("    Bem Vindo   ");
  lcd.setCursor(0,0);
  lcd.print(" ON/OFF: START  ");
  lcd.setCursor(0,1);
  lcd.print(" TIME: Inc Time ");
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(8) == LOW)       // caso o botão de ON/OFF seja pressionado
  {
    while(digitalRead(8) == LOW); //debounce do botão
    flag = !flag;                     //inverte e flag 
    control('w');                     // comando de ligar o ar
  }
  while(flag)                        // enquanto ele estiver ligado
  {
    lcd.setCursor(0,0);
    lcd.print("Ar Ligado  ");
    contaTempo(); // chama a função de contagem de tempo
    if(contaTempo() >= timeset*50 || digitalRead(8) == LOW|| segPIR >=20 || segLDR >= 20 || flag == false) // e verifica os tempos de aula, os tempos de sensor de presença, LDR ou se o botao ON/OFF foi pressionado novamente
    {
      Serial.print("off");
      control('s'); // caso alguma das condições seja atendida, manda o comando de desliga
      delay(1000);
      flag = false;
      resetFunc();  // e reinicia o arduino
    }
  }
}
