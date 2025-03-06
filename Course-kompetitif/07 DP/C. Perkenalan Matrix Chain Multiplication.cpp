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

const ll MOD = 26101991, maxn = 1e2 + 5;
ll dp[maxn][maxn], s[maxn][maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	Fori(i, n + 1){
		cin >> a[i];
	}
	int q;
	cin >> q;
	
	
	if(q == 1){
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				dp[i][j] = LLONG_MAX;
				for(int k = i; k < j; k++){
					ll min = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
					dp[i][j] = min < dp[i][j] ? min : dp[i][j];
				}
//				cout << dp[i][j] << ' ';
			}
//			cout << endl;
		}
		cout << dp[1][n] << endl;
	}else if(q == 2){
		Fori(i, n){
			s[i][i] = 1;
		}
		
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				dp[i][j] = LLONG_MAX;
				for(int k = i; k < j; k++){
					ll min = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
					if(min < dp[i][j]){
						dp[i][j] = min;
						s[i][j] = s[i][k] * s[k + 1][j];
					}else if(min == dp[i][j]) s[i][j] += s[i][k] * s[k + 1][j];
					s[i][j] %= MOD;
				}
//				cout << dp[i][j] << ' ';
			}
//			cout << endl;
		}
		cout << s[1][n] << endl;
	}else if(q == 3){
		Fori(i, n){
			dp[i][i] = 1;
		}
		
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				int j = i + len - 1;
				dp[i][j] = 0;
				for(int k = i; k < j; k++){
					dp[i][j] += dp[i][k] * dp[k + 1][j];
					dp[i][j] %= MOD;
				}
//				cout << dp[i][j] << ' ';
			}
//			cout << endl;
		}
		
		cout << dp[1][n] << endl;
	}
}
