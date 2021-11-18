#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'poisonousPlants' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY p as parameter.
 */

int poisonousPlants(vector<int> p) {
    int lastDied = -1;
    int lastNotDied = -1;
    vector<int> days(p.size(), 0);

    for (int i = 0; i < p.size() - 1; ++i)
    {
        if(p[i] < p[i+1])
        {
            if(days[i] == 0)
            {
                lastNotDied = i;
                days[i+1] = days[i] + 1;
            }
            else
            {
                days[i+1] = days[lastNotDied] + 1;
            }

            lastDied = i + 1;

        }
        else
        {
            if (days[i] != 0)
            {
                if (p[i+1] <= p[lastNotDied])
                {
                    lastNotDied = i + 1;
                }
                else
                {
                    days[i+1] = days[lastDied] + 1;
                    lastDied = i + 1;
                }
            }
            else
            {
                lastNotDied = i + 1;
            }
        }
    }

    return *std::max_element(days.begin(), days.end());
}

int main()
{
//    vector<int> p = {3,1,10,7,3,5,6,6}; //5
//    cout << poisonousPlants(p) << endl;

//    vector<int> p1 = {20,5,6,15,2,2,17,2,11,5,14,5,10,9,19,12,5}; //4
//    cout << poisonousPlants(p1) << endl;

    vector<int> p2= {4,3,7,5,6,4,2}; //3
    cout << poisonousPlants(p2) << endl;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
