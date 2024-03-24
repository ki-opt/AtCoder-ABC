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
	ll A, B, X; cin >> A >> B >> X;
	if (A * 1 + B * 1 > X) {
		cout << 0 << endl;
		return 0;
	}
	ll left = 0, right = 1e9 + 1;
	while (right > 1 + left) {
		ll mid = (left + right) / 2;
		ll keta = 1, tmp = mid / 10;
		while (tmp != 0) {
			keta++;
			tmp = tmp / 10;
		}
		if (A * mid + B * keta <= X) left = mid;
		else right = mid; 
	}
	cout << right - 1 << endl;

	return 0;
}