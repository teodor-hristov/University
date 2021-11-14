#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

static const char openBrackets[] = "{[(";
static const char closeBrackets[] = "}])";

typedef enum
{
    foundOpenBracket = 0,
    foundCloseBracket
}
BracketState;

string isBalanced(string s) {
    int state;
    int closedIndexInArray;
    char* bracketPos;
    stack<char> opened{};

    if (s.length() % 2)
        return "NO";

    for (char & i : s) {
        bracketPos = (char *)strrchr(openBrackets, i);
        if (bracketPos != nullptr)
        {
            state = foundOpenBracket;
        }
        else
        {
            bracketPos = (char*)strrchr(closeBrackets, i);
            if (bracketPos != nullptr)
            {
                closedIndexInArray = bracketPos - closeBrackets;
                state = foundCloseBracket;
            }else
            {
                continue;
            }
        }

        switch (state) {
            case foundOpenBracket:
                opened.push(i);
                break;
            case foundCloseBracket:
                if ((!opened.empty()) &&
                (opened.top() == openBrackets[closedIndexInArray]))
                {
                    opened.pop();
                }
                else
                {
                    return "NO";
                }
                break;
        }
    }

    return opened.empty() ? "YES" : "NO";
}

int main()
{
   cout << isBalanced("[]{{");
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
