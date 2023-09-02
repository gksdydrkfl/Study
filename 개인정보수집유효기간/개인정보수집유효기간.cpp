#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	string today = "2022.05.19";
	vector<int> answer;
	vector<string> terms;
	vector<int> nums;
	terms.push_back("A 6");
	terms.push_back("B 12");
	terms.push_back("C 3");

	vector<string> privacies;

	privacies.push_back("2021.05.02 A");
	privacies.push_back("2021.07.01 B");
	privacies.push_back("2022.02.19 C");
	privacies.push_back("2022.02.20 C");

	int year = stoi(today.substr(0, 4));
	int month = stoi(today.substr(5, 2));
	int day = stoi(today.substr(8, 2));
	int date = year * 28 * 12 + month * 28 + day;

	map<char, int> m;

	for (int i = 0; i < terms.size(); ++i)
	{
		stringstream ss(terms[i]);
		char ch;
		int month;
		ss >> ch;
		ss >> month;
		m[ch] = month;
	}

	for (auto privacie : privacies)
	{
		//679,056 140 2 168
		int year = stoi(privacie.substr(0, 4));
		int month = stoi(privacie.substr(5, 2));
		int day = stoi(privacie.substr(8, 2));
		int totaldate = year * 28 * 12 + month * 28 + day + m[privacie[11]] * 28;
		nums.push_back(totaldate);
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] <= date)
		{
			answer.push_back(i + 1);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		std::cout << answer[i] << " ";
	}
}
