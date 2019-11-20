int contaLDR()
{
  do
  {
   if(flag && digitalRead(pir) == LOW)
   {
    unsigned long tempoPIR = millis();
    int segPIR = 0;
    if (tempoPIR > = tempoPIR + 1000)
    {
      if(segPIR >= 60)
      {
        segPIR = 0;
      }
      else
      {
        segPIR += segPIR;
      }
    }
    return segPIR;
   }
  }
  while(segPIR <= 20);
  segPIR = 0;
}
