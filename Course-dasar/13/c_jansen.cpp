#include<stdio.h>
int n, catat[10];
bool perna[10], zigzag;
void fungsi(int x)
{
	if (x >= n)
	{
		zigzag = true;
		for (int i = 1; i + 1 < n; i++)
		{
			if (catat[i] > catat[i + 1] && catat[i] < catat[i - 1]) zigzag = false;
			else if (catat[i] < catat[i + 1] && catat[i] > catat[i - 1]) zigzag = false;
		}
		if (zigzag)
		{
			for (int i = 0; i < n; i++) printf("%d", catat[i]);
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!perna[i])
		{
			perna[i] = true;
			catat[x] = i;
			fungsi(x + 1);
			perna[i] = false;
		}
	}
}
int main()
{
	scanf("%d", &n);
	fungsi(0);
}
