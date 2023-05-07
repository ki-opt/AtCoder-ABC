#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int X;
	cin >> X;
	while(1) {
		int flag = 0;
		for (int i = 2; i <= (int)sqrt(X); i++) {
			if (X % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
	      cout << X << endl;
			return 0;
		}
		X++;
	}

	return 0;
}