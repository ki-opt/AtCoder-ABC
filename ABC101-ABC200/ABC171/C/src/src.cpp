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
	ll n = N;
	string ans;
	while (n > 0) {
		ll val;
		if (n % 26 == 0) n--, val = n % 26;
		else val = n % 26 - 1;
		char c = val + 'a';
		//cerr << c << " " << val << endl;
		ans = c + ans;
		n /= 26;
	}
	cout << ans << endl;
	return 0;
}