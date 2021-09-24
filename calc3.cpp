#include <iostream>
using namespace std;

int main()
{
	std::string s;
	int sum = 0, input;
	char op;
	cin >> input;
	char v = cin.peek();
	if (v == '^')
		input *= input;
	sum += input;
	if (v == '^')
		cin >> op;
	while (cin >> op)
	{
		if (op == ';')
		{
			cout << sum << endl;
			cin >> input;
			sum = input;
		}
		else
		{
			cin >> input;
			char check = cin.peek();
			bool c = (check == '^');
			if (c)
				input *= input;
			if (op == '+')
				sum += input;
			else if (op == '-')
				sum -= input;
			if (c)
				cin >> op;
		}
	}
	return 0;
}
