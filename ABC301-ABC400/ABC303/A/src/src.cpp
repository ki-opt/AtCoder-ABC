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
	string S, T;
	cin >> N >> S >> T;


	rep(i,N) {
		if (S[i] == T[i]) {

		} else if ((S[i] == '1' && T[i] == 'l') || (S[i] == 'l' && T[i] == '1')) {

		} else if ((S[i] == '0' && T[i] == 'o') || (S[i] == 'o' && T[i] == '0')) {

		} else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}