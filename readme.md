# physicsSim
This is a simple OpenGL C++ project to develop a graphics and physics library to create accurate simulations

I havent used a .gitignore so that all libraries come with the application in the libs folder. Im probably breaking some license for one of these but oh well.

## Compiling
To make your makefile using mingw in the main folder run
cmake -B build -S . -G "MinGW Makefiles"
once complete cd into the build dir and run
mingw32-make 
or 
make
whatever you have installed
This will generate a .exe for you in the build folder
If thats to much work and your on windows you could also just type build and run respectively, I have simple scripts.
