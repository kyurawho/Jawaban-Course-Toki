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

vector <int> coins;

int coinChange(int amount) {
    int dp[++amount];
    dp[0] = 0;
    
    for(int i = 1; i < amount; i++){
    	dp[i] = INT_MAX;
    	for(int c: coins){
    		if(i - c < 0) break;
    		
    		if(dp[i - c] != INT_MAX){
    			dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
	}
    
    return dp[--amount] != INT_MAX ? dp[amount] : -1;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	For(i, n){
		int x; cin >> x;
		coins.pb(x);
	}
	
	int k;
	cin >> k;
	
	cout << coinChange(k) << endl;
}
