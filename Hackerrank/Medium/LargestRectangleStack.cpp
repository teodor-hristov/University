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

long largestRectangle(vector<int> h) {
    stack<int> last{};
    vector<int> width(h.size(), 1);
    int max = 0;

    for (int i = 0; i < h.size(); ++i) {

        while(!last.empty() && h[i] <= h[last.top()]){
            last.pop();
        }

        if(!last.empty())
        {
            width[i] += i - last.top() - 1;
        }else
        {
            width[i] +=i;
        }

        last.push(i);
    }

    while(!last.empty())
    {
        last.pop();
    }

    for (int i = h.size() - 1; i >= 0; --i) {

        while(!last.empty() && h[i] <= h[last.top()]){
            last.pop();
        }

        if(!last.empty())
        {
            width[i] += last.top() - i - 1;
        }else
        {
            width[i] +=h.size() - 1 - i;
        }

        last.push(i);
    }

    for (int i = 0; i < width.size(); ++i) {
        max = std::max(max, width[i] * h[i]);
    }

    return max;
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
