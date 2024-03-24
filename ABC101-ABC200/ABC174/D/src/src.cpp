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
	string c; cin >> c;
	/*
	bool isFound = false;
	rep(i,N-1) if (c[i] == 'W' && c[i+1] == 'R') isFound = true;
	if (!isFound) {
		cout << 0 << endl;
		return 0;
	}
	*/

	int left_r = 0;
	while (c[left_r] == 'R') left_r++;
	ll ans = 0;
	for (int i = N-1; i > 0; i--) {
		if (c[i] == 'R' && left_r < i) {
			ans++;
			left_r++;
			while(c[left_r] == 'R') left_r++;
		}
	}
	cout << ans << endl;

	/*
	bool isFirst = true;
	int first_r = -1;
	ll ans = 0;
	rep(i,N) {
		if (c[i] == 'R') {
			if (isFirst) first_r = i, isFirst = false;
			else ans++;
		}
	}
	if (ans < first_r) ans++;
	cout << ans << endl;
	*/
	return 0;
}