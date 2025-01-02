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

const int MAXN = 1e5 + 5;

int n, a[MAXN];

ll merge(int l, int m, int r){
    int i = l, j = m + 1, k = l;
    ll total = 0;
    
    int b[MAXN];
    for(int i = l; i <= r; i++){
    	b[i] = a[i];
	}

    while (i <= m && j <= r) {
        if (b[i] <= b[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = b[j++];
            total += (m - i + 1);
        }
    }


    while (i <= m) {
        a[k++] = b[i++];
    }


    while (j <= r) {
        a[k++] = b[j++];
    }
    
    return total;
}


ll mergeSort(int l, int r){
    if (l >= r) {
    	return 0;
    }
    
    int m = l + (r - l) / 2;
    
	ll total = 0;
    total += mergeSort(l, m);
    total += mergeSort(m + 1, r);
    
    total += merge(l, m, r);
    
    
    return total;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	Fori(i, n){
		cin >> a[i];
	}
	
	cout << mergeSort(1, n) << endl;
}
