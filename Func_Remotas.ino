void control(char data)
{
  switch(data){

    case 'w': // função de ligar o ar via IR
      //on
      lcd.setCursor(0,0);
      lcd.print("on");
      break;
     
    case 's': // função de desligar o ar via IR
      //off
      lcd.setCursor(0,0);
      lcd.print("  Ar Desligado  ");
      lcd.setCursor(0,1);
      lcd.print(" ON/OFF: START  ");
      break;
  }
}
