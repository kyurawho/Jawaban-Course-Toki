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

bool visited[100001];
vector <int> adj[100001]; // vector tapi array, soalnya adj[100001] bukan adj(100001)
// kalau adj(100001) jadi size dari vector itu, tapi pada kasus ini size vectornya tidak ada, yang ada adalah size dari arraynya, sehingga tidak memakan banyak memori

void dfs(int x){
	visited[x] = true;
	For(i, adj[x].size()){ //cek setiap simpul yang berhubungan dengan simpul itu sendiri;
		if(!visited[adj[x][i]]){
			dfs(adj[x][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	
	For(i, m){
		int v, u;
		cin >> v >> u; // 1 2
		
		adj[v].pb(u); // 1 connect sama 3, jadi adj[1] = {3}; versi akhir: adj[1] = {3, 2}; 
		adj[u].pb(v); // 1 connect sama 3, jadi adj[3] = {1}; versi akhir: adj[3] = {1, 2};
	}
	
	For(i, n){
		visited[i] = false;
	}
	
	int cnt = 0;
	Fori(i, n){ // cek semua simpulnya, lalu lakukan dfs untuk menandai bahwa telah didatangi, count sebagai penghitung banyak pulau/komponen yang ada
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	
	cout << cnt << endl;
}

/*

Test Case Example

Input:
7 5
1 2
3 2
5 7
2 4
3 1

Output:
3
*/
