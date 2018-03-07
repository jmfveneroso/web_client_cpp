#!/bin/bash -ev

cd libStatic

libtool -static libchilkat_x86_64.a libchilkat_i386.a -o libchilkat.a

cd ..

cd libDyn

lipo -create libchilkat_x86_64.dylib libchilkat_i386.dylib -output libchilkat.dylib

cd ..

