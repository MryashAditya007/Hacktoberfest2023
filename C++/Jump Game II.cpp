#include <iostream>
#include <vector>

int jump(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int jumps = 0;
    int currentEnd = 0;  // The current boundary of the farthest position that can be reached.
    int farthest = 0;     // The farthest position that can be reached from the current position.

    for (int i = 0; i < n - 1; i++) {
        farthest = std::max(farthest, i + nums[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    int minJumps = jump(nums);
    std::cout << "Minimum number of jumps: " << minJumps << std::endl;

    return 0;
}
