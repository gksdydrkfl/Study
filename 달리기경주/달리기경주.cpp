#include <iostream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<string> players;
    players.push_back("mumu");
    players.push_back("soe");
    players.push_back("poe");
    players.push_back("kai");
    players.push_back("mine");

    vector<string> callings;
    callings.push_back("kai");
    callings.push_back("kai");
    callings.push_back("mine");
    callings.push_back("mine");

    for (int i = 0; i < players.size(); ++i)
    {
        cout << players[i] << " ";
    }

    map<string, int> mp;

    for (int i = 0; i < players.size(); ++i)
    {
        mp[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); ++i)
    {
        int index = mp[callings[i]];
        int a = mp[players[index - 1]]++;
        int b = mp[callings[i]]--;

        string temp = players[index];
        players[index] = players[index - 1];
        players[index - 1] = temp;
    }

    cout << endl;

    for (int i = 0; i < players.size(); ++i)
    {
        cout << players[i] << " ";
    }
}
