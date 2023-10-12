#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <bits/stdc++.h>
#include <atcoder/modint>

using ull=unsigned long long;
using ll=long long;
using namespace std;
using namespace atcoder;
using mint = modint998244353;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int Q;
	cin >> Q;
	vector<int> query(Q);
	deque<int> S;
	S.push_back(1);
	mint ans = 1;
	rep(i,Q) {
		cin >> query[i];
		if (query[i] == 1) {
			int tmp;
			cin >> tmp;
			S.push_back(tmp);
			ans = ans * 10 + tmp;
		} else if (query[i] == 2) {
			ans -= mint(10).pow(S.size()-1) * S.front();
			S.pop_front();
		} else if (query[i] == 3) {
			cout << ans.val() << endl;
		}
	}

	

	return 0;
}