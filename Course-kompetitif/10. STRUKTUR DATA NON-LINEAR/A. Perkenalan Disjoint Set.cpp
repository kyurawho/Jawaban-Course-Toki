#include<bits/stdc++.h>
//#include<stdio.h>
//#include<math.h>
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

//ll MOD = 1e9 + 7;
int n, q;
int par[100005];

int find(int x){
	if(par[x] == x) return x;
	par[x] = find(par[x]);
	return par[x];
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	par[a] = b;
}

bool check(int a, int b){
	return find(a) == find(b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	
	Fori(i, n){
		par[i] = i;
	}
	
	while(q--){
		int x, a, b;
		cin >> x >> a >> b;
		
		if(x == 1) join(a, b);
		else cout << (check(a, b) ? "Y" : "T") << endl;
	}
}
