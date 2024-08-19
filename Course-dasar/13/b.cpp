#include <stdio.h>

void gunung(int x){
	for(int i=1; i<=x; i++){
		printf("*");
	}
	printf("\n");
}

void naik(int n){
	if(n==1){
		gunung(1);
	}else{
		naik(n-1);
		gunung(n);
		naik(n-1);
	}
}

int main(){
	int x;
	scanf("%d", &x);
	naik(x);
}
