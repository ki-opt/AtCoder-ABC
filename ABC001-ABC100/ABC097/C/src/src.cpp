#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string s;
	int K;
	cin >> s >> K;

	unordered_map<string,int> umap;
	repp(i,1,6) {
		rep(j,s.size()+1-i) {
			umap[s.substr(j,i)]++;
		}
	}
	
	int k = 0;
	vector<string> ans;
	for (auto iter = umap.begin(); iter != umap.end(); iter++) {
		ans.push_back(iter->first);		
	}
	sort(ans.begin(),ans.end());
	cout << ans[K-1] << endl;
	return 0;
}