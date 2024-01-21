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
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	vector<int> num(N,0);
	repp(i,1,N) {
		if (S[i-1] == 'A' && S[i] == 'C') num[i] = num[i-1] + 1;
		else num[i] = num[i-1];
	}
	vector<int> ans;
	rep(q,Q) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		if (l == 0) ans.push_back(num[r]);
		else ans.push_back(num[r]-num[l]);
	}
	for (auto a : ans) {
		cout << a << endl;
	}

	return 0;
}