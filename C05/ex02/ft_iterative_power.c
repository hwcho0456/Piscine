int ft_itrative_power(int nb, int power)
{
  int result;
  
  result = 1;
  if (nb < 0)
    return (0);
  if (nb == 0 && power == 0)
    return (1)
  while(power > 0)
  {
    result *= nb;
    power--;
   }
  return (result);
}
