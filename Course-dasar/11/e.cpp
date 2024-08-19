#include <stdio.h>

int main(){
	char s[111];
	int i=0;
	scanf("%s", s);
	
	while(s[i] != 0){
		if(s[i]>96){
			s[i] -= 'a' - 'A';
		}else{
			s[i] += 'a' - 'A';
		}
		i++;
	}
	printf("%s", s);
}
