void printDisplay()
{
        lcd.setCursor(11,0);
        lcd.print("QT:");
        lcd.setCursor(14,0);
        lcd.print(ArrumaZero(timeset));
        lcd.setCursor(0,1);
        lcd.print("TA:");
        lcd.setCursor(3,1);
        lcd.print(ArrumaZero(segacum));
        lcd.setCursor(6,1);
        lcd.print("LX:");
        lcd.setCursor(9,1);
        lcd.print(ArrumaZero(segLDR));
        lcd.setCursor(11,1);
        lcd.print("PR:");
        lcd.setCursor(14,1);
        lcd.print(ArrumaZero(segPIR));
}
