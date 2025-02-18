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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	vector<int> a, b;
	
	For(i, n){
		int x;
		cin >> x;
		a.pb(x);
	}
	
	For(i, n){
		int x;
		cin >> x;
		b.pb(x);
	}
	
	int dp[n + 1][n + 1];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
		}
	}
	
	cout << dp[n][n] << endl;
}
