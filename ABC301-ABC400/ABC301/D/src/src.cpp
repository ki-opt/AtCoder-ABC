#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <bitset>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	string S;
	long int N;
	cin >> S >> N;

	string n_binary = bitset<64>(N).to_string();

	int nmax_digit = 0;
	rep(i,n_binary.size()) {
		if (n_binary[i] == '1') nmax_digit = i;
	}
	rep(i,S.size()) {
		if (S[i] == '1') {
			if (i > nmax_digit) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if (nmax_digit >= S.size()) {
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '@') {
				S[i] = '1';
			}
		}
		// ここで出力
		stoi(S, 0, 2);
		return 0;
	}

	/*
	
	int flag_num = INT_MAX;
	for (int i = nmax_digit; i >= 0; i--) {
		if (n_binary[i] == '1') {
			flag_num = i;
			break;
		}
	}
	for (int i = S.size()-1; i>= 0; i--) {
		
	}*/

	return 0;
}