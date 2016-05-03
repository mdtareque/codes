#include<iostream>
#include<bitset>
#include<cmath>
#include<cstring>
#define MAX 1000000
#define NPRIME 78498
using namespace std;


/*
not sure how to overcome this error, tried all variations of stoll, stoull
Case #1:
checking if prime in all bases for 10000000000000000000000000000001
checking if prime in all bases for 10000000000000000000000000000011
checking if prime in all bases for 10000000000000000000000000000101
checking if prime in all bases for 10000000000000000000000000000111
terminate called after throwing an instance of 'std::out_of_range'
  what():  stoll
  Aborted (core dumped)


*/

unsigned long long primes[NPRIME];
unsigned long long numLine[MAX];

void sieve() {
    long long i, j=0, k;
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
    //printf("%lld %lld\n", j, primes[NPRIME-1]);
}

int isPrime(unsigned long long n) {
    long long i;
    for(i=0; primes[i]*primes[i] < n &&  i<NPRIME; i++) {
        //printf("checking for %lld\n", primes[i]);
        if(n%primes[i] == 0) return primes[i];
    }
    return 1;
}

int main() {
    sieve();
/*  cout<<isPrime(337)<<"\n";
    string bin = bitset<4>(13).to_string();
    cout<<bin<<'\n';
    cout<<stol("110111", nullptr, 3); 
    string bin2 = bitset<14>(0).to_string();
    cout<<bin2<<'\n'; */

    int t, j, n, i;
    int count;
    long loopn;
    //long long candidate;
    //cout<<sizeof(candidate);
    int flag; 
    //const int maxN = 65535; //maxN = pow(2, n) - 1;
    const int maxDigits = 30;
    string bin , newn;
    //cin>>t;
    //cin>>n>>j;
    n=32; j=500;
    //maxDigits = n-2;
    //cout<<maxN;
    count=0;
    loopn = 0;
    cout<<"Case #1:\n";
    
//   /*
 while(count < j) {
//        cout<<"checking for "<<loopn<<"\n";
        bin = bitset<30>(loopn).to_string();
        newn = '1' + bin + '1';
        cout<<"checking if prime in all bases for "<< newn <<'\n';
        flag=0;
        unsigned long int candidate;
        //long double candidate;
        for(i=2; i<11; i++) {
            candidate = stoull(newn, nullptr, i);
            //candidate = stoll(newn, nullptr, i);
            cout<< candidate<<'\n';
            //candidate = strtoll(newn, nullptr, i); // error
            if(isPrime(candidate) == 1) { flag=1; break; }
        }
        if(flag == 0) { // got a number
            // a jamcoin
            cout<<"Got one\n";
            count++;

            // now print all its non trivial divisor in base 2 to k
            cout<<newn<<" ";
            for(i=2; i<11; i++) {
                candidate = stoull(newn, nullptr, i);
                cout<< isPrime(candidate) << " ";

            }
            cout<<'\n';
        }
        loopn++;
    }
//*/
    return 0;
}
