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

int N;

vector<string> rotate(const vector<string> &s) {
	vector<string> tmp(s[0].size());
	rep(i,tmp.size()) {
		rep(j,s.size()) {
			tmp[i] += s[s.size()-j-1][i];
		}
	}
	return tmp;
}

vector<string> trimming(const vector<string> &V) {
	int row_min = INT_MAX, row_max = -1;
	int col_min = INT_MAX, col_max = -1;
	rep(i,N) rep(j,N) {
		if (V[i][j] == '#') {
			row_min = min(row_min,i);
			row_max = max(row_max,i);
			col_min = min(col_min,j);
			col_max = max(col_max,j);
		}
	}
	int ii = 0;
	vector<string> v(row_max+1-row_min);
	repp(i,row_min,row_max+1) {
		repp(j,col_min,col_max+1) {
			v[ii] += V[i][j];
		}
		ii++;
	}
	return v;
}

int main() {
	cin >> N;
	vector<string> S(N); rep(i,N) cin >> S[i];
	vector<string> T(N); rep(i,N) cin >> T[i];

	vector<string> s = trimming(S), t = trimming(T);

	rep(r,4) {
		if (s.size() == t.size() && s[0].size() == t[0].size()) {
			bool isFound = true;
			rep(i,s.size()) {
				rep(j,s[i].size()) {
					if (s[i][j] != t[i][j]) {
						isFound = false;
					}
				}
			}
			if (isFound) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		s = rotate(s);
	}
	cout << "No" << endl;
	return 0;
}