//Iterative Programming Implementation for very large values of n
//Refer README.txt to fetch more details 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	
	//Reading the value of n from a file
	FILE *fptr;
	char str[1002];
	char ch;
	int i=0, m, mctr, ctr;
	int a=0, b=1, c, k, len, d;
	
	scanf("%d", &m);
	mctr = m*m;
	
	
	fptr = fopen("input.txt", "r");
	if(fptr == NULL){
		printf("Cannot open File");
		exit(0);
	} else {
		ch = fgetc(fptr);
		while(ch != EOF){
			if(ch != 10){
				str[i] = ch;
				i++;
			}
			ch = fgetc(fptr);	
		}
		str[i] = '#';
		str[i+1] = '\0';
		i=0;
	}

	//Finding the periodic index
	while(i<mctr){
		c=(a+b)%m;
		a=b;
		b=c;
		if(c==0){
			if((a+b)%m == 1){
				k = i;
				break;
			}
		}
		i++;
	}
	k+=2;
	i=0;d=0;
	ctr = strlen(str);
	
	//Calculating n mod k	
	while(i<ctr){	
		d = d % k;
		if(str[i]=='#'){
			break;
		} else {
			d = d*10 + (str[i]-48);
		}
		i++;
		
	}	
	
	//Finding the perfect answer
	a=0;b=1;
	if(d==0){
		c = 0;
	} else if(d==1 || d==2){
		c = 1;
	} else {
		d -= 2;
		while(d>0){
			c=(a+b)%m;
			a=b;
			b=c;
			d--;
		}
	}

	printf("%d", c);
	return 0;
}
