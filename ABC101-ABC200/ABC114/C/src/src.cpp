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

ll N;

void dfs(vector<ll> &ans, ll val) {
	for (ll i = 3; i <= 7; i += 2) {
		ll tmp = val * 10 + i;
		if (tmp > N) continue; 
		ans.push_back(tmp);
		dfs(ans, tmp);
	}
}

int main() {
	cin >> N;
	vector<ll> ans = {3,5,7};
	dfs(ans,3);
	dfs(ans,5);
	dfs(ans,7);
	
	vector<ll> true_ans;
	for (auto a : ans) {
		ll tmp = a;
		vector<bool> seen(9,false);
		while (tmp != 0) {
			seen[tmp % 10] = true;
			tmp /= 10;
		}
		if (seen[3] && seen[5] && seen[7]) true_ans.push_back(a);
	}

	cout << true_ans.size() << endl;

	return 0;
}