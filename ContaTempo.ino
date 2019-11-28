int contaTempo() // função de contagem de tempo, dependente da função millis
{ 
  unsigned long tempo = millis();
  int segacum = 0; // variável que acumula valor em segundos do projeto
  int j = 1;
  while(j)
  {
    if(millis() - tempo >= 1000) // toda vez que um ciclo de 1000 milli segundos passar
    {
      tempo = millis();
        if(analogRead(A0) >= 800) // verifica o ldr
        {
           segLDR++;
        }
        else
        {
          segLDR = 0;
        }
        if(digitalRead(7) == LOW) // verifica o sensor de presença
        {
           segPIR++;
        }
        else
        {
          segPIR = 0;
        }
        if(digitalRead(8) == LOW) // verifica o botão ON/OFF
        {
         while(digitalRead(8) == LOW);
         flag = !flag;
        }
        segacum++; // incrementa o segundo
        printDisplay(); // imprime os valores de tempo no display
      
      return segacum; 
    }
 }
}
