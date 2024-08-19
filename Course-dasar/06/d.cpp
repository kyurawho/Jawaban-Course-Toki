#include <stdio.h>

int main(){
	int arr;
	int jumlah = 0;
	
	while(scanf("%d", &arr) != EOF){
		jumlah = jumlah + arr;
	}
	
	printf("%d \n", jumlah);
}
