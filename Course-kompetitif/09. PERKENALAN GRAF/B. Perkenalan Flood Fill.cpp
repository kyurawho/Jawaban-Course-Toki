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
#define Repp(i, l, r, a) for(int i = l; i < r; i += a)
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

int r, c, kucing = 0, bebek = 0;
char grid[505][505];
bool visited[505][505];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
/*
0 = atas
1 = bawah
2 = kanan
3 = kiri
*/

int bfs (int x, int y){
	memset(visited, 0, sizeof(visited));
	
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = true;
	int count = 0;
	
	while(!q.empty()){
		int cx = q.front().fi; // current x, curent y
		int cy = q.front().se;
		q.pop();
//		count++;
		
		For(i, 4){
			int nx = cx + dx[i]; // new x
			int ny = cy + dy[i]; // new y
			
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && grid[nx][ny] != '#'){
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	
	For(i, r){
		For(j, c){
			if(visited[i][j]) count++;
		}
	}
	
	return count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> r;
    
	int kx, ky, bx, by;
	
	For(i, r){
		For(j, c){
			cin >> grid[i][j];
			if(grid[i][j] == 'K'){
				kx = i;
				ky = j;
			}
			if(grid[i][j] == 'B'){
				bx = i;
				by = j;
			}
		}
	}
	
	
	kucing = bfs(kx, ky);
	bebek = bfs(bx, by);
	
	
	if(kucing > bebek) cout << "K " << kucing - bebek << endl;
	else if(bebek > kucing) cout << "B " << bebek - kucing << endl;
	else cout << "SERI" << endl;
}
