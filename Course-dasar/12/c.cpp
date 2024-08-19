#include <stdio.h>
#include <cmath>

int a, b;

int fungsi(int x, int k){
	if(k == 0){
		return x;
	}else{
		return abs(a*fungsi(x, k-1) + b);
	}
}

int main(){
	int k, x;
	scanf("%d %d %d %d", &a, &b, &k, &x);
	
	printf("%d", fungsi(x, k));
}
