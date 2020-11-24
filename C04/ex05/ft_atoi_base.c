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
    nb = 
}
