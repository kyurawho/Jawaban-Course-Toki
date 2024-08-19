#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	int b, c, y;
	scanf("%d", &b);
	int a[b];
	c = 0;
	
	for(int j = 0; j < b; j++){
		scanf("%d", &a[j]);
	}
	
	while(true){
		for(int i=2; i <= trunc(sqrt(a[c])); i++){
			if(a[c]%i == 0){
				y = 1;
			}
		}
		if(y || a[c] == 1){
			y = 0;
			printf("BUKAN\n");
		}else{
			printf("YA\n");
		}
		c++;
		if(c == b){
			break;
		}
	}
}
