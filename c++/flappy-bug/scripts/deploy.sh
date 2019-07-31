sh scripts/build.sh release 

rm -rf -d flappy-bug

mkdir flappy-bug

cp bin/release/flappy-bug flappy-bug
cp -r res flappy-bug

echo "Deploy build created."
echo "cd flappy-bug to find it"