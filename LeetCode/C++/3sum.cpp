#include <cstdlib> // for abs function
#include <climits> // for INT_MAX constant
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int rsum=nums[0]+nums[1]+nums[2];
        int mindiff=INT_MAX;

        for(int i=0;i<nums.size()-2;i++){
            int left = i+1;
            int right = nums.size()-1;

            while(left<right){

                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target){
                    return target;
                }
                if(sum<target){
                    left++;
                }
                else{
                    right--;
                }

                int difftarget=(sum-target);
                if(difftarget<0){
                    difftarget=-difftarget;
                }
                if(difftarget<mindiff){
                    rsum=sum;
                    mindiff=difftarget;
                }
            }
        }

        return rsum;

        
    }
};
