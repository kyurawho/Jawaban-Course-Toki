#include <stdio.h>
#include <cmath>

int a, b;

int fungsi(int &x){
	int temp;
	temp = abs((a*x) + b);//fungsinya
	return temp;
}

int main(){
	int k, x;
	scanf("%d %d %d %d", &a, &b, &k, &x);
	for(int i=0; i<k; i++){
		x = fungsi(x);
	}
	printf("%d", x);
}
