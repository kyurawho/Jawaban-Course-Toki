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

int ma[75][75], mb[75][75], xa, xb, ya, yb;

bool identik(){
	For(i, xa){
		For(j, ya){
			if(ma[i][j] != mb[i][j]) return 0;
		}
	}
	return 1;
}

bool vertikal(){
	For(i, xa){
		For(j, ya){
			if(ma[i][j] != mb[i][ya - 1 - j]) return 0;
		}
	}
	return 1;
}

bool horizontal(){
	For(i, xa){
		For(j, ya){
			if(ma[i][j] != mb[xa - 1 - i][j]) return 0;
		}
	}
	return 1;
}

bool kananBawah(){
	For(i, xa){
		For(j, ya){
			if(ma[i][j] != mb[j][i]) return 0;
		}
	}
	return 1;
}

bool kiriBawah(){
	For(i, xa){
		For(j, ya){
			if(ma[i][j] != mb[xa - 1 - j][ya - 1 - i]) return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> xa >> ya;
	
	For(i, xa){
		For(j, ya){
			cin >> ma[i][j];
		}
	}
	
	cin >> xb >> yb;
	
	For(i, xb){
		For(j, yb){
			cin >> mb[i][j];
		}
	}
	
	if(xa != xb || ya != yb){
		cout << "tidak identik";
	}else{
		if(identik()) cout << "identik";
		else if(vertikal()) cout << "vertikal";
		else if(horizontal()) cout << "horisontal";
		else if(kananBawah()) cout << "diagonal kanan bawah";
		else if(kiriBawah()) cout << "diagonal kiri bawah";
		else cout << "tidak identik";
	}
}
