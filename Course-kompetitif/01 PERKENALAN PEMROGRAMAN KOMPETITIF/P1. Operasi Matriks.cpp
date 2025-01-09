#include<iostream>
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

int n, m, x;

void h(int ma[105][105]){
	For(i, n / 2){
		For(j, m){
			swap(ma[i][j], ma[n - 1 - i][j]);
		}
	}
}

void v(int ma[105][105]){
	For(i, n){
		For(j, m / 2){
			swap(ma[i][j], ma[i][m - 1 - j]);
		}
	}
}

void r90(int ma[105][105]){
	int temp[105][105];
	For(i, n){
		For(j, m){
			temp[j][n - 1 - i] = ma[i][j];
		}
	}
	swap(n, m);
	For(i, n){
		For(j, m){
			ma[i][j] = temp[i][j];
		}
	}
}

void r180(int ma[105][105]){
	r90(ma);
	r90(ma);
}

void r270(int ma[105][105]){
	r90(ma);
	r90(ma);
	r90(ma);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;
	
	int ma[105][105];
	For(i, n){
		For(j, m){
			cin >> ma[i][j];
		}
	}
	
	string op;
	For(i, x){
		cin >> op;
		if(op == "_") h(ma);
		if(op == "|") v(ma);
		if(op == "90") r90(ma);
		if(op == "180") r180(ma);
		if(op == "270") r270(ma);
	}
	
	
	For(i, n){
		For(j, m){
			cout << ma[i][j] << ' ';
		}
		cout << endl;
	}
}
