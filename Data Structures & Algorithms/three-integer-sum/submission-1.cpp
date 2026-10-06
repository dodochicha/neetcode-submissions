class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int a = i + 1;
            int b = n - 1;
            while (a < b) {
                if (nums[a] + nums[b] > - nums[i]) {
                    b--;
                    while (b >= 1 && nums[b] == nums[b+1]) {
                        b--;
                    }
                }
                else if (nums[a] + nums[b] < - nums[i]) {
                    a++;
                    while (a <= n - 2 && nums[a] == nums[a-1]) {
                        a++;
                    }
                }
                else {
                    ans.push_back(vector<int>{nums[i], nums[a], nums[b]});
                    b--;
                    while (b >= 1 && nums[b] == nums[b+1]) {
                        b--;
                    }
                    a++;
                    while (a <= n - 2 && nums[a] == nums[a-1]) {
                        a++;
                    }
                }
            }
        }
        return ans;
    }
};
