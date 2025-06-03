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

int n, m, k, s, x, y, posx, posy;
bool grid[505][505];
bool ans = false;

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void BFS(){
	queue <pair<pii,int>> q;
	
	q.push({{posx, posy}, 0});
	grid[posx][posy] = true;
//	cout << posx << ' ' << posy << endl << endl;
	
	while(!q.empty()){
		auto [pos, steps] = q.front();
		q.pop();
		int cx = pos.fi, cy = pos.se;
		
		For(i, 8){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !grid[nx][ny] && steps != s){
				grid[nx][ny] = true;
				q.push({{nx, ny}, steps + 1});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//int n;
	//cin >> n;
	
	
	int t;
	cin >> t;
	while(t--){
		ans = false;
		
		cin >> n >> m >> k >> s >> x >> y;
		x--; y--;
		
		For(i, k){
			For(i, 505){
				For(j, 505){
					grid[i][j] = false;
				}
			}
			cin >> posx >> posy;
			posx--; posy--;
			BFS();
			if(grid[x][y]) ans = true;
		}
		
//		For(i, n){
//			For(j, m){
//				if(grid[i][j]) cout << "1 ";
//				else cout << "0 ";
//			}
//			cout << endl;
//		}
		
		(ans) ? cout << "TRUE" : cout << "FALSE";
		cout << endl;
	}
}
