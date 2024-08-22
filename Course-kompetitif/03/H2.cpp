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

int n;
double x;

struct karung_beras{
    double harga, c, w;
};

bool comp(karung_beras a, karung_beras b){
    return a.harga > b.harga;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> x;

    karung_beras beras[n];

    for(int i = 0; i < n; i++) cin >> beras[i].w;
    for(int i = 0; i < n; i++) cin >> beras[i].c;

    for(int i = 0; i < n; i++) beras[i].harga = beras[i].c / beras[i].w;

    sort(beras, beras + n, comp);

    int idx = 0;
    double ans = 0;
    while(x > 0 && n > idx){
        if(beras[idx].w <= x){
            ans += beras[idx].c;
            x -= beras[idx].w;
        } else {
            ans += beras[idx].harga * x;
            x -= x;
        }

        idx++;
    }

    cout << fixed << setprecision(5) << ans << endl;
}
