#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXSIZE 1000
int main(int argc, char **argv)
{
	int myid, numprocs;
	int data[MAXSIZE], i, x, low, high, myresult=0, result=0;
	FILE *fp;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	if (myid == 0) {  /* Open input file and initialize data */
		if ((fp = fopen("rand.txt","r")) == NULL) {
			printf("Can't open the input file: rand.txt\n\n");
			exit(1);
		}
		for(i = 0; i < MAXSIZE; i++) fscanf(fp,"%d\n", &data[i]);
	}
	MPI_Bcast(data, MAXSIZE, MPI_INT, 0, MPI_COMM_WORLD); /* broadcast data */
	x = MAXSIZE/numprocs; /* Add my portion Of data */
	low = myid * x;
	high = low + x;
	for(i = low; i < high; i++)
		myresult += data[i];
	char hostname[30];
	gethostname(hostname, 30);
	printf("I got %d from %d - %s\n", myresult, myid, hostname); /* Compute global sum */
	MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (myid == 0) printf("The sum is %d.\n", result);
	MPI_Finalize();
	return 0;
}

