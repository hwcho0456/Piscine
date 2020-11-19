echo $FT_NBR1 + $FT_NBR2  | tr '\' 1 | tr '"' 2 | tr '?' 3 | tr '!' 4 | sed "s/'/0/g" | tr 'mrdoc' 01234 | xargs echo "obase=13; ibase=5; " | bc | tr 0123456789ABC 'gtaio luSnemf'
