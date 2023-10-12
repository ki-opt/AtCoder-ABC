#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int K, A, B;
	cin >> K >> A >> B;

	long int ans = 0;
	if (A > B) {
		cout << 1 + K << endl;
		cerr << 1 << endl;
		return 0;
	} else {
		if (K > A) K -= (A + 1);
		else {
			cout << 1 + K << endl;
			cerr << 2 << endl;
			return 0;
		}
		long int tmp = 1;
		tmp += (K / (A + 1));
		ans += K % A + B * tmp;
		cout << max(K+1, ans) << endl;
		cerr << tmp << endl;
		cerr << ans << endl;
	}

	return 0;
}