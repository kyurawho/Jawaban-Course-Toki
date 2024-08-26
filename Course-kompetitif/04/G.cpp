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

int m, n, ans;

void solve(int x, int y, int num, bool marked, bool visited[128][128], int b[128][128]){
	if((b[x][y] != num) || (visited[x][y])|| (y < 0) || (x < 0) || (y >= n) || (x >= m)) return;
	else{
		ans++;
		if(marked) b[x][y] = -1;
		visited[x][y] = true;
		solve(x + 1, y, num, marked, visited, b);
		solve(x - 1, y, num, marked, visited, b);
		solve(x, y + 1, num, marked, visited, b);
		solve(x, y - 1, num, marked, visited, b);
	}
}

void copyball(int b[128][128], int a[128][128]){
	For(i, m){
		For(j, n){
			b[i][j] = a[i][j];
		}
	}
}

void fall(int r, int x, int b[128][128]){
	int rn = r;
	while(rn + 1 < m && b[rn + 1][x] == -1){
		rn++;
	}
	if(rn == r) return;
	b[rn][x] = b[r][x];
	b[r][x] = -1;
}

int solve3(int b[128][128]){
	bool visited[128][128] = {0};
	int maks = 0;
	int ball[128][128];
	copyball(ball, b);
	For(i, m){
		For(j, n){
			if(visited[i][j] || ball[i][j] == -1) continue;
			ans = 0;
			solve(i, j, ball[i][j], false, visited, ball);
			if(ans == 1) continue;
			maks = (ans > maks) ? ans : maks;
		}
	}
	
	return maks;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	
	bool visited[128][128] = {0};
	int bola[128][128] = {0};
	For(i, m){
		For(j, n){
			cin >> bola[i][j];
		}
	}
	
	int max = 0;
	int x, y;
	int ball[128][128];
	
	For(i, m){
		For(j, n){
			if(visited[i][j]) continue;
			ans = 0;
			copyball(ball, bola);
			solve(i, j, ball[i][j], true, visited, ball);
			if(ans == 1) continue;
			for(int i = m - 1; i >= 0; i--){
				For(j, n){
					fall(i, j, ball);
				}
			}
			int temp = ans * (ans - 1);
			int ans2 = solve3(ball);
			temp += ans2 * (ans2 - 1);
			max = (temp > max) ? temp : max;
		}
	}
	
	cout << max << endl;
}
