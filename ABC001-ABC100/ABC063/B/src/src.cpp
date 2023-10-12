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
	cin >> S;

	rep(i,S.size()) {
		repp(j,S.size(),i+1) {
			if (S[i] == S[j]) {
				cout << "no";
				return 0;	
			}
		}
	}
	cout << "yes";

	return 0;
}