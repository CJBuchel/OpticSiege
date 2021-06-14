#!/bin/sh
echo "Setting up project..."
echo "Using mac? [y/n]"

read usingMac

if [ "$usingMac" = "y" ]; then
	echo "Using mac..."
	sudo cp ../Premake/bin/premake5_mac /bin/premake5
else
	echo "Using linux (assumed ubuntu)..."
	sudo apt-get install libgl-dev
	sudo cp ../Premake/bin/premake5 /bin/premake5
fi

echo "Setting up premake5"

cd ../; git submodule update --init; git submodule update --remote -f; premake5 gmake2
echo "Trying first time build"
cd ./Solution/; make;