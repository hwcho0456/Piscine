ifconfig -a | tr -d '\t' | grep "ether " | sed 's/ether //' | tr -d ' '
