#!/bin/bash

clean_unix() {
	if [ -d "build" ]; then
		rm -rf build
	fi
}

clean_windows() {
	if exist "build" rmdir /s /q build
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
