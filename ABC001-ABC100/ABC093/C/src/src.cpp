#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	vector<int> input = {A,B,C};

	sort(input.begin(),input.end(),greater<int>());

	int gusu = 0, kisu = 0;
	rep(i,3){
		if (input[i] % 2 == 0) gusu++;
		else kisu++;
	}

	int ans = 0;
	if (gusu == 3 || kisu == 3) {
		
	} else if (gusu > kisu) {
		rep(i,3) {
			if (input[i] % 2 == 0) {
				input[i]++;
			}
		}
		ans++;
	} else if (gusu < kisu) {
		rep(i,3) {
			if (input[i] % 2 == 1) {
				input[i]++;
			}
		}
		ans++;
	}

	sort(input.begin(),input.end(),greater<int>());
	while(input[0] != input[1]) {
		input[1]++;
		input[2]++;
		ans++;
	}
	ans += (input[1]-input[2])/2;
	cout << ans << endl;

	return 0;
}