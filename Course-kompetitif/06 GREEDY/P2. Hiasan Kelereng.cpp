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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	
	string s;
	cin >> s;
	
	ll arr[27];
	
	For(i, 27) arr[i] = 0;
	
	ll ans;
	
	For(i, n) arr[s[i] - 64]++;
	sort(arr + 1, arr + 27);
	
	ans = arr[24] * 3;
	
	if(arr[25] > arr[24]) ans++;
	if(arr[26] > arr[24]) ans++;
	
	if(arr[24] == 0) cout << -1;
	else cout << ans;
}
