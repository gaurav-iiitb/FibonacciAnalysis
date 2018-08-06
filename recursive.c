//Recursive Programming Implementation
//Refer README.txt to fetch more details 

#include<stdio.h>
int fibo(int n){
	if(n==0){
		return 0;
	}
	else if(n==1 || n==2){
		return 1;
	} else {
		return (fibo(n-1)+fibo(n-2))%100;
	}
}
int main() {

	int n;
	printf("Enter n\n");
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;	
}

