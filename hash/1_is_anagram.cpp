#include <iostream>
#include <string>

using namespace std;

bool is_anagram(const string& s, const string& t)
{
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        record[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        record[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (record[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "rat";
    string t = "car";
    cout << is_anagram(s, t) << endl;
    return 0;
}
