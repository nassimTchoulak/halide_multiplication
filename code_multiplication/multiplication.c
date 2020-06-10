#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <time.h>   // clock_gettime, CLOCK_REALTIME
#include <unistd.h>


int main(int argc, char **argv) {


		 if(argc<=1) {

	     	   exit(1);
		     }
	     int dim = atoi(argv[1]);
		int trace = atoi(argv[2]);


    int mat1[dim][dim], mat2[dim][dim];
    int result[dim][dim];

    int i,j,k;
	for(i = 0; i < dim; ++i) {
        for ( j = 0; j < dim; ++j) {
            result[i][j] = 0;
		mat1[i][j] = rand()%4;
		mat2[i][j] = rand()%4;
        }
    }


	if(trace>0){// display mat1

	  for ( i = 0; i < dim; i++) {
		for ( j = 0; j < dim; j++) {

		        printf("|%3d", mat1[i][j]);

		}
		printf("\n");
    	}
	}
	printf("\n=========\n");

	if(trace>0){// display mat1

	  for ( i = 0; i < dim; i++) {
		for ( j = 0; j < dim; j++) {

		        printf("|%3d", mat2[i][j]);

		}
		printf("\n");
    	}
	}


	printf("\n=========\n");

	// time start
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);


	for ( i = 0; i < dim; ++i) {
        for ( j = 0; j < dim; ++j) {
            for ( k = 0; k < dim; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    	}


	clock_gettime(CLOCK_MONOTONIC_RAW, &end);

	uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;



	if(trace>0){
		  for ( i = 0; i < dim; i++) {
		for ( j = 0; j < dim; j++) {

		        printf("|%3d", result[i][j]);

		}
		printf("\n");
    	}
	}

		printf("duree d'execution de multiplication est %" PRIu64 " miliseconds\n", delta_us/1000 );





    return 0;
}


