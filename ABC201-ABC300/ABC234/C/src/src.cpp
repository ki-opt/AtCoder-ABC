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
#include <bitset>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ull K;
	cin >> K;

	bitset<64> bs(K);

	bool isOne = false;
	rep(i,64) {
		if (bs[63-i] == 1) { cout << 2; isOne = true;}
		else if (bs[63-i] == 0 && isOne) cout << 0;
	}

	return 0;
}