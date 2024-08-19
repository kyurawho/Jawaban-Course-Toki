#include <stdio.h>

int n, k;
int catat[1000];
bool pernah[1000];

void tulis (int kedalaman)
{
	if (kedalaman >= k){
		bool naik = true;
		for (int i = 0; i < k - 1; i++){
			if (catat[i] > catat[i + 1]) naik = false;
		}
		if (naik){
			for (int i = 0; i < k; i++){
				printf("%d", catat[i]);
				if (i < k) printf(" ");
			}
			printf("\n");
		}
	}else{
		for (int i = 1; i <= n; i++){
			if (!pernah[i]){
				pernah[i] = true;
				catat[kedalaman] = i;
				tulis(kedalaman + 1);
				pernah[i] = false;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	tulis(0);
}
