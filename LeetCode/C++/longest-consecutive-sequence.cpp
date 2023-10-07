/*
This problem can be found on:
https://leetcode.com/problems/longest-consecutive-sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]); // insert all unique numbers into a set
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.count(nums[i] - 1)) // check if previous element of set was not there
            {
                int x = nums[i];
                int curr = 1;
                while (s.count(x + 1)) // find longest consecutive sequence starting with x
                {
                    x++;
                    curr++;
                }
                ans = max(ans, curr); // compare this sequence with the largest before it and update answer
            }
        }
        return ans;
    }
};