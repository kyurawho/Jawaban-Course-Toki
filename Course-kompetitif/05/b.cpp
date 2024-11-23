#include <stdio.h>

typedef long long LL;

LL function(LL a, LL b, LL m){
  a %= m;
  if(b==0) return 1;
  LL res = function(a,b/2,m);
  if(b&1) return (res*res*a) % m ;
  else return (res*res) % m ;
}

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  LL res = function(a, b, 1000000);
  printf("%d", res);
}