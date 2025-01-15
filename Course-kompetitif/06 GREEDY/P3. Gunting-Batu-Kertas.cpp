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
	int n; cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	
	int g = 0, b = 0, k = 0;
	
	For(i, n){
		if(s2[i] == 'G') g++;
		else if(s2[i] == 'B') b++;
		else if(s2[i] == 'K') k++;
	}
	
	int ans = 0;
	
	For(i, n){
		if(s1[i] == 'G' && k > 0){
			k--;
			ans++;
		}
		else if(s1[i] == 'B' && g > 0){
			g--;
			ans++;
		}
		else if(s1[i] == 'K' && b > 0){
			b--;
			ans++;
		}
	}
	
	cout << ans;
}
