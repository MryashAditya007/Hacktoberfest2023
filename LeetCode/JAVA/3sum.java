import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int rsum = nums[0] + nums[1] + nums[2];
        int mindiff = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right;

                if (sum == target) {
                    return target;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }

                int difftarget = Math.abs(sum - target);

                if (difftarget < mindiff) {
                    rsum = sum;
                    mindiff = difftarget;
                }
            }
        }

        return rsum;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 4, 8, 16, 32};
        int target = 26;
        int result = solution.threeSumClosest(nums, target);
        System.out.println("Closest sum to " + target + " is: " + result);
    }
}
