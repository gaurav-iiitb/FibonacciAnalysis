//Iterative Programming Implementation
//Refer README.txt to fetch more details 

#include<stdio.h>
int main(){

	int n, a=0, b=1, c, nctr;
	scanf("%d", &n);
	nctr = n-2;
	if(n==0){
		printf("0");
	} else if(n==1 || n==2){
		printf("1");
	} else {
		while(nctr>0){
			c=(a+b)%100;
			a=b;
			b=c;
			nctr--;
		}
		printf("%d", c);
	}	
	return 0;
}
