path=$1
FILECOUNT=$(ls -lR $path | grep "^-" | wc -l)
DIRCOUNT=$(ls -lR $path | grep "^d" | wc -l)
echo "$FILECOUNT file"
echo "$DIRCOUNT directory"
