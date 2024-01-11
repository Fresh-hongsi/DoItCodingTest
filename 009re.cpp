#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	map<char, int> m; // 부분 문자열 내의 A C G T를 관리할 자료구조 
	int totalLength; // 문자열 전체 길이
	int partLength; // 부분 문자열 길이
	string s; // 입력받은 문자열
	 
	int acgt[4] = { 0, }; // 최소 기준 acgt 개수
	

	int result = 0; // 최종 결과값


	// 입력
	cin >> totalLength >> partLength >> s;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> acgt[i];
	}

	// 슬라이딩할 때의 해당 부분문자열의 가장 앞 인덱스
	int f_idx = 0;

	// 슬라이딩할 떄의 해당 부분문자열의 가장 뒤 인덱스
	int e_idx = partLength - 1;

	m['A'] = 0;
	m['C'] = 0;
	m['G'] = 0;
	m['T'] = 0;

	// 첫 부분문자열에 대해서는 직접 map을 채워주기
	for (int i = f_idx; i <= e_idx; i++)
	{
		m[s[i]]++;
	}

	if ((m['A'] >= acgt[0]) && (m['C'] >= acgt[1]) && (m['G'] >= acgt[2]) && (m['T'] >= acgt[3]))
	{
		result++;
	}

	

	// 슬라이딩 시키면서 변화되는 개수를 체크하고, 조건 만족하면 result 수 추가
	while (e_idx < totalLength-1)
	{
		// 부분 문자열의 가장 앞부분 문자의 value 감소시키기
		m[s[f_idx]]--;

		// f_idx 변경
		f_idx++;

		// e_idx 변경
		e_idx++;

		// 부분 문자열의 가장 뒷부분 문자의 value 증가시키기
		m[s[e_idx]]++;

		// 조건에 맞는 지 확인하고 추가하기
		if ((m['A'] >= acgt[0]) && (m['C'] >= acgt[1]) && (m['G'] >= acgt[2]) && (m['T'] >= acgt[3]))
		{
			result++;
		}
	}

	cout << result;
	return 0;


}
