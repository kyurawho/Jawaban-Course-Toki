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

int r, c, res;
char a[128][128];
bool temp;

void solve(){
	res = -1;
	For(i, r){
		temp = 0;
		if(a[i][0] == '1'){
			temp = 1;
			for(int j = 1; j < c; j++){
				if(a[i][j] == '0'){
					temp = 0;
					break;
				}
			}
		}
		
		if(temp){
			For(j, c){
				a[i][j] = '0';
			}
			res = i;
		}
	}
	
	temp = 0;
	
	if(res != -1){
		for(int i = res - 1; i >= 0; i--){
			for(int j = 0; j < c; j++){
				int l = i;
				if(a[l][j] == '1'){
					while(l <= r && a[l + 1][j] == '0'){
						swap(a[l][j], a[l + 1][j]);
						l++;
						temp = 1;
					}
				}
			}
		}
		if(temp) solve();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> r >> c;
	For(i, r){
		For(j, c){
			cin >> a[i][j];
		}
	}
	
	solve();
	
	For(i, r){
		For(j, c){
			cout << a[i][j];
		}
		cout << endl;
	}
}
