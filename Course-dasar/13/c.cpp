#include <stdio.h>
#include <algorithm>
using namespace std;

int j = 1;
int low, high, anslow, anshigh;

int fungsi(int x){
	
}

int main(){
	int n;
	scanf("%d", &n);
	
	int arr[n];
	
	for(int i=0; i<n ;i++){
		arr[i] = j;
		j++;
	}
	
	for(int i=0; i<n ;i++){
		printf("%d", arr[i]);
	}
	
	if(n%2 == 0){
		return 0;
	}if(n == 1){
		return 0;
	}else{
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j){
					continue;
				}else{
					low = min(arr[i], arr[j]);
					anslow = min(anslow, low);
					high = max(arr[i], arr[j]);
					anshigh = max(anshigh, high);
				}
			}
		}
	}
	
	printf("\n%d %d", low, high);
	//fungsi(n);
}
