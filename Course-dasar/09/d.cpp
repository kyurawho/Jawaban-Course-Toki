#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[101][101];
	
	for(int i = 0; i < n; i++){
		for(int j=0; j < m; j++){
			scanf("%d", &arr[i][j]);
		}	
	}
	
	for(int i = 0; i < n; i++){
		for(int j=n-1; j >= 0; j--){//program enter dan space
			if(j < n-1){
				printf(" ");
			}else{
				printf("\n");
			}
			printf("%d", arr[j][i]);//pahami aja sendiri, pusing gw njelasinnya
		}
	}
}
