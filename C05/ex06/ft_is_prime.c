int ft_is_prime(int nb)
{
  int square;
  int a;
  int i;
  
  if (nb <= 1)
    return (0);
    
  square = 0;
  a = 1;
  i = 1;
  while(square <= nb)
  {
    square += (2 * a - 1);
    a++;
   }
   while(++i <= a)
   {
    if(nb%i == 0)
      return (0);
   }
   return (1);
}
