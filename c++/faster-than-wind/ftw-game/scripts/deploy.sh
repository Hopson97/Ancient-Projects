sh scripts/build.sh release 

rm -rf -d ftw-game

mkdir ftw-game
mkdir ftw-game/Resources

cp bin/release/ftw-game ftw-game
cp -r Resources ftw-game

echo "Deploy build created."
echo "cd ftw-game to find it"