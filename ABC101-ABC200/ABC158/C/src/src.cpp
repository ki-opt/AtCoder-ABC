#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int A, B;
	cin >> A >> B;
	int ans = A;
	while(1) {
		int a = 0.08 * ans, b = 0.10 * ans;
		if (a == A && b == B) {
			cout << ans << endl;
			return 0;
		}
		ans++;
		if (ans > 1000) {
			cout << -1 << endl;
			return 0;
		}
	}

	return 0;
}