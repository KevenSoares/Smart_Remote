String ArrumaZero(int i) // função utilizada para formatação dos caracteres no display, de modo que um numero menor que 10 sempre seja completado com 0
{
  String ret;
  if (i < 10) ret += "0";
  ret += i;
  return ret;
}
