sh scripts/build.sh release 

rm -rf -d stick-rpg

mkdir stick-rpg

cp bin/release/stick-rpg stick-rpg
cp -r res stick-rpg

echo "Deploy build created."
echo "cd stick-rpg to find it"