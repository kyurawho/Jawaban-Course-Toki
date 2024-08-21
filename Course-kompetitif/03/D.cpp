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

int n;
int a[100001];

int bins(int z){
	int l = 0, r = n - 1;
	while(l <= r){
		int m = (r + l) / 2;
		
		if(a[m] <= z){
			l = m + 1;
			if(l > n - 1) return l;
			if(a[l] > z){
				return l;
			}
		}else if(a[m] > z){
			r = m - 1;
			if(r < 0) return 0;
			if(a[r] < z){
				return r + 1;
			}
		}
	}
	return -1;
}

void solve(){
	int x, y; cin >> x >> y;
	cout << bins(y) - bins(x) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	For(i, n) cin >> a[i];
	
	int q; cin >> q;
	
	while(q--){
		solve();
	}
}
