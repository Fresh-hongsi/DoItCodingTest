#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<char,int> m;
	int totalSLen;
	int partSLen;
	string s;
	int A;
	int C;
	int G;
	int T;
	cin >> totalSLen >> partSLen;
	cin >> s;
	cin >> A >> C >> G >> T;
	int result = 0;

	for (int i = 0; i < partSLen; i++) {
		char cur = s[i];
		if (cur == 'A') {
			m['A']++;
		}
		else if (cur == 'C') {
			m['C']++;
		}
		else if (cur == 'G') {
			m['G']++;
		}
		else if (cur == 'T') {
			m['T']++;
		}
	}

	if (m['A'] >= A && m['C'] >= C && m['G'] >= G && m['T'] >= T) {
		//cout << 0 << '\n';
		result++;
	}

	for (int i = 1; i <= totalSLen - partSLen; i++) {
		char front = s[i - 1];
		m[front]--;
		char back = s[i + partSLen - 1];
		m[back]++;
		if (m['A'] >= A && m['C'] >= C && m['G'] >= G && m['T'] >= T) {
			result++;
			//cout << i << '\n';
		}
	}

	cout << result;
	

	
	return 0;
}
