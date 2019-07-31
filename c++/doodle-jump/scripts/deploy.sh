sh scripts/build.sh release 

rm -rf -d doodle-jump

mkdir doodle-jump

cp bin/release/doodle-jump doodle-jump
cp -r Data doodle-jump

echo "Deploy build created."
echo "cd doodle-jump to find it"
