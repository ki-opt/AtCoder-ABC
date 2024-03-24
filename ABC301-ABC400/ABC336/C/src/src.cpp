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
	ll N; cin >> N;
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	string ans = "";
	ll tmp = N - 1;
	while (tmp != 0) {
		ans.push_back('0'+tmp%5);
		tmp /= 5;
	}

	string v = "";
	rep(i,ans.size()) {
		int a = ans[i] - '0';
		v.push_back(a*2+'0');
	}
	reverse(v.begin(),v.end());

	cout << v << endl;
	return 0;
}