#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define pb push_back
#define pq priority_queue
#define mp make_pair
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
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

ll k, n, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> k;
	vector<pair<ll, ll>> c(k); //vector kalau ada sizenya, pake cin, kalau ga ada, pake pb
	
	for(ll i = 0; i < k; i++) cin >> c[i].se;
	for(ll i = 0; i < k; i++) cin >> c[i].fi;
	
	cin >> n;
	vector<ll> b(n);
	
	for(ll i = 0; i < n; i++) cin >> b[i];
	
	sort(all(c));
	sort(allr(b));
	
	ll index = 0;
	ll ans = 0;
	
	for(ll i = 0; i < n; i++){
		if(c[index].se == 0) index++;
		ans += b[i] * c[index].fi;
		c[index].se--;
	}
	
	cout << ans << endl;
}
