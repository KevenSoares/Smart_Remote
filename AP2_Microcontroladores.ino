/* Avaliação Parcial 2
 *  Autores: Keven Soares, Mauricio Calheiro
 */
int onoff = 8, temp = 9, pir = 10, ir = 3, seg = 0, minute = 0, hora = 0, LDRpin = A0;
unsigned long segacum = 0;
unsigned long timeset = 0;
bool flag = false;

void setup() 
{
  pinMode(onoff,INPUT_PULLUP);
  pinMode(temp,INPUT_PULLUP);
  pinMode(pir,INPUT);
}

void loop()
{
  if(digitalRead(onoff) == LOW)
  {
    while(digitalRead(onoff) == LOW);
    flag = !flag;
    control('o');
  }
  while(flag == 1)
  {
    contaTempo();
    timeSet();
    if(contaPir() >= 20 || contaLDR() >= 20 || contaTempo() >= timeset || digitalRead(onoff) == LOW)
    {
      control('c');
      flag = false;
      segacum = 0;
    }
  }
}
