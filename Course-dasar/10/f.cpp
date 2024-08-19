#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n, d, anslow = 1e9, anshigh = -1e9;
	scanf("%d %d", &n, &d);
	int x[n], y[n];
	for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int temp1 = 1, temp2 = 1;
			for (int k = 0; k < d; k++) temp1 = temp1 * abs(x[j] - x[i]), temp2 = temp2 * abs(y[j] - y[i]);
			anslow = min(anslow, temp1 + temp2);
			anshigh = max(anshigh, temp1 + temp2);
		}
	}
	printf("%d %d", anslow, anshigh);
}
