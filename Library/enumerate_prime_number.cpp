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
