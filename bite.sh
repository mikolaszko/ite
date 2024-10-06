#/usr/bin/bash
# oh i need to make it better

cd ./build/
echo "Meson compile"
meson compile
cd ..
echo "clang compile"
clang $(pkg-config --cflags gtk4) -o ite ite.c $(pkg-config --libs gtk4)
echo "execute binary"
./ite
