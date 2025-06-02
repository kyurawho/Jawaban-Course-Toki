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

int n, m, a, b;
int grid[105][105];
bool visited[105][105];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(){
	queue <pair<pii, int>> q;
	
	q.push({{a, b}, 1});
	visited[a][b] = true;
	
	while(!q.empty()){
		auto [pos, steps] = q.front();
		int cx = pos.fi, cy = pos.se;
		q.pop();
		
		
		if(cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) return steps;
		
		For(i, 4){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0){
				visited[nx][ny] = true;
				q.push({{nx, ny}, steps + 1});
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	For(i, 105){
		For(j, 105){
			visited[i][j] = false;
		}
	}
	
	cin >> n >> m;
	
	For(i, n){ // a
		For(j, m){ // b
			cin >> grid[i][j];
		}
	}
	
	cin >> a >> b;
	a--; b--;
	
	cout << bfs() << endl;
}
