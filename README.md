## halide_multiplication
highlights performance between c &amp; halide in matrix multiplication
## setup explanation
- to start we need to place our code folder in halide root dir
- ├── bin
- ├── code_multiplication // our code
- ├── halide.cmake
- ├── halide_config.cmake
- ├── halide_config.make
- ├── include
- ├── lib
- ├── README_cmake.md
- ├── README.md
- ├── README_rungen.md
- ├── README_webassembly.md
- ├── tools
- └── tutorial

## inside code_multiplication
- ├── app.sh
- ├── multi_c
- ├── multi_halide
- ├── multiplication.c
- └── multiplication.cpp

be sure to grant app.sh x right ( chmod )
### run ./app.sh
- then type your commande & follow description
- build : builds .c & .cpp into executables
- execute [dimention] : runs a matrix mutiplication
...

### my test :
for dim = 800 , i.e matrix size is 800*800 ; halide: 1075 miliseconds , c: 3731 ms ; 3x faster

