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
	string T;
	int N; cin >> T >> N;
	vector<int> A(N);
	vector<vector<string>> S(N);
	rep(i,N) {
		cin >> A[i];
		rep(j,A[i]) {
			string tmp;
			cin >> tmp;
			S[i].push_back(tmp);
		}
	}

	unordered_map<string,int> umap;
	umap["-"] = 0;
	repp(i,0,N) {		
		unordered_map<string,int> cand;
		rep(j,A[i]) {
			for (const auto &u : umap) {
				string tmp;
				if (u.first == "-") tmp = S[i][j];
				else tmp = u.first + S[i][j];
				bool isFound = true;
				if (tmp.size() > T.size()) continue;
				rep(k,tmp.size()) {
					if (tmp[k] != T[k]) {
						isFound = false;
						break;
					}
				}
				if (isFound) {
					if (umap.count(tmp) > 0) {
						if (cand.count(tmp) > 0) cand[tmp] = min({cand[tmp],umap[tmp],u.second+1});
						else cand[tmp] = min(umap[tmp],u.second+1);
					} else {
						if (cand.count(tmp) > 0) cand[tmp] = min(cand[tmp],u.second+1);
						else cand[tmp] = u.second+1;
					}
				}
			}		
		}
		// update
		for (auto &c : cand) {
			if (umap.count(c.first) > 0) umap[c.first] = min(c.second,umap[c.first]);
			else umap[c.first] = c.second;
		}
	}
	if (umap.count(T) > 0) cout << umap[T] << endl;
	else cout << -1 << endl;

	return 0;
}