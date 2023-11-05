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
	ull N;
	cin >> N;

	ull x = 0;
	while (N >= (ull)pow(2,x)) {
		if (N % ((ull)pow(2,x)) != 0) { x++; continue; }
		ull n = N / (ull)pow(2,x);
		ull y = 0;
		while (n >= (ull)pow(3,y)) {
			if (n == (ull)pow(3,y)) {
				cout << "Yes" << endl;
				return 0;
			}
			y++;
		}		
		x++;
	}

	cout << "No" << endl;

	return 0;
}