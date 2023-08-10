#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int N = 0;

/*
문제 풀이 핵심: 어느 숫자가 제일 기존 위치에서 앞으로 멀리 이동했는지 알면됨
				최대값 +1 해주면 정답! (문제는 i,j가 1부터 시작했으므로 +1해주어야함)
*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	vector<pair<int, int>> vp(N);
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		
		vp[i].first = temp; //숫자: first에 저장
		vp[i].second = i; //인덱스: second에 저장
	}

	sort(vp.begin(), vp.end()); //vector<pair>은 first기준으로 오름차순 정렬된다!!!!!

	//인덱스값의 최대값 찾기
	//정렬 전 인덱스 - 정렬 후 인덱스가 가장 큰 값 찾기(가장 앞으로 멀리 온 것 찾기)
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (vp[i].second - i > max)
		{
			max = vp[i].second - i;
		}
	}
	cout << max+1;

	
	return 0;
	
}
