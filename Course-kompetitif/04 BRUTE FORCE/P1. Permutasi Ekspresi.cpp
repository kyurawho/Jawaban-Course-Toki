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

string s;
set<ll> ans;

void solve(ll depth, ll sum){
	if(depth == s.size()){
		ans.insert(sum);
	}else{
		ll temp = 0;
		for(ll i = depth; i < s.size(); i++){
			temp *= 10;
			temp += s[i] - '0';
			if(depth == 0) solve(i + 1, temp);
			else{
				solve(i + 1, sum + temp);
				solve(i + 1, sum - temp);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	solve(0, 0);
	cout << ans.size();
}