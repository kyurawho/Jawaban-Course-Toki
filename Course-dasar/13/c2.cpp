#include <stdio.h>

int n, catat[1000001];
bool perna[1000005], zigzag;

void fungsi(int x){
	if( x >= n){
		zigzag = true;
		for(int i=1; i<n; i++){
			if(catat[i]>catat[i+1]){
				if(catat[i]>catat[i-1]){
					
				}else{
					zigzag = false;
				}
			}else if(catat[i]>catat[i+1]){
				if(catat[i]>catat[i-1]){
					
				}else{
					zigzag = false;
				}
			}
		}
		
		if(zigzag == true){
			for(int i=0; i<n; i++){
				printf("%d", catat[i]);
			}
			printf("\n");
		}
	}else{
		for(int i=1; i<n; i++){
			if(!perna[i]){
				perna[i] = true;
				catat[x] = i;
				fungsi(x + 1);
				perna[i] = false;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	fungsi(0);
}
