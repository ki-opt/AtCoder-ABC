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
	string O, E;
	cin >> O >> E;

	if ((O.size()+E.size())%2==0) {
		rep(i,O.size()){
			cout << O[i] << E[i];
		}
	} else {
		cout << O[0];
		rep(i,E.size()){
			cout << E[i] << O[i+1];
		}
	}

	return 0;
}