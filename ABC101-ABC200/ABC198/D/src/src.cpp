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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S1, S2, S3; cin >> S1 >> S2 >> S3;
	vector<string> vec = {S1,S2,S3};
	unordered_map<char,int> umap;
	rep(i,vec.size()) {
		rep(j,vec[i].size()) umap[vec[i][j]]++;
	}

	if (umap.size() > 10) {
		cout << "UNSOLVABLE" << endl;
		return 0;
	}

	vector<int> v; rep(i,10) v.push_back(i);
	do {
		int index = 0;
		unordered_map<char,int> mp;
		for (auto &u : umap) {
			mp[u.first] = v[index]; index++;
		}
		bool isFound = false;
		rep(i,vec.size()) {
			if (mp[vec[i][0]] == 0) isFound = true;
		}
		if (isFound) continue;

		vector<ll> N(vec.size(),0);
		rep(i,vec.size()) {
			rep(j,vec[i].size()) {
				N[i] *= 10; N[i] += mp[vec[i][j]];
			}
		}
		
		if (N[0] + N[1] == N[2]) {
			cout << N[0] << endl << N[1] << endl << N[2] << endl;
			return 0;
		}
	} while (next_permutation(v.begin(),v.end()));
	cout << "UNSOLVABLE" << endl;

	return 0;
}