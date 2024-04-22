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
	string S, T; cin >> S >> T;
	string t;
	rep(i,T.size()) t += (T[i] + 32);

	map<char,vector<int>> umap;
	rep(i,S.size()) {
		umap[S[i]].push_back(i);
	}

	if (T[2] == 'X') {
		if (umap[t[0]].size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		int f = umap[t[0]][0];
		
		int next = -1;
		if (umap[t[1]].size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		for (auto u : umap[t[1]]) {
			if (u > f) {
				next = u;
				break;
			}
		}
		if (next == -1) {
			cout << "No" << endl;
			return 0;
		}
	} else {
		if (umap[t[0]].size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		int f = umap[t[0]][0];

		int next = -1;
		if (umap[t[1]].size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		for (auto u : umap[t[1]]) {
			if (u > f) {
				next = u;
				break;
			}
		}
		if (next == -1) {
			cout << "No" << endl;
			return 0;
		}

		f = next;
		next = -1;
		if (umap[t[2]].size() == 0) {
			cout << "No" << endl;
			return 0;
		}
		for (auto u : umap[t[2]]) {
			if (u > f) {
				next = u;
				break;
			}
		}
		if (next == -1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}