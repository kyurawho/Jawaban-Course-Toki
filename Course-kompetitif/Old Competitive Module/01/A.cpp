#include <iostream>
#include <string>
using namespace std;

void fungsi(int t)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	string search;
	cin >> search;
	
	string id[n];
	int temp1, temp2, temp3, score[80], tosearch;
	for (int i = 0; i < n; i++){
		cin >> id[i] >> temp1 >> temp2 >> temp3;
		score[i] = temp1 + temp2 * 1000 + temp3 * 10000000;
		if(search == id[i]){
			tosearch = score[i];
		}
	}
	
	for (int i = 1; i < 8; i++){
		for (int j = i; j > 0; j--){
			if(score[j] > score[j - 1]){
				int temp = score[j - 1];
				score[j - 1] = score[j];
				score[j] = temp;
			}
		}
	}
	
	bool passed = false;
	for(int i = 0; i < m; i++){
		if(tosearch == score[i]) passed = true;
	}
	
	if(passed) printf("YA\n");
	else printf("TIDAK\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) fungsi(t);
}
