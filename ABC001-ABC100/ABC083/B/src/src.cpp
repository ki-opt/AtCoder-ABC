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
	int N, A, B;
	cin >> N >> A >> B;

	int ans = 0;
	rep(i,N+1) {
		int n = i;
		int sum = 0;
		while (n != 0) {
			sum += (n % 10);
			n /= 10;
		}
		if (sum >= A && sum <= B) ans += i;
	}
	cout << ans << endl;

	return 0;
}