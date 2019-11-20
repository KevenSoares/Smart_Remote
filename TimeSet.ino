unsigned long timeSet()
{
  int limitador = 0;
  timeset = 50;
  if(digitalRead(temp) == LOW)
  {
    while(digitalRead(temp) == LOW);
    limitador++;
    if(limitador <= 6)
    {
      timeset = timeset + 50;
      return timeset;
    }
  }
  else
  {
   return timeset;
  }
}
