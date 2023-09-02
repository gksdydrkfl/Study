#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<string> name;
    vector<int> yearning;
    vector<int> value;
    vector<string> n1;
    vector<string> n2;
    vector<string> n3;
    vector<vector<string>> photo;

    name.push_back("may");
    name.push_back("kein");
    name.push_back("kain");
    name.push_back("radi");

    yearning.push_back(5);
    yearning.push_back(10);
    yearning.push_back(1);
    yearning.push_back(3);

    n1.push_back("may");
    n1.push_back("kein");
    n1.push_back("kain");
    n1.push_back("radi");

    n2.push_back("may");
    n2.push_back("kein");
    n2.push_back("brin");
    n2.push_back("deny");

    n3.push_back("kon");
    n3.push_back("kain");
    n3.push_back("may");
    n3.push_back("coni");

    photo.push_back(n1);
    photo.push_back(n2);
    photo.push_back(n3);

    map<string, int> m;

    for (int i = 0; i < name.size(); ++i)
    {
        m[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); ++j)
        {
            sum += m[photo[i][j]];
        }
        value.push_back(sum);
    }

    for (int i = 0; i < value.size(); ++i)
    {
        cout << value[i] << " ";
    }
}
