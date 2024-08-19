#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int FPB(int a, int b){
	if(b == 0) return a;
	else return FPB(b, a % b);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	int kpk;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 1){
			kpk = (a[i] * a[i - 1]) / FPB(a[i], a[i - 1]);
		}else{
			kpk = (kpk * a[i]) / FPB(kpk, a[i]);
		}
	}
	cout << kpk << endl;
}
