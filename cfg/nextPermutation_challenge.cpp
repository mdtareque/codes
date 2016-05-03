#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
//using namespace std;

int main() {
		//char xs[] = "123";
		std::string xs;// ="123";
		std::vector<long> list;
		int n=4, k=1, i;
		long num;
		char *p;
		for(i=0; i<k;i++)
		   xs+='1';
		for(; i<n;i++)
		   xs+='0';
		std::cout<<xs<<"\n";
		sort(xs.begin(), xs.end());
		std::cout<<xs<<"\n";
		std::cout<<xs.size()<<"\n";
		do {
				std::cout<<xs<<"\n";
				num = std::stol(xs,nullptr, 2);
				list.push_back(num);
				std::cout<<num<<"\n";
		} while (std::next_permutation(xs.begin(), xs.end()));
		return 0;
}


