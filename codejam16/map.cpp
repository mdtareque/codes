#include<iostream>
#include<map>
using namespace std;

int main() {
	map<char, int> mymap;
	map<char, int>::iterator it;
	mymap.insert( pair<char,int>('a', 100) );
	mymap.insert( pair<char,int>('c', 120) );

	for(it = mymap.begin(); it!=mymap.end(); it++)
		cout<< it->first << " => " << it->second << '\n';

	return 0;
}
