//Dynamic Programming Implementation
//Refer README.txt to fetch more details 
#include<stdio.h>
int main(){

	int n, i;
	int F[100000];
	scanf("%d", &n);
	F[0]=0;F[1]=1;
	for(i=2; i<n; i++){
		F[i] = (F[i-1] + F[i-2])%100;
	}
	printf("%d", F[n-1]);
	return 0;
}
