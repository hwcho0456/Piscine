cat /etc/passwd | sed '/#/d' | sed -n "n;p" | sed 's/:.*//' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr "\n" "," | sed 's/,$/./' | sed 's/, */, /g' | tr -d '\n' 
