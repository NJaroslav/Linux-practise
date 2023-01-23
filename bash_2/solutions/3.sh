out=$(cut -d ':' -f 1 /etc/passwd | tr '\n' ',')
length=${#out}
last_index=$(expr $length - 1)
form_out=${out:0:$last_index}
echo -e "$form_out\n"
