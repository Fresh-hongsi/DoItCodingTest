#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> timeSlot; // 회의 시간표들을 저장(시작시간,종료시간)
int N = 0;


bool comp(pair<int, int>a, pair<int, int> b)
{
	// 종료 시간이 빠른 순서대로 정렬
	if (a.second != b.second)
	{
		return a.second < b.second;
	}
	

	// 만약 종료 시간이 같다면, 시작 시간이 빠른 순으로 정렬
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	// 회의 시간들 입력
	for (int i = 0; i < N; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;

		timeSlot.push_back(make_pair(start, end));

	}

	// 회의 종료 시간이 빠른 순으로, 만약 종료 시간이 같다면 시작 시간이 빠른 순으로 정렬
	// 1,2  2,2 일 때 2개를 count하기 위함
	sort(timeSlot.begin(), timeSlot.end(),comp);

	int result = 0;
	int curEnd = -1; 
	
	// 현재까지 구한 회의의 마지막 기준을 업데이트해가며 count하기
	for (int i = 0; i < timeSlot.size(); i++)
	{
		if (curEnd <= timeSlot[i].first)
		{
			curEnd = timeSlot[i].second;
			result++;
		}
	}

	cout << result;
	return 0;

}
