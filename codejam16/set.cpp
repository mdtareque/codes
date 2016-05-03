#include<iostream>
#include<set>
using namespace std;

int main() {
	set<long> myset;
	set<long>::iterator it;
	int i;
	for(i=0; i<5; i++) myset.insert(i*10);
	bool present = myset.find(30) != myset.end();
	cout<<"present : " << present<<"\n";
	return 0;
}
