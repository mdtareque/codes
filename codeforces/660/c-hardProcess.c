#include<stdio.h>
#define MAX 300005

int main() {
		int n, k, a[MAX];
		int i,j;
		scanf("%d%d", &n, &k);
		for(i=0; i<n;i++)
				scanf("%d", &a[i]);
		int maxWinSize=-1;
		int curNumZeros=0;
		int startWin=-1, endWin=-1;
		i=0;j=0;
		while(i<n-k && j<n) {

				while(curNumZeros != k) {
						if(j == n) break;
						if( a[j] == 0 ){
								curNumZeros++;
						}
						j++;
				}
				while(j<n && a[j] == 1) j++;
				if(curNumZeros == k) {
						if(j-i > maxWinSize) {
								maxWinSize = j-i;
								startWin = i;
								endWin = j;
						}
				}
				if(a[i] == 1)
						;
				else
						curNumZeros--;
				i++;

		}
		printf("%d\n", maxWinSize);
		for(i=0; i<n; i++) {
				if(i >=startWin && i< endWin) printf("1 ");
				else printf("%d ", a[i]);
		}
		printf("\n");

}
