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

void decode(int r, int c, int k, string s){
	if(s.size() == 1 && s[0] == '1'){
		for(int i = r; i < r + k; i++){
			for(int j = c; j < c + k; j++){
				m[i][j] = 1;
			}
		}
	}else{
		if(s[1] == '0') decode(r, c, k / 2, s.erase(1,1));
		else if(s[1] == '1') decode(r, c + (k / 2), k / 2, s.erase(1,1));
		else if(s[1] == '2') decode(r + (k / 2), c, k / 2, s.erase(1,1));
		else if(s[1] == '3') decode(r + (k / 2), c + (k / 2), k / 2, s.erase(1,1));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	string a[n];
	For(i, n){
		cin >> a[i];
	}
	
	int r, c;
	cin >> r >> c;
	
	int pow = 1;
	while(pow < max(r,c)){
		pow *= 2;
	}

	For(i, pow){
		For(j, pow){
			m[i][j] = 0;
		}
	}
	
	For(i, n){
		decode(0, 0, pow, a[i]);
	}

	For(i, r){
		For(j, c){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
