#include <stdio.h>

void swap(int &a, int &b){
	int temp1 = a;
	int temp2 = b;
	b = temp1;
	a = temp2;
}

int main(){
	int n, t;
	scanf("%d", &n);
	
	int arr[2][n];
	
	for(int i=0; i < 2; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		char buff1[5], buff2[5];
		int x, y;
		scanf("%s %d %s %d", buff1, &x, buff2, &y);
		int p = buff1[0] - 'A';
		int q = buff2[0] - 'A';
		x--;
		y--;
		swap(arr[p][x],arr[q][y]);
	}
	
	for(int i=0; i < 2; i++){
		for(int j=0; j<n; j++){
			printf("%d", arr[i][j]);
			if(j+1<n){
				printf(" ");
			}
		}
		printf("\n");
	}
}
