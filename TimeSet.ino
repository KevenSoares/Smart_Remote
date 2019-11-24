void timeSet() // função chamada caso a interrupção do botão de TIME seja ativada
{
  while(digitalRead(2)== LOW); //debounce do botão
  if(timeset >= 6) // limitador de quantidade de tempo
   timeset = 2;
  else
   timeset++;
}
