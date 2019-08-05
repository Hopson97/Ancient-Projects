sh scripts/build.sh release 

rm -rf -d city-game

mkdir city-game

cp bin/release/city-game city-game
cp -r Data city-game

echo "Deploy build created."
echo "cd city-game to find it"