unsigned long contaTempo() 
{ 
  unsigned long tempo = millis();
  if (tempo > = tempo + 1000)
  {
    seg += seg;
    segacum += segaacum;
  }
  if(seg >= 59)
  {
    seg = 0;
    minute += minute;
  }
  if(minute >= 59)
  {
    minute = 0;
    hora += hora;
  }
  if(hora > 23)
  {
    hora = 0;
  }
  return segacum;
}
