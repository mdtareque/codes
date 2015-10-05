#include<stdio.h>
#include<string.h>
#define max(a,b) (a>b?a:b)

// array and it's length
int kadane1d(int *a, int l, int *start, int *end) {
    int maxSoFar=INT_MIN, currMax=INT_MIN;
    int i, curStart; //, start=0, end;
    *start=0;
    for(i=0; i<l; i++) {
        currMax=max(currMax+a[i], a[i]);
        if(currMax<0) { currMax=0; curStart=i+1; }
        else if(maxSoFar < currMax) { *maxStart=currMax; maxSoFar=currMax; *end=i;}
    }
    return maxSoFar;
}

int main(int argc, char *argv[]) {
    int a[]= {-2, -3, 4, -1, -2, 1, 5, -3};
    int l=8, i, start, end;
    for(i=0; i<l; i++) printf("%d ", a[i]); printf("\n");
    printf("%d\n",kadane1d(a,l, &start, &end));
    printf("start %d, end %d\n", start, end);
    return 0;
}

