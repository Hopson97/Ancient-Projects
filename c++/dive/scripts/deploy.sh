sh scripts/build.sh release 

rm -rf -d dive

mkdir dive

cp bin/release/dive dive
cp -r res dive

echo "Deploy build created."
echo "cd dive to find it"