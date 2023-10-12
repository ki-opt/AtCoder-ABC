#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    // 素因数分解を行う
    vector<long long> factors;
    long long gcd = __gcd(A, B); // C++17以降
    for (long long i = 2; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            factors.push_back(i);
            while (gcd % i == 0) {
                gcd /= i;
            }
        }
    }
    if (gcd > 1) {
        factors.push_back(gcd);
    }

    // 素因数同士が互いに素であることを確認しながら異なる素因数の数を数える
    int answer = 1; // 1を最初に選ぶ
    for (int i = 0; i < factors.size(); i++) {
        bool isCoprime = true;
        for (int j = 0; j < i; j++) {
            if (__gcd(factors[i], factors[j]) != 1) {
                isCoprime = false;
                break;
            }
        }
        if (isCoprime) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
/*#include <iostream>
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
	ll A, B;
	cin >> A >> B;

	if (B > A) {
		ll tmp = A;
		A = B;
		B = tmp;
	}

	vector<ll> ans;
	for (ll i = 2; i * i <= B; i++) {
		if (A % i == 0 && B % i == 0) ans.push_back(i);
	}

	ll val = (ll)ans.size();
	for (ll i = 0; i < val - 1; i++) {
		ll b = ans[i];
		if (b == 1) continue;
		for (ll j = i + 1; j < val; j++) {
			ll a = ans[j];
			if (a % b == 0) {
				ans.erase(ans.begin() + j);
				j--;
				val--;
			}
		}
	}
	cout << val + 1 << endl;

	return 0;
}*/