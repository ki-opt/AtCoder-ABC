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
	string S; cin >> S;
	vector<int> ans(26,0);
	rep(i,S.size()) {
		int val = S[i] - 'a';
		ans[val]++;
	}
	int tmp = *max_element(ans.begin(),ans.end());
	rep(i,ans.size()) {
		if (ans[i] == tmp) {
			char c = i + 97;
			cout << c << endl;
			return 0;
		}
	}


	return 0;
}