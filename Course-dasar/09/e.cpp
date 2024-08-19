#include <stdio.h>

int main(){
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	
	int arr1[n][m], arr2[m][p], arr3[n][p];
	
	for(int i=0; i < n; i++){
		for(int j=0; j < m; j++){
			scanf("%d", &arr1[i][j]);
		}
	}
	
	for(int i=0; i < m; i++){
		for(int j=0; j < p; j++){
			scanf("%d", &arr2[i][j]);
		}
	}
	
	for(int i=0; i < n; i++){
		int r = 0;
		for(int j=0; j<p; j++){
			for(int k=0; k<m; k++){
				r += arr1[i][k] * arr2[k][j];
			}
			printf("%d ", r);
			r = 0;
		}
		printf("\n");
	}
}
