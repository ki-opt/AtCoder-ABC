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
	string s;
	cin >> s;

	int ans;
	int start = -1;
	int end = -1;
	rep(i,s.size()) {
		if (s[i] == 'A' && start == -1) {
			start = i;
		}
		if (s[i] == 'Z') {
			end = i;
		}
	}
	cout << end - start + 1<< endl;

	return 0;
}