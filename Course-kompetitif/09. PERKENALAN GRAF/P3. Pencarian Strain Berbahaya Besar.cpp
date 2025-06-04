#include<bits/stdc++.h>
//#include<stdio.h>
//#include<math.h>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define pb push_back
#define pq priority_queue
//#define mp make_pair
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

int a[1000005];
int n, s, p, mx;
vector <int> adj[1000005];
map<string, vector<int>> mp;
bool visited[1000005];

void dfs(int cur, int sum){
	visited[cur] = true;
	sum += a[cur];
	
	if( !(adj[cur].size()) ){
		mx = max(mx, sum);
	}
	
	Each(i, adj[cur]){
		if(!visited[i]) dfs(i, sum);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	For(i, 1000005){
		visited[i] = false;
	}
	
	cin >> n >> s >> p;
	
	Fori(i, n){
		cin >> a[i];
	}
	
	For(i, p){
		string v; int x;
		cin >> v >> x;
		mp[v].pb(x);
	}
	
	For(i, n - p){
		int u, v;
		cin >> u >> v;
		
		adj[u].pb(v);
	}
	
	int ans = 0;
	string virus;
	for(auto &[v, c]: mp){
		int mxc = 0;
		Each(i, c){
			mx = 0;
			dfs(i, 0);
			mxc = max(mxc, mx);
		}
		
		if(mxc > ans){
			ans = mxc;
			virus = v;
		}
	}
	
	cout << virus << endl;
	cout << ans << endl;
}
