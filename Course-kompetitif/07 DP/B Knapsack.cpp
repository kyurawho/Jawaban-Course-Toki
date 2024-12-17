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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int w[k + 1], h[k + 1];
	int dp[k + 1][n + 1];
	
	w[0] = 0;
	h[0] = 0;
	
	for(int i = k; i > 0; i--){
		cin >> w[i] >> h[i];
	}
	
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || w == 0){
				dp[i][j] = 0;
			}else if(w[i] <= j){
				dp[i][j] = max(h[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	
//	for(int i = 0; i <= k; i++){
//		for(int j = 0; j <= n; j++){
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
	
	int id;
	for(int i = 1; i <= n; i++){
		if(dp[k][n] == dp[k][i]){
			id = i;
			break;
		}
	}
    
    for(int i = k; i > 0; i--){
    	if(dp[i][id] == h[i] + dp[i - 1][id - w[i]]){
    		cout << k - i + 1 << endl;
    		id -= w[i];
		}
	}

}
