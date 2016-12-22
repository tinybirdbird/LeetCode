/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        //vector<int> ret_i;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
        for (int i = 0; i < static_cast<long>(nums.size()) - 2; ++i) {
           int sum = -nums[i];
           int prev = i + 1;
           int rear = nums.size() - 1;
           if (sum < 0) {
               break;
           }
           while (prev < rear) {
               if (nums[prev] + nums[rear] < sum) {
                   ++prev;
               }
               else if (nums[prev] + nums[rear] > sum) {
                   --rear;
               }
               else {
                    ret.push_back(vector<int>{nums[i], nums[prev++], nums[rear--]});
                    while (prev < rear && nums[prev] == nums[prev - 1]) ++prev;
                    while (prev < rear && nums[rear] == nums[rear + 1]) --rear;
               }


           }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++ i;
        }
        return ret;
    }
};
