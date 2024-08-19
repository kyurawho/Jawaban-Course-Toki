#include <stdio.h>
using namespace std;

int main(){
	int n, b;
	scanf("%d %d", &n, &b);
	
	for (int i=1; i <= n; i++){
		if(i%b == 0){
			printf("*");
		}else{
			printf("%d", i);
		}
		if (i == n){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}
