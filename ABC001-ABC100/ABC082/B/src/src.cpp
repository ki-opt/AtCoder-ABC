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
	string s, t;
	cin >> s >> t;

	sort(s.begin(),s.end());
	sort(t.begin(),t.end(),greater<int>());

	if (s.size() < t.size()) {
		rep(i,s.size()) {
			if (s[i] == t[i]) {
			} else if (s[i] > t[i]) {
				cout << "No" << endl;
				return 0;
			} else {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	} else if (s.size() >= t.size()) {
		rep(i,t.size()) {
			if (s[i] == t[i]) {
			} else {
				if (s[i] > t[i]) {
					cout << "No" << endl;
					return 0;
				} else {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
		cout << "No" << endl;
	} 
	return 0;
}