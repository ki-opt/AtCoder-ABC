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

int main() {
	string s;
	cin >> s;
	if (s.size() == 1) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}

	rep(i,s.size()-1) {
		if (s[i] == s[i+1]) {
			cout << i+1 << " " << i+2 << endl;
			return 0;
		}
		if (i == s.size()-3) {
			if (s[i+1] == s[i+2]) {
				cout << i+2 << " " << i+3 << endl;
				return 0;
			}
		}
	}
	rep(i,s.size()-2) {
		if (s[i] == s[i+2]) {
			cout << i+1 << " " << i+3 << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}