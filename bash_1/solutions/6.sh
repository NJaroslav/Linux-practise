n=$1
if ((n == 0)); then
    exit 1
fi
if ((n == 1)); then
    exit 1
fi
i=2
while ((i*i<=n)) ; do
    if ((n%i==0)); then 
        exit 1
    fi
((i++))
done
exit 0
