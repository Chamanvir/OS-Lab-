#include <stdio.h>

int main(){
	int A[1000000],i,sum=0;
	for (i=0;i<1000000;i++){
		A[i] = i;
	}
	for(i=0;i<1000000;i++){
		sum = sum + A[i];
	}
	printf("%d",sum);
}
