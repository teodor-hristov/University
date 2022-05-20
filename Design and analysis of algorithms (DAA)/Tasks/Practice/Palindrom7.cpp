#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
    int times_occured[1000] = {0};
    char str[100050] = {0};
    string result;

    cin >> str;
    int str_len = strlen(str);
    //cout << str_len << endl;

    for (int i = 0; i < str_len; i++)
    {
        //cout << str[i]-'a' << endl;
        times_occured[str[i]-'a']++;
    }

    // for (int i = 0; i < str_len; i++)
    // {
    //     cout << times_occured[i] << " " << endl;
    //     //times_occured[str[i]-'a']++;
    // }

    string pref;
    string suff;
    int isPossible = -1;
    int len = 0;

    for (int i = 0; i < 64; i++)
    {
        if (times_occured[i] % 2 != 0)
        {
            if (isPossible == -1)
                isPossible = i;
            else{
                printf("IMPOSSIBLE %d\n", i);
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for(int h = 0; h < times_occured[i]/2; h++){
            if (i != isPossible){
                pref.push_back((char)(i + 'a'));
                suff.push_back((char)(i + 'a'));
            }
        }

    len+= times_occured[i];
    }
    result.insert(0,times_occured[isPossible], isPossible+'a');
    printf("%s%s", pref.c_str(), result.c_str());
    for(int i = suff.length(); i >= 0; i--){
        printf("%c", suff[i]);
    }
    cout << endl;
}

//abaaba
//abazaba
