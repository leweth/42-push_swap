# Duplicates Test

args=""

for ((i=6; i<=200; i++))
do
	args+="\" $i\""
	args+=" "
done

args+=" \"-217483647\""
# args+="\" 10\""

echo $args

./push_swap $args
