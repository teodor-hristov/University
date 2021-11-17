#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

long getArea(vector<int>& h)
{
    return (*std::min_element(h.begin(), h.end())) * h.size();
}

long largestRectangle(vector<int> h) {
    vector<int> possibleMaxBuilds{};
    vector<int> used{};
    long result = 0;
    int currentMaxElement = -1;
    int elementIdx = 0;

    while(*std::min_element(h.begin(), h.end()) != currentMaxElement)
    {
        currentMaxElement = 0;

        for (size_t i = 0; i < h.size(); ++i)
        {
            if (std::count(used.begin(), used.end(), i) == 0 && currentMaxElement <= h[i])
            {
                    currentMaxElement = h[i];
                    elementIdx = i;
            }
        }

        used.push_back(elementIdx);

        int tempIdx = elementIdx;
        while(true)
        {
            if (tempIdx >= 0)
            {
                possibleMaxBuilds.push_back(h[tempIdx]);
                tempIdx--;

                if (result < getArea(possibleMaxBuilds))
                {
                    result = getArea(possibleMaxBuilds);
                }
            }
            else
            {
                break;
            }
        }

        possibleMaxBuilds.clear();

        tempIdx = elementIdx;
        while(true)
        {
            if (h.size() - tempIdx > 1)
            {
                possibleMaxBuilds.push_back(h[tempIdx]);
                tempIdx++;

                if (result < getArea(possibleMaxBuilds))
                {
                    result = getArea(possibleMaxBuilds);
                }
            }
            else
            {
                break;
            }
        }

        possibleMaxBuilds.clear();
    }

    return result;
}

int main()
{
    vector<int> v{10,10,200,10,10};
    cout << largestRectangle(v) << endl;
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
