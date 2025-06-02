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

int n, k;
vector <int> v;

int BFS(){
	vector <int> target = v;
	sort(all(target));
	
	queue<pair<vector <int>, int>> q;
	set <vector <int>> visited;
	
	q.push({v, 0});
	visited.insert(v);
	
	while(!q.empty()){
		auto [current, steps] = q.front();
		q.pop();
		
		if(current == target) return steps;
		
		For(i, n - k + 1){
			vector <int> next = current;
			reverse(next.begin() + i, next.begin() + i + k);
			
			if(!visited.count(next)){
				visited.insert(next);
				q.push({next, steps + 1});
			}
		}
	}
	
	
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;

	For(i, n){
		int x;
		cin >> x;
		v.pb(x);
	}
	
	cin >> k;
	
	cout << BFS() << endl;
}
