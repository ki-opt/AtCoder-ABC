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

//struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
vector<ll> Eratosthenes( const ll N )
{
	vector<bool> is_prime( N + 1 );
	for( ll i = 0; i <= N; i++ )
	{
		is_prime[ i ] = true;
	}
	vector<ll> P;
	for( ll i = 2; i <= N; i++ )
	{
		if( is_prime[ i ] )
		{
			for( ll j = 2 * i; j <= N; j += i )
			{
					is_prime[ j ] = false;
			}
			P.emplace_back( i );
		}
	}
	return P;
}


vector<long long> sieve(ll MAXP){
	vector<long long> res;
	vector<int> mem(MAXP,0);
	for(int i=2;i<MAXP;i++){
		if(mem[i]){continue;}
		res.push_back(i);
		for(int j=i;j<MAXP;j+=i){mem[j]=1;}
	}
	return res;
}


int main() {
	ll N;
	cin >> N;
	vector<ll> sosu = sieve(288675);
	vector<ll> sosu_pow(sosu.size());
	rep(i,sosu_pow.size()) sosu_pow[i] = sosu[i] * sosu[i];
	
	ll ans = 0;
	rep(i,sosu.size()-2) {
		ll tmp = sosu[i] * sosu[i];
		if (tmp > N) break;
		repp(j,i+1,sosu.size()-1) {
			ll tmp_2 = tmp * sosu[j];
			if (tmp_2 > N) break;
			repp(k,j+1,sosu.size()) {
				if (tmp_2 * sosu[k] > N) {
					break;
				} else if (tmp_2 * sosu[k] * sosu[k] > N) {
					break;
				} else {
					ans++;
				}
			}
		}
	}
	/*rep(i,sosu.size()-2) {
		repp(j,i+1,sosu.size()-1) {
			int k = sosu.size()-1;
			while (sosu_pow[i] * sosu[j] * sosu_pow[k] > N && j < k) k--;
			ans += k - j;
		}
	}*/
	cout << ans << endl;
	return 0;
}