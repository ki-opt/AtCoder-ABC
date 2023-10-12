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
	string S, T;
	cin >> S >> T;

	vector<int> s(26,0), t(26,0);
	int s_at = 0, t_at = 0;
	rep(i,S.size()) {
		if (S[i] == '@') s_at++;
		else {
			char tmp = S[i];
			s[tmp-97]++;
		}
		if (T[i] == '@') t_at++;
		else {
			char tmp = T[i];
			t[tmp-97]++;
		}
	}

	rep(i,26) {
		if (s[i] != t[i]) {
			if (!(i == 0 || i == 19 || i == 2 || i == 14 || i == 3 || i == 4 || i == 17)) {
				cout << "No" << endl;
				return 0;
			} 
			if (s[i] < t[i]) {
				if (s_at <= 0) {
					cout << "No" << endl;
					return 0;
				}
				for (int j = s[i]+1; j <= t[i]; j++) {
					s_at--;
					if (s_at < 0) {
						cout << "No" << endl;
						return 0;
					}
				}
			} else if (s[i] > t[i]) {
				if (t_at <= 0) {
					cout << "No" << endl;
					return 0;
				}
				for (int j = t[i]+1; j <= s[i]; j++) {
					t_at--;
					if (t_at < 0) {
						cout << "No" << endl;
						return 0;
					}
				}
			}
		} 
	}
	cout << "Yes" << endl;

	return 0;
}