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

bool used[11];
string s;
int n, r, y, j, x;
int h[1001];
pair <int, char> bebek[15];
vector <int> jumlah_k;

void permutasi(int i, int sum, char prev, bool has){
	if(i > r){
		jumlah_k.pb(sum);
		return;
	}
	
	For(j, n){
		if(used[j]) continue;
		used[j] = true;
		int newsum = sum;
		
		if(prev == 'L') newsum += bebek[j].fi / 2;
		else if (prev == 'P') newsum += bebek[j].fi * 2;
		else newsum += bebek[j].fi;
		
		if(has) newsum += y;
		
		permutasi(i + 1, newsum, bebek[j].se, (has || bebek[j].se == 'Y'));
		
		used[j] = false;
	}
}

int binser(vector<int> &jumlah_k, int h){
	int l = 0, r = jumlah_k.size() - 1;
	int ans = jumlah_k.size();
	
	while(l <= r){
		int m = (l + r) / 2;
		
		if(jumlah_k[m] > h){
			ans = m;
			r = m - 1;
		}else{
			l = m + 1;
		}
	}
	
	return jumlah_k.size() - ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s >> x;
	cin >> n >> r >> y >> j;
	
	For(i, n){
		cin >> bebek[i].fi >> bebek[i].se;
	}
	
	permutasi(1, 0, 'B', false);
	sort(all(jumlah_k));
	
	For(i, j){
		cin >> h[i];
		cout << binser(jumlah_k, h[i]) << endl;
	}
}
