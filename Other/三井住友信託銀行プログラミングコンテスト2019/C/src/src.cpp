#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int X;
	cin >> X;
	int N = 6;
	vector<int> value(N);
	value[0] = 100; value[1] = 101; value[2] = 102;
	value[3] = 103; value[4] = 104; value[5] = 105;
	vector<int> dp(X+1);
	dp[0] = 1;
	for(int x = 0; x <= X; x++) {
		for (int i = 0; i < N; i++) {
			if (x - value[i] >= 0) {
				if (dp[x-value[i]] == 1) dp[x] = 1;
			}
		}
	}
	if (dp[X] == 1) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}