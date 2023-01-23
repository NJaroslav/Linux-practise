while read line; do    
    if [[ $line =~ ^https://|http://.* ]]; then
        echo $line
    else 
        echo http://$line
    fi
done
