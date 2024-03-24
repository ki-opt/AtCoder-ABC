#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int X, N; cin >> X >> N;
	vector<int> p(N);
	unordered_map<int,int> umap;
	rep(i,N) {
		cin >> p[i];
		umap[p[i]]++;
	}

	vector<int> candidate;
	repp(i,-1000,1001) {
		if (umap.count(i) > 0) continue;
		candidate.push_back(i);
	}

	int ans = INT_MAX, index;
	for (int i = candidate.size()-1; i >= 0; i--) {
		if (abs(candidate[i]-X) <= ans) ans = abs(candidate[i]-X), index = candidate[i];
	}
	cout << index << endl;

	return 0;
}