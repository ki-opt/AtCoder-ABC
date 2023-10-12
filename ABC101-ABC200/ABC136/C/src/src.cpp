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
	int N;
	cin >> N;
	vector<int> H(N);
	rep(i,N) cin >> H[i];

	rep(i,N-1) {
		if (H[i] < H[i+1]) H[i+1]--;
		if (H[i] > H[i+1]) {
			cout << "No" << endl;
		}
	}
	cout << "Yes" << endl;

	return 0;
}