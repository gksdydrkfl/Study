#include <iostream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	vector<string> park;
	vector<string> routes;
	vector<int> answer;

	park.push_back("SOO");
	park.push_back("OOO");
	park.push_back("OOO");

	routes.push_back("E 2");
	routes.push_back("S 2");
	routes.push_back("W 1");

	//routes.push_back("E 2");
	//routes.push_back("S 3");
	//routes.push_back("W 1");

	///*park.push_back("SOO");
	//park.push_back("OXX");
	//park.push_back("OOO");*/

	//park.push_back("OSO");
	//park.push_back("OOO");
	//park.push_back("OXO");
	//park.push_back("OOO");

	pair<int, int>curpos;

	for (int i = 0; i < park.size(); ++i)
	{
		for (int j = 0; j < park[i].length(); ++j)
		{
			if (park[i][j] == 'S')
			{
				curpos = { j, i };
			}
		}
	}

	//185억
	//130억
	for (int i = 0; i < routes.size(); ++i)
	{
		int dirx = 0;
		int diry = 0;
		switch (routes[i][0])
		{
		case 'N':
			diry = -1;
			break;
		case 'S':
			diry = 1;
			break;
		case 'W':
			dirx = -1;
			break;
		case 'E':
			dirx = 1;
			break;
		}

		int distance = routes[i][2] - 48;
		//int curx = curpos.first;
		//int cury = curpos.second;
		//int j = 0;
		//for (j = 0; j < distance; ++j)
		//{
		//	curx += dirx;
		//	cury += diry;

		//	if (park[j].size() <= curx || park.size() <= cury || 0 > curx || 0 > cury || park[cury][curx] == 'X')
		//	{
		//		break;
		//	}
		//}

		//if (j == distance)
		//{
		//	curpos.first = curx;
		//	curpos.second = cury;
		//}




		if (park[i].size() > (dirx * distance) + curpos.first && park.size() > (diry * distance) + curpos.second && (diry * distance) + curpos.second >= 0 && (dirx * distance) + curpos.first >= 0)
		{
			for (int j = 0; j < distance; ++j)
			{
				if (park[curpos.second + diry * (j + 1)][curpos.first + dirx * (j + 1)] == 'X')
				{
					break;
				}
				if (distance == j + 1)
				{
					curpos.first += dirx * distance;
					curpos.second += diry * distance;
				}
			}

		}
	}
	answer.push_back(curpos.first);
	answer.push_back(curpos.second);
	//return answer;
	std::cout << curpos.second << " " << curpos.first;
}
//soo
//ooo
//ooo

//soo
//oxx
//ooo

//oso
//ooo
//oxo
//ooo
