#!/bin/sh
SRC="main.cpp detectObject.cpp preprocessFace.cpp recognition.cpp ImageUtils_0.7.cpp"
BIN=WebcamFaceRec
g++ `pkg-config opencv --cflags` $SRC -o $BIN.exe `pkg-config opencv --libs`

