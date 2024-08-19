#include <stdio.h>

int main(){
	int n, high, low;
	scanf ("%d", &n);
	
	int arr[n];
	
	for(int i =1; i <= n; i++){
		scanf("%d", &arr[i]);
	}

	high = arr[1];
	for(int i=1; i <= n; i++){
		if(arr[i] > high){
			high = arr[i];
		}else{
			continue;
		}
	}
	
	low = arr[1];
	for(int i=1; i <= n; i++){
		if(arr[i] < low){
			low = arr[i];
		}else{
			continue;
		}
	}
	
	
	printf("%d ", high);
	printf("%d", low);
}
