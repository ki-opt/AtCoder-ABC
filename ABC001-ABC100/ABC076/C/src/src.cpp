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
	string S_dash, T;
	cin >> S_dash >> T;
	
	bool found = false;
	int start = -1;
	rep(i,S_dash.size()) {
		bool flag = true;
		rep(j,T.size()) {
			if (S_dash[i+j] != T[j]) {
				if (S_dash[i+j] == '?') {
					continue;
				}
				flag = false; 
				break;
			}
		}
		if (flag) {
			start = i;
			found = true;
		}
	}
	if (found == false) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	
	char c = 'a';
	rep(i,S_dash.size()) {
		if (i == start) {
			rep(j,T.size()) {
				cout << T[j];
				i++;
			}
			i--;
		} else {
			if (S_dash[i] == '?') {
				cout << c;
			} else {
				cout << S_dash[i];
			}
		}
	}

	return 0;
}