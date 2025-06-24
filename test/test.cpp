#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int n = s.length();
    if (n == 0)
        return (0);
    
    unordered_set<char> charSet;
    int maxLen = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        while (charSet.find(s[right]) != charSet.end())
        {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return (maxLen);
}

int main()
{
    string s = "abcabcbb";

    cout << solution(s) << endl;
}