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

ll temp[1005][1005];

ll solve(ll n, ll x){
	if(x > n || x < 0) return 0;
	if(x == 0 || n == x) return 1;
	if(temp[n][x]) return temp[n][x];
	temp[n][x] = solve(n - 1, x - 1) + solve(n - 1, x);
	return temp[n][x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int arr[2][n];
	For(i, n){
		cin >> arr[0][i] >> arr[1][i];
	}
	cout << solve(n, 3) << endl;
}
