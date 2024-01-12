#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;
	stack<int> st;
	vector<char> s;
	bool flag = false;

	int num = 0;
	int idx = 0; 
	cin >> num;

	// 입력
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	int max = 0; // 현재 어디까지 가봤는지 확인하기 위함
	
	

	while (idx < num)
	{
		
		int next = arr[idx];

		if (next > max)
		{
			for (int i = max+1; i <= next; i++)
			{
				st.push(i);
				s.push_back('+');
			}

			max = next;
			continue;
		}

		if (!st.empty() && st.top() == arr[idx])
		{
			st.pop();
			s.push_back('-');
			idx++;
			continue;
		}



		if (st.top() > arr[idx])
		{
			cout << "NO" << '\n';
			flag = true;
			break;
		}
	}

	if (flag == false)
	{
		for (int i = 0; i < s.size(); i++)
		{
			cout << s[i] << '\n';
		}
	}


	return 0;


}

