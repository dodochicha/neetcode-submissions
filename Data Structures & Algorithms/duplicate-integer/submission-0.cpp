class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited[nums[i]] == 1) return true;
            else visited[nums[i]] = 1;
        }
        return false;
    }
};