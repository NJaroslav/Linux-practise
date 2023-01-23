ASCIIToWide="ASCIIToWide"
UTF8ToWide="UTF8ToWide"
Utf16StringFor="Utf16StringFor"

files=$(find . -type f \( -name "*.cpp" -o -name "*.h" \))

for file in $files; do
  sed -i "" "s/$ASCIIToWide(\"\(.*\)\");/u\"\1\";/g" $file
  sed -i "" "s/$UTF8ToWide(\"\(.*\)\");/u\"\1\";/g" $file
  sed -i "" "s/$Utf16StringFor(\"\(.*\)\");/u\"\1\";/g" $file
done
