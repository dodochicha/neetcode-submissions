class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            if (dic[nums[i]]) {
                return std::vector<int>{dic[nums[i]] - 1, i};
            }
            else {
                dic[target - nums[i]] = i + 1;
            }
        }
    }
};
