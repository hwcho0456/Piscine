<<<<<<< HEAD
ifconfig -a | tr -d '\t' | grep "ether " | sed 's/ether //' | tr -d ' '
=======
ifconfig -a | grep "ether"  | tr -d " " | sed "s/ether//g"
>>>>>>> 6a9ab7536b81ab64f9c9ee74b4af836fb3cedb2a
