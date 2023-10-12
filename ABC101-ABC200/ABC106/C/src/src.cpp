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
	string S;
	long int K;
	cin >> S >> K;

	rep(i,S.size()) {
		if (S[i] != '1') {
			cout << S[i] << endl;
			return 0;
		} else if (S[i] == '1' && i + 1 == K) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}