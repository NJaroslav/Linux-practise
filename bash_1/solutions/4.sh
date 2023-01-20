c=1 
for arg in $@; do
    echo "arg #$c: $arg"
    c=$(($c+1))
done 
