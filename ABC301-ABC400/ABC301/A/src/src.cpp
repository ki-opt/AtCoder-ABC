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
	string S;
	cin >> N >> S;
	int t = 0, a = 0;
	rep(i,S.size()) {
		if (S[i] == 'T') t++;
		else a++;
	}
	if (t > a) cout << "T" << endl;
	else if (t < a) cout << "A" << endl;
	else {
		if (S[S.size()-1] == 'T') cout << "A" << endl;
		else cout << "T" << endl;
	}
	return 0;
}