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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	
	deque <int> q;
	bool reverse = false;
	
	while(t--){
		string s;
		cin >> s;
		
		if(s == "add"){
			int x, y;
			cin >> x >> y;
			
			if(!reverse) q.insert(q.end(), y, x);
			else q.insert(q.begin(), y, x);
			
			cout << q.size() << endl;
		}else if(s == "del"){
			int y;
			cin >> y;
			int remove = reverse ? q.back() : q.front();
			
			
			For(i, y){
				if(!reverse) q.pop_front();
				else q.pop_back();
			}
			
			cout << remove << endl;
		}else if (s == "rev"){
			reverse = !reverse;
		}
	}
}
