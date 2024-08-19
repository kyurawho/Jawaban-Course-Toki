#include <stdio.h>

int main(){
	int arr[100];
	int a = 0;
	
	while(scanf("%d", &arr[a]) != EOF){
		a++;
	}
	for(int b = a-1; b >=0; b--){
		printf("%d\n", arr[b]);
	}
}
