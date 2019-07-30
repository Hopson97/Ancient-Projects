sh scripts/build.sh release 

rm -rf -d ftw-editor

mkdir ftw-editor
mkdir ftw-editor/Resources

cp bin/release/ftw-editor ftw-editor
cp -r Resources ftw-editor

echo "Deploy build created."
echo "cd ftw-editor to find it"