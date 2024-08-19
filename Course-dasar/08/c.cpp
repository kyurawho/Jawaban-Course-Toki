#include <stdio.h>
#include <cmath>
using namespace std;

void testprima(){
	int a, y;
	scanf("%d", &a);
	y = 1;
	
	if(a == 1){
		printf("YA\n");
		return;
	}
	
	for(int i=2; i <= trunc(sqrt(a)); i++){
		if(a%i == 0){
			y++;
		}
	}
	if(y > 2){
		printf("BUKAN\n");
	}else{
		printf("YA\n");
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	while(n--){
		testprima();
	}
}
