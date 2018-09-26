#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

int sum1 = 0;
int sum2 = 0;
struct arguments{
	int A[1000000],mid;
};

void *compute_sum1(void *args){
	
	int i;
	struct arguments *arg1;
	arg1 = (struct arguments *)args;
	for (i=0;i<arg1->mid;i++){
		sum1 = sum1 + arg1->A[i];
	}
}

void *compute_sum2(void *args){
	
	int i;
	struct arguments *arg1;
	arg1 = (struct arguments *)args;
	for (i=arg1->mid;i<1000000;i++){
		sum2 = sum2 + arg1->A[i];
	}
}

int main(){

	pthread_t t1,t2;
	int A[1000000],i,rc;
	struct arguments *arg;
	arg = (struct arguments *)malloc(sizeof(struct arguments));
	for (i=0;i<1000000;i++){
		arg->A[i] = i;
	}
	arg->mid = 500000;
	rc = pthread_create(&t1,NULL,compute_sum1,arg);
	assert(rc==0);
	rc = pthread_create(&t2,NULL,compute_sum2,arg);
	assert(rc==0);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Sum of array is %d",sum1+sum2);
	return 1;
}
