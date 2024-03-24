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
	string S; cin >> S;
	unordered_map<char,int> umap;
	rep(i,S.size()) {
		umap[S[i]]++;
	}
	rep(i,S.size()-1) {
		if (S[i] != S[i+1]) {
			if (umap[S[i]] > umap[S[i+1]]) {
				cout << i + 2 << endl;
			} else {
				cout << i + 1 << endl;
			}
			return 0;
		}
	}

	return 0;
}