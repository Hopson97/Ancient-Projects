sh scripts/build.sh release 

rm -rf -d breakout

mkdir breakout
mkdir breakout/res

cp bin/release/breakout breakout
cp -r res breakout

echo "Deploy build created."
echo "cd breakout to find it"