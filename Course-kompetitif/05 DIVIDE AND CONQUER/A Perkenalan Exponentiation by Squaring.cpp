#include <stdio.h>
#include <math.h>

typedef long long LL;
LL MOD = 1000000;

LL function(LL a, LL e){
  if (e == 0) return 1;
  if (e == 1) return a % MOD;
  if (e % 2 == 0) return ((function(a, e / 2) % MOD) * (function(a, e / 2) % MOD)) % MOD;
  if (e % 2 == 1) return ((function(a, e - 1) % MOD) * (function(a, 1) % MOD)) % MOD;
  
  return 0;
}

int main(){
  LL a, b;
  scanf("%lld %lld", &a, &b);
  if(b * log10(a) >= 6) printf("%06lld\n", function(a, b) % MOD);
  else printf("%lld\n", function(a, b) % MOD);
}