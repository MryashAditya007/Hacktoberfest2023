// SOLUTION TO LEETCODE Question -> Search first and last position of an element in a sorted array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lo = findFirstOccurrence(nums, target);
        int hi = findLastOccurrence(nums, target);
        return {lo, hi};
    }

private:
    int findFirstOccurrence(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                hi = mid - 1;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }

    int findLastOccurrence(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                lo = mid + 1;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
