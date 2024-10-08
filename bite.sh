#/usr/bin/bash
# oh i need to make it better

cd ./build/
echo "Meson compile"
if [ $(echo $?) != 0 ]; then
	echo "Compilation failed"
	exit
fi
cd ..
echo "clang compile"
clang $(pkg-config --cflags gtk4) -o ite main.c iteapp.c iteappwin.c ./build/ui-resources.c $(pkg-config --libs gtk4)
if [ $(echo $?) != 0 ]; then
	echo "Compilation failed"
	exit
fi
echo "execute binary"
./ite
