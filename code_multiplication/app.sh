echo ============ halide_test app 2 matrix multiplication ==== functions:
echo
echo -- build : builds both halide and .c version 
echo -- execute [dimention] : executes both + shows multiplication\'s times  
echo -- execute_trace [dimention] : execute both + shows used matrix 
echo -- execute_trace++ [dimention] : same + multiplication trace
echo --
echo -- reset clears screan
echo -- exit 

echo
read var var2 
echo $var

while [ $var != 'exit' ]
do
	
	if [ $var = 'build' ]
	then 
		g++ multiplication.cpp -g -I ../include -L ../bin -lHalide -lpthread -ldl -o multi_halide -std=c++11
		 gcc multiplication.c -o multi_c


		echo halibe built + .c built

	fi
	if [ $var = 'execute' ]
	then 
		echo -- halide execution :
		echo
		LD_LIBRARY_PATH=../bin ./multi_halide $var2 0
		echo  -- c execution :
		./multi_c $var2 0

	fi
	if [ $var = 'execute_trace' ]
	then 
		echo -- halide execution :
		echo 
		LD_LIBRARY_PATH=../bin ./multi_halide $var2 1
		echo -- c execution :
		./multi_c $var2 1
	fi
	if [ $var = 'execute_trace++' ]
	then 
		echo -- halide execution :
		echo 
		LD_LIBRARY_PATH=../bin ./multi_halide $var2 2
		echo -- c execution :
		./multi_c $var2 0
	fi
	if [ $var = 'reset' ]
	then 
		clear
		echo ============ halide_test app 2 matrix multiplication ==== functions:
		echo
		echo -- build : builds both halide and .c version 
		echo -- execute [dimention] : executes both + shows multiplication\'s times  
		echo -- execute_trace [dimention] : execute both + shows used matrix + halide_trace
		echo --
		echo -- reset clears screan
		echo -- exit 
		
	fi
echo
read var var2 
done