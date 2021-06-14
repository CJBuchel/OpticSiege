#!/bin/bash

CONFIG_FILE=./conf_run.sh

if test -f "$CONFIG_FILE"; then
	echo "Running output"

	while IFS= read -r line; do
		./build/bin/$line/$1/$1
	done < $CONFIG_FILE

else
	echo "Config file does not exist, creating now"
	read -p "Linux? [y/n]: " os
	read -p "Debug mode? [y/n]: " mode
	read -p "32 bit? [y/n]: " arch

	# Mode type
	if [ "$mode" == "y" ]; then
		MODE_TYPE="Debug-"
	else
		MODE_TYPE="Release-"
	fi

	# OS type
	if [ "$os" == "y" ]; then
		OS_TYPE="linux-"
	else
		OS_TYPE="macosx-"
	fi

	# ARCH type
	if [ "$arch" == "y" ]; then
		ARCH_TYPE="x86_32"
	else
		ARCH_TYPE="x86_64"
	fi

	CONFIG="$MODE_TYPE$OS_TYPE$ARCH_TYPE"
	echo "Config Determined"
	echo "PROJECT=$1" >> $CONFIG_FILE
	echo $CONFIG > $CONFIG_FILE

	while IFS= read -r line; do
		./build/bin/$line/$1/$1
	done < $CONFIG_FILE
fi