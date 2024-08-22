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

struct beras{
	double w;
	double c;
	double cost;
};

typedef beras Beras;

Beras B[1001];
Beras BSort[1001];

void insertionSort(int i) {
    BSort[i]=B[i];
    if(i!=0) {
        while(i>0 && BSort[i-1].cost<BSort[i].cost) {
            Beras tmp = BSort[i-1];
            BSort[i-1] = BSort[i];
            BSort[i] = tmp;
            i--;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	
	For(i, n){
		cin >> B[i].w;
	}
	
	For(i, n){
		cin >> B[i].c;
		B[i].cost = B[i].c / B[i].w;
        insertionSort(i);
	}
	int i = 0;
	while(q>0 && i<n) {
        if(i!=0) {
            if(BSort[i].w < q) {
                BSort[i].cost=(BSort[i].cost*BSort[i].w)+BSort[i-1].cost;
                q -= BSort[i].w;
            } else {
                BSort[i].cost=(BSort[i].cost*q)+BSort[i-1].cost;
                break;
            }
        } else {
            if(BSort[i].w < q) {
                BSort[i].cost=BSort[i].cost*BSort[i].w;
                q -= BSort[i].w;
            } else {
                BSort[i].cost = BSort[i].cost*q;
                break;
            }
        }
        i++;
    }
    if(i==n) i--;
    cout<<std::setprecision(5)<<std::fixed<<BSort[i].cost<<endl;
}
