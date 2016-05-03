#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class DoubleWeights {
int min;
void dfs(int v, int w1, int w2, int n, vector<string> &wt1, vector<string> &wt2, vector<int> &vis ) {
	vis[v] = 1;
	for(int i=0; i<n; i++ ) {
		if( wt1[v][i] == ".") 
			cout<<"string match\n";
		if( wt1[v][i] == '.') 
			cout<<"char match\n";
	}
	
}
public:
	int minimalCost(vector <string> weight1, vector <string> weight2) {
		min = INT_MAX;
		int n = (int) sqrt(wt1.size());
		vector<int> vis(n);
		std::fill(vis.begin(), vis.end(), 0);
		dfs(0, 0, 0, n, wt1, wt2, vis)
		cout<<min<<endl;

	}
	

};

