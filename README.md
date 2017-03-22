# qCw

[![Build Status](https://travis-ci.org/sardylan/qcw.svg?branch=master)](https://travis-ci.org/sardylan/qcw)

qCw is a simple tool to help learning [Morse Code](https://en.wikipedia.org/wiki/Morse_code).

The software simply draws the manipulation timing in a continuous line which represent "dots" and "dashes" using a custom OpenGL widget for drawing and an Arduino with a custom sketch (shipped in source code) connected to the PC to read the on/off contact of the key.

It's based on the Qt/C++ cross-platform framework and can be built using cmake in Linux, Mac and Windows with gcc, clang or Visual Studio.

Windows build are created using the official releases of Qt 5.8.0 for VS 2015 (both 32 and 64bit) and Visual Studio Community 2015 edition.

Windows users must install **Visual C++ Redistributable for Visual Studio 2015** of the same architecture to use this software. The correct installation package can be installed using the one which is already shipped with ZIP release (English language), or can be downloaded from the official Microsoft website.

