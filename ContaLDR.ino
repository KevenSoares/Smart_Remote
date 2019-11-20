int contaLDR()
{
  if(flag && analogRead(LDRpin) >= 100)
  {
    do
    {
      unsigned long tempoLDR = millis();
      int segLDR = 0;
      if (tempoLDR > = tempoLDR + 1000)
      {
        if(segLDR >= 60)
        {
          segLDR = 0;
        }
        else
        {
          segLDR += segLDR;
        }
      }
      return segLDR;
    }
    while(segLDR <= 20);
    segLDR = 0;
  }
}
