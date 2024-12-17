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

ll n, x;

ll parcel(ll y, vector <ll>&a){
	ll total = 0;
	For(i, a.size()){
		total += y / a[i];
	}
	return total;
}

ll solve(ll x, vector <ll>&a){
	ll l = 1, r = LLONG_MAX, ans = LLONG_MAX;
	ll m = 0;
	
	while(l <= r){
		m = (l + r) / 2;
		
		if(parcel(m, a) >= x){
			r = m - 1;
		}else{
			l = m + 1;
			ans = m;
		}
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x;
	vector<ll>a(n);
	For(i, n) cin >> a[i];
	
	cout << solve(x + 1, a) - solve(x, a) << endl;
}
