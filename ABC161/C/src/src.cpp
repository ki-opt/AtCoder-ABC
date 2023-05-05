#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long int N, K;
	cin >> N >> K;

	long int ans = N % K;
	if (abs(ans - K) < ans) {
		cout << abs(ans - K) << endl;
		return 0;
	} else {
		cout << ans << endl;
		return 0;
	}

	return 0;
}