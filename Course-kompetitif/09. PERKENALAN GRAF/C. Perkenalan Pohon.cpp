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

int n, m;
string a, b;
unordered_map <string, vector<string>> mp;
unordered_map <string, bool> visited;
bool done = false, is_a = false, is_b = false;
vector <string> ans;

void dfs(string x){
	if(done) return;
	visited[x] = true;
	ans.pb(x);
	
	if(x == b && is_a){
		done = true;
		return;
	}
	
	if(x == a && is_b){
		done = true;
		return;
	}
	
	For(i, mp[x].size()){
		if(!visited[mp[x][i]]){
			dfs(mp[x][i]);
			if(done) return;
		}
	}
	
	ans.pop_back();
	visited[x] = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	For(i, m){
		string p, c;
		cin >> p >> c;
		mp[p].pb(c);
	}
	
	cin >> a >> b;
	
	if(mp.count(a)){
		is_a = true;
		dfs(a);
	}else if(mp.count(b)){
		is_b = true;
		dfs(b);
	}else{
		cout << "TIDAK MUNGKIN" << endl;
		return 0;
	}
	
	if(done){
		Each(i, ans){
			cout << i << endl;
		}
	}else{
		cout << "TIDAK MUNGKIN" << endl;
		return 0;
	}
}
