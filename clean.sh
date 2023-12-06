#!/bin/bash

clean_unix() {
	if [ -d "build" ]; then
		rm -rf build
	fi
}

clean_windows() {
	if [ -d "build" ]; then
		 rmdir /s /q build
	fi
}

case "$(uname -s)" in
	Linux*|Darwin*)
		clean_unix
		;;
	CYGWIN*|MINGW*|MSYS*)
		clean_windows
		;;
	*)
		echo "Unsupported operating system"
		exit 1
		;;
