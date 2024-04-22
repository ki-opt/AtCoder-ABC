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

vector<int> vec(26);
bool dict_order(const string &lhs, const string &rhs) {
	int length = min(lhs.size(),rhs.size());
	rep(i,length) {
		if (lhs[i] == rhs[i]) continue;
		if (vec[lhs[i]-'a'] < vec[rhs[i]-'a']) return true;
		else return false;
	}
	return lhs.size() < rhs.size();
}

int main() {
	string X; cin >> X;
	ll N; cin >> N;
	vector<string> S(N);
	rep(i,N) cin >> S[i];

	rep(i,X.size()) {
		vec[X[i]-'a'] = i;
	}
	sort(S.begin(),S.end(),dict_order);
	for (auto s : S) cout << s << endl;
	
	/*
	vector<int> vec(26);
	rep(i,X.size()) {
		vec[X[i]-'a'] = i;
	}

	vector<string> ans(N);
	rep(i,N) {
	}

	for (auto a : ans) {
		cout << a << endl;
	}*/

	return 0;
}