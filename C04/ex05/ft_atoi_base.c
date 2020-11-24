#include <unistd.h>

int ft_atoi(char *str)
{
  int msb;
  int number;
  
  number = 0;
  msb = 1;
  if(*str == '-')
  {
    msb = -1;
    str++;
  }
  else if(*str == '+')
    str++;
  while(*str)
  {
    if(*str < '0' || *str >'9' )
      return (msb * number);
    number = 10 * number + (*str - '0');
    str++;
  }
  return (msb * number);
}

int rec(int nb, char *base, int len)
{
  int digit;
  
  if( nb == 0)
    return 0;
  rec(nb / 10);
  write(1, &base[nb % len], 1);
}
  
int ft_atoi_base  (char *str, char *base, int len)
{
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
    rec(-(nb / len), base , len);
    write(1, &base[nb % len], 1);
  }
  else
  {
    rec(nb / len, base, len);
    write(1, &base[nb % len], 1);
  }
}
