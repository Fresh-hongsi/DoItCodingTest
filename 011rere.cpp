#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <stack>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<int> dq;
	int N = 0;
	cin >> N;

	int temp = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		dq.push_back(temp);
	}
	
	int c = dq.front();
	dq.pop_front();
	int current = c+1;
	
	stack<int> st;
	vector<char> v;
	bool flag = true;

	for (int i = 1; i <= c; i++) {
		st.push(i);
		v.push_back('+');
	}
	st.pop();
	v.push_back('-');

	while (dq.size()>0) {
		
		
		c = dq.front();
		dq.pop_front();
		

		if (!st.empty() &&st.top() == c) {
			st.pop();
			v.push_back('-');
		}

		else if (!st.empty() && st.top() > c) {
			flag = false;
			break;
		}

		else if (!st.empty() && st.top() < c) {
			while (current <= c) {
				st.push(current++);
				v.push_back('+');
			}

			st.pop();
			v.push_back('-');
			
		}

		else if (st.empty()) {
			if (current <= c) {
				while (current <= c) {
					st.push(current++);
					v.push_back('+');
				}

				st.pop();
				v.push_back('-');
			}
			else {
				flag = false;
				break;
			}
		}



	}

	if (flag == true) {
		for (auto k : v) {
			cout << k << '\n';
		}
	}

	else {
		cout << "NO";
	}
	



	return 0;
}


