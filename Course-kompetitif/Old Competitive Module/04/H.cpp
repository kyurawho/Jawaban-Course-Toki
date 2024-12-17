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

void solve(int i, int nb, int nk, int lb, int lk, vector<int> &ans, int a[]){
	if(nb + nk == 1){
		For(i, ans.size()){
			cout << ans[i] << ' ';
		}
		exit(0);
	}
	
	if(nb > 0 && a[i + lb] != a[i + lb - 1]){
		ans.pb(a[i + lb]);
		solve(i + lb, nb - 1, nk, lb, lk, ans, a);
		ans.pop_back();
	}
	
	if(nk > 0 && a[i + lk] != a[i + lk - 1]){
		ans.pb(a[i + lk]);
		solve(i + lk, nb, nk - 1, lb, lk, ans, a);
		ans.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a[n];
	For(i, n) cin >> a[i];
	
	int m; cin >> m;
	
	sort(a, a + n);
	
	int lk = n / m;
	int lb = lk + 1;
	int nb = n % m;
	int nk = m - nb;
	vector<int> ans;
	solve(0, nb, nk, lb, lk, ans, a);
}
