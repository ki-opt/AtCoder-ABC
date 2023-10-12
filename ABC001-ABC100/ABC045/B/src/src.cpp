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
	string SA, SB, SC;
	cin >> SA >> SB >> SC;

	int a = 0, b = 0, c = 0;
	int turn = 0;
	while(!((a == SA.size() && turn == 0) || 
			(b == SB.size() && turn == 1) || 
			(c == SC.size() && turn == 2))) {
		if (turn == 0) {
			if (SA[a] == 'b') turn = 1;
			else if (SA[a] == 'c') turn = 2;
			a++;
		} else if (turn == 1) {
			if (SB[b] == 'a') turn = 0;
			else if (SB[b] == 'c') turn = 2;
			b++;
		} else if (turn == 2) {
			if (SC[c] == 'a') turn = 0;
			else if (SC[c] == 'b') turn = 1;
			c++;
		}
	}
	if (a == SA.size() && turn == 0) cout << 'A' << endl;
	else if (b == SB.size() && turn == 1) cout << 'B' << endl;
	else cout << 'C' << endl;

	return 0;
}