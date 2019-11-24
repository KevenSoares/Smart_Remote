void control(char data)
{
  switch(data){

    case 'w': // função de ligar o ar via IR
      //on
      lcd.setCursor(0,0);
      lcd.print("    Ligando Ar  ");
      for(int i = 0; i <=2; i++)
      {
        int khz = 38; // 38kHz carrier frequency for the NEC protocol
        unsigned int irSignal[] = {9072,4544, 528,568, 528,568, 528,544, 556,1636, 552,568, 528,572, 528,568, 528,568, 528,1664, 528,568, 548,548, 528,1636, 576,1644, 528,568, 528,568, 528,568, 528,1664, 528,568, 528,568, 528,1664, 528,568, 528,568, 528,568, 528,568, 528,568, 528,544, 576,544, 552,548, 528,1660, 528,572, 528,568, 528,568, 528,544, 552,568, 528,1664, 528,1640, 552,568, 528,568, 532,564, 528,568, 544};
        irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
        delay(2000);
      }
      break;
     
    case 's': // função de desligar o ar via IR
      //off
      lcd.setCursor(0,0);
      lcd.print(" Desligando Ar  ");
      for(int i = 0; i <= 2; i++)
      {
        int khz2 = 38; // 38kHz carrier frequency for the NEC protocol
        unsigned int irSignal2[] = {9064,4532, 576,544, 532,540, 576,548, 528,568, 528,568, 532,564, 528,568, 536,564, 532,1660, 528,544, 576,544, 548,1648, 528,1664, 528,568, 528,568, 528,568, 528,1668, 528,568, 528,568, 552,1640, 528,568, 528,568, 532,568, 528,568, 532,564, 528,568, 532,564, 528,568, 528,1668, 528,568, 528,568, 548,552, 548,524, 564,532, 576,1640, 528,1644, 556,564, 528,568, 528,544, 576,544, 540};
        irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), khz2); //Note the approach used to automatically calculate the size of the array.
        delay(2000);
      }
      break;
  }
}
