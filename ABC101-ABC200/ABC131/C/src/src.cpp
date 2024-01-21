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

ull gcd(ull a, ull b) {
	if (a % b == 0) return b;
	else return gcd(b, a%b);
}

ull lcm(ull a, ull b) {
	return (a/gcd(a,b))*b;
}

int main() {
	ull A, B, C, D;
	cin >> A >> B >> C >> D;
	
	ull ans = B - A + 1;

	ull c = B / C - A / C;
	if (A % C == 0) c++;
	//if (B % C == 0) c--;
	if (c < 0) c = 0;
	
	ull d = B / D - A / D;
	if (A % D == 0) d++;
	//if (B % D == 0) d--;
	if (d < 0) d = 0;

	ull kobaisu = lcm(C,D);
	ull mid = B / kobaisu - A / kobaisu;
	if (A % kobaisu == 0) mid++;

	cout << ans - (c + d - mid) << endl;

	return 0;
}