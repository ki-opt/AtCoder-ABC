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

#define PI 3.14159265359

void rotate(int &x, int &y) {
	int x2 = round(sqrt(2)*(cos(PI/4) * x - sin(PI/4) * y));
	int y2 = round(sqrt(2)*(sin(PI/4) * x + cos(PI/4) * y));
	x = x2; y = y2;
}

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int x3, y3;
	x3 = x2 - x1;
	y3 = y2 - y1;
	rotate(x3, y3);
	x3 += x1;
	y3 += y1;

	int x4, y4;
	x4 = x3 - x2;
	y4 = y3 - y2;
	rotate(x4, y4);
	x4 += x2;
	y4 += y2;

	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	return 0;
}