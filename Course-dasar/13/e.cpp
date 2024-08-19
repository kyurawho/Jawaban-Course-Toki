#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define pb push_back
#define pq priority_queue
#define mp make_pair
#define all(x) x.begin(), x.end()
#define Repp(i, l, r, a) for (int i = l; i < r; i += a)
#define Rep(i, l, r) Repp(i, l, r, 1)
#define For(i, n) Rep(i, 0, n)
#define Fori(i, n) Rep(i, 1, n + 1)
#define Each(x, v) for (auto x : v)
#define Repd(i, l, r) for (int i = r - 1; i >= l; i--)
#define Ford(i, n) Repd(i, 0, n)
#define endl "\n"

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

int m[128][128];
string ans[128 * 128];
int nans = 0;

bool homogen(int r, int c, int k){
	int val = m[r][c];
	//mengecek homogen atau tidak, jika iya, tidak akan ada pembelahan lagi
	for(int i = r; i < k + r; i++){
		for(int j = c; j < k + c; j++){
			if(m[i][j] != val) return false;
		}
	}
	return true;
}

void tree(int r, int c, int k, string s){
	if(homogen(r, c, k)){
		//mencari jawaban, kalau 1 berarti benar dan dihitung
		if(m[r][c] == 1){
			ans[nans] = '1' + s;
			nans++;
		}
	}else{
		//dibelah menjadi 4
		tree(r, c, k/2, s + '0');
		tree(r, c + (k / 2), k/2, s + '1');
		tree(r + (k / 2), c, k/2, s + '2');
		tree(r + (k / 2), c + (k / 2), k/2, s + '3');
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int r, c;
	cin >> r >> c;
	
	//menjadikan r c menjadi power of 2
	int pow = 1;
	while (pow < max(r,c)){
		pow *= 2;
	}
	
	//Inisiasi 0, jika input r c tidak power of 2, maka diperlebar dan angkanya 0
	For(i, pow){
		For(j, pow){
			m[i][j] = 0;
		}
	}
	
	//Inisiasi matrix dari input
	For(i, r){
		For(j, c){
			cin >> m[i][j];
		}
	}
	
	tree(0, 0, pow, "");
	
	cout << nans << endl;
	For(i, nans){
		cout << ans[i] << endl;
	}
}
