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
	string input;
	cin >> input;
	int a = input[0] - '0';
	int b = input[1] - '0';
	int c = input[2] - '0';
	int d = input[3] - '0';

	if (a + b + c + d == 7) cout << a << '+' << b << '+' << c << '+' << d << '=' << 7;
	else if (a + b + c - d == 7) cout << a << '+' << b << '+' << c << '-' << d << '=' << 7;
	else if (a + b - c + d == 7) cout << a << '+' << b << '-' << c << '+' << d << '=' << 7;
	else if (a - b + c + d == 7) cout << a << '-' << b << '+' << c << '+' << d << '=' << 7;
	else if (a + b - c - d == 7) cout << a << '+' << b << '-' << c << '-' << d << '=' << 7;
	else if (a - b + c - d == 7) cout << a << '-' << b << '+' << c << '-' << d << '=' << 7;
	else if (a - b - c + d == 7) cout << a << '-' << b << '-' << c << '+' << d << '=' << 7;
	else if (a - b - c - d == 7) cout << a << '-' << b << '-' << c << '-' << d << '=' << 7;

	return 0;
}