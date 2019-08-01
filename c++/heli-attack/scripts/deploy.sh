sh scripts/build.sh release 

rm -rf -d heli-attack

mkdir heli-attack

cp bin/release/heli-attack heli-attack
cp -r Res heli-attack

echo "Deploy build created."
echo "cd heli-attack to find it"