/*
This problem can be found on:
https://leetcode.com/problems/longest-common-prefix

Write a function to find the longest common prefix string amongst an array of strings.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end()); // sort the strings in alphabetical order
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string ans = "";
        int mn = min(first.size(), last.size()); // choose the smaller of the first and last string
        for (int i = 0; i < mn; i++) // compare every character of first and last string
        {
            if (first[i] != last[i]) // stop when different character is found
            {
                return ans;
            }
            ans += first[i]; // add same characters to the answer
        }
        return ans;
    }
};