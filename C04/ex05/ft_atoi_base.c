#include <unistd.h>

int ft_atoi(char *str)
{
  int msb;
  
  msb = 1;
  if(*str == '-')
  {
    msb = -1;
    str++;
  }
  else if(*str == '+')
    str++;
  
}




int ft_atoi_base  (char *str, char *base)
{
  int len;
  int i;
  int nb;
  
  nb = ft_atoi(str);
  while(*(base+len))
  {
    while(*(base+len+i))
    {
      if(*(base+len) == *(base+len+i) || *(base +len+i) == ('+' || '-'))
        return 0;
      i++;
    }
    len++;
  }
  if(nb<0)
  {
    rec(-(nb / len));
    write(1, &base[nb % len], 1);
  }
  else
  {
    rec(nb / len);
    write(1, &base[nb % len], 1);
  }
}