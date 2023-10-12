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
	string w;
	cin >> w;
	vector<int> cnt(26,0);
	rep(i,w.size()) {
		char c = w[i];
		int tmp = c - 97;
		cnt[tmp]++;
	}
	rep(i,cnt.size()) {
		if (cnt[i] % 2 != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}