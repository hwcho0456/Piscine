ifconfig -a | grep "ether"  | tr -d " " | sed "s/ether//g"
