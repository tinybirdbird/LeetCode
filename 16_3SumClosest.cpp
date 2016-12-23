class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int front = i + 1;
            int rear = nums.size() - 1;
            while (front < rear) {
                int temp = nums[i] + nums[front] + nums[rear];
                if (abs(temp - target) < abs(result - target)) {
                    result = temp;
                }
                if (temp < target) {
                    ++front;
                }
                else if (temp > target) {
                    --rear;
                }
                else {
                    return temp;
                }
            }
        }
        return result;
    }
};
