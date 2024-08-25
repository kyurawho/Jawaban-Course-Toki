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

int b, k;
int m, n;
int a[128][128];
int c[128][128];
int ans = 0;
int num = 0;

void solve(int x, int y){
	if(a[x][y] == num){
		a[x][y] = -1;
		ans++;
		solve(x + 1, y);
		solve(x - 1, y);
		solve(x, y + 1);
		solve(x, y - 1);
	}
}

void solve2(int x, int y){
	if(c[x][y] == num){
		c[x][y] = -1;
		ans++;
		solve2(x + 1, y);
		solve2(x - 1, y);
		solve2(x, y + 1);
		solve2(x, y - 1);
	}
}

void fall(int r, int x){
	int rn = r;
	while(rn + 1 < m && c[rn + 1][x] == -1){
		rn++;
	}
	if(rn == r) return;
	c[rn][x] = c[r][x];
	c[r][x] = -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> m >> n;
	
	For(i, m){
		For(j, n){
			cin >> a[i][j];
			c[i][j] = a[i][j];
		}
	}
	
	int max = 0;
	int x, y;
	
	For(i, m){
		For(j, n){
			if(a[i][j] != -1){
				ans = 0;
				num = a[i][j];
				solve(i, j);
				if(ans > max){
					max = ans;
					x = i;
					y = j;
				}
			}
		}
	}
	
	num = c[x][y];
	solve2(x, y);
	
	for(int i = m - 1; i >= 0; i--){
		For(j, n){
			fall(i,j);
		}
	}
	
	For(i, m){
		For(j, n){
			if(c[i][j] == -1) cout << ". ";
			else cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
