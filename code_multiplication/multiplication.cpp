
#include "Halide.h"
#include <stdio.h>
#include <sys/time.h>
#include <inttypes.h>
using namespace Halide;



int main(int argc, char **argv) {


		 if(argc<=1) {

	     	   exit(1);
		     }  
	     int dim = atoi(argv[1]);
		int trace = atoi(argv[2]);


	Var x("x"), y("y") ;
	Func init_random_1 , init_random_2 ;

	init_random_1(x,y) = 0 ;

	init_random_2(x,y) = 0;


	RDom r1(0, dim,0,dim);
	init_random_1(r1.x,r1.y) = (r1.y + r1.x)%10 ;
	init_random_2(r1.x,r1.y) = (r1.x - r1.y)%5 ;


	Buffer<int> mat1 = init_random_1.realize(dim, dim);

	if(trace>0){// display mat1

	  for (int i = 0; i < mat1.width(); i++) {
		for (int j = 0; j < mat1.height(); j++) {
		    

		        printf("|%3d", mat1(i, j));

		}
		printf("\n");
    	}
	}
	printf("\n ===== \n");

	Buffer<int> mat2 = init_random_2.realize(dim, dim);

	if(trace>0){// display mat2
	  for (int i = 0; i < mat2.width(); i++) {
		for (int j = 0; j < mat2.height(); j++) {

		        printf("|%3d", mat2(i, j));


		}
		printf("\n");
    	}
	}
	printf("\n ===== \n");

	// save mult start time
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);

	// declare mult function

	Func matrix_multiplication ;
	matrix_multiplication(x,y) = 0 ;

	// multiplication's reduction
	RDom r(0, dim);
	matrix_multiplication(x,y) += mat1(x,r)*mat2(r,y) ;

	// parellel optimisation [opt]
	matrix_multiplication.parallel(x) ;

	//trace++
	if(trace==2){

		 matrix_multiplication.trace_stores();
	}


	Buffer<int> result = matrix_multiplication.realize(dim, dim);

	// get finish time + display
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

	if(trace>0){


	 for (int i = 0; i < result.width(); i++) {
		for (int j = 0; j < result.height(); j++) {

		        printf("|%3d", result(i, j));


		}
		printf("\n");
    	}
	}

	printf("duree d'execution de multiplication est %" PRIu64 " miliseconds\n", delta_us/1000 );







    return 0;
}
