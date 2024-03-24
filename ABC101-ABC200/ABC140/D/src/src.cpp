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

int N, K;

int func(char c, char c_inv, string S) {
	vector<pair<int,int>> tmp;
	rep(i,N) {
		if (S[i] == c) {
			int i_dash = i+1;
			while (i_dash < N && S[i_dash] == c) i_dash++;
			tmp.push_back({i,i_dash});
			i = i_dash - 1;
		}
	}

	if (tmp.size() == 0) return 0;
	rotate(tmp.rbegin(),tmp.rbegin()+1,tmp.rend());
	reverse(tmp.begin(),tmp.end());
	int cnt = 0;
	for (auto p : tmp) {
		repp(i,p.first,p.second) S[i] = c_inv;
		if (++cnt >= K) break;
	}

	int ans = 0;
	rep(i,N-1) if (S[i] == S[i+1]) ans++;
	return ans;
}

int main() {
	string S;
	cin >> N >> K >> S;

	int ans = 0;
	ans = max(func('L','R',S),func('R','L',S));

	cout << ans << endl;

	return 0;
}