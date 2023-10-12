#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

#define MODVAL 1000000007

int main() {
	int N;
	string S1, S2;
	cin >> N >> S1 >> S2;

	//vector<int> tate;
	ll ans = 0;
	rep(i,N) {
		if (S1[i] == S2[i]) {
			if (i == 0) {
				ans = 3;
			} else {
				if (S1[i-1] == S2[i-1]) {
					ans = (ans * 2) % MODVAL;
				} else {
					ans = ans;
				}
			}
		} else {
			if (i == 0) {
				ans = 3 * 2;
			} else {
				if (S1[i-1] == S2[i-1]) {
					ans = (ans * 2 * 1) % MODVAL;
				} else {
					ans = (ans * 3) % MODVAL;
				}
			}
			i++;
		}
		cerr << ans << endl;
	}
	cout << ans << endl;

	return 0;
}