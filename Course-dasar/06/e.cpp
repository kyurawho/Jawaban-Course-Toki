#include <cstdio>

int main(){
	double n;
	scanf("%lf", &n);
	
	while(true){
		if(n == 2 || n == 1){
			printf("ya");
			break;
		}else if(n < 2){
			printf("bukan");
			break;
		}
		n /= 2;
	}
}
