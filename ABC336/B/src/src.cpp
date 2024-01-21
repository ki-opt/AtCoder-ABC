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
#include <bitset>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	bitset<64> bs(N);
	int ans = 0;
	for (int i = 0; i < 64; i++) {
		if (bs[i] == 0) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}