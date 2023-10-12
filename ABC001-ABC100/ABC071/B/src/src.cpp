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

	char moji;
	vector<int> check(26,0);
	for (int i = 0; i < S.size(); i++) {
		int cnt = 0;
		for (moji='a'; moji<='z'; moji++) {
			if (S[i] == moji) check[cnt] = 1;
			cnt++;
		}
	}
	
	int cnt = 0;
	for (moji='a'; moji<='z'; moji++) {
		if (check[cnt] == 0) {
			cout << moji << endl;
			return 0;
		}
		cnt++;
	}
	cout << "None" << endl;

	return 0;
}