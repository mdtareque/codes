#include<stdio.h>
#include<limits.h>
#include<string.h>
#define MAXN 100
#define MAX 1000000
#define NPRIME 78499
#define MAXFACTORS 1024

unsigned long long primes[NPRIME];
unsigned long long numLine[MAX];
unsigned long long primeFactor[MAXFACTORS];

void sieve() {
    long long i, j=1, k;
    int step=0;
    primes[j++]=2; primes[j++]=3;

    for(i=5; i<MAX;) {
        if(numLine[i]==0) {
            primes[j++]=i;
            for(k=2; i*k<MAX; k++)
                numLine[i*k]=1;
        }
        // little quicker jumps
        if(step%2) {i+=4; step=0;}
        else {i+=2; step++;}
    }
    //    printf("%lld %lld\n", j, primes[NPRIME-1]);
}

int isPrime(unsigned long long n) {
    long long i;
    for(i=1; primes[i]*primes[i] < n &&  i<NPRIME; i++) {
        //printf("checking for %lld\n", primes[i]);
        if(n%primes[i] == 0) return 0;
    }
    return 1;
}

long long printPrimeDivisors(long long n) {
    int numOfPrimeDivisor=0;
    long long i;
    int pfcount=0;
    if(n==1){ return 0;} //numOfPrimeDivisor=1;primeFactor[pfcount++]=1;return 1;}
    //printf("printing prime divisors of %lld\n",n);
    for(i=1; primes[i]*primes[i]<=n && i<NPRIME; i++) {
        if(n%primes[i] == 0) {
            primeFactor[pfcount++] = primes[i];
            //printf("%lld\n",primes[i]);
            numOfPrimeDivisor++;
        }
        while(n>0 && n%primes[i] == 0) {
            n = n/primes[i];
        }
    }
    if(n>1) {
        numOfPrimeDivisor++;
        //printf("%lld\n",n);
        primeFactor[pfcount++] = n;
    }
    return numOfPrimeDivisor;
}

unsigned long long gcd ( unsigned long long a, unsigned long long b ) {
    unsigned long long c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}


unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a*(b/gcd(a,b));
}

// prime divisors on lcm on n numbers
int main(int argc, char *argv[]) {
    //printf("%lld\n", LLONG_MAX);
    //printf("%llu\n", ULLONG_MAX);
    unsigned long long lcmm, num1, num2, num[MAXN];
    int numOfPrimeDivisor;
    int T, N, i, j, l;
    sieve();
    scanf("%d", &T);
    j=1;
    while(j <= T) {
        scanf("%d", &N);
        if(N>0) {
            l = 0;
            for(i=0; i<N; i++) {
                scanf("%llu", &num1);
                if(num1 != 0) num[l++] = num1;
                //             printf("read %llu\n", num2);
            }
            num1= num[0];
            for(i=1; i<l; i++) {
                num2=num[i];
                if(num1<num2) {
                    num1=num1^num2;
                    num2=num1^num2;
                    num1=num1^num2;
                }

                lcmm = lcm(num1, num2);
                num1 = lcmm;
            }
            //         printf("Print prime divisors of %llu\n", lcmm);
            numOfPrimeDivisor = printPrimeDivisors(num1);
            printf("Case #%d:%d\n", j++, numOfPrimeDivisor);
            //         printf("%s", buf);
            for(i=0; i<numOfPrimeDivisor; i++) {
                printf("%lld\n", primeFactor[i]);
            }
        } else {j++;}

    }
    return 0;
}



