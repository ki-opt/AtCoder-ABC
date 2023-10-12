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

	rep(i,S.size()) {
		char init = S[0];
		rep(i,S.size()-1) {
			S[i] = S[i+1];
		}
		S[S.size()-1] = init;
		if (S == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}	
	cout << "No" << endl;

	return 0;
}