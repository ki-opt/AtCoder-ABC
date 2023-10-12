#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, j, n) for (int i = (int)j; i < (int)(n); i++)

int main() {
	string S;
	cin >> S;
	
	int near_val = 0;
	rep(i,S.length()-2) {
		int tmp = int(S[i]-'0') * 100 + int(S[i+1]-'0') * 10 + int(S[i+2]-'0');
		if (abs(tmp-753) < abs(near_val-753)) near_val = tmp;
	}
	cout << abs(near_val - 753) << endl;

	return 0;
}