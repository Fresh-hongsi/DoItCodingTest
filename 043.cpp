#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


long long gcd(long long max, long long min)
{
	if (max % min == 0)
	{
		return min;
	}

	else
	{
		return gcd(min, max % min);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a;
	long long b;

	cin >> a >> b;

	long long result = gcd(max(a, b), min(a, b));

	for (int i = 0; i < result; i++)
	{
		cout << '1';
	}

	return 0;
}
