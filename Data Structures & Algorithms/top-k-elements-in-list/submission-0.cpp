class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> freq_vec;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto pair: freq) {
            freq_vec.push_back(make_pair(pair.first, pair.second));
        }
        nth_element(freq_vec.begin(), freq_vec.begin()+k-1, freq_vec.end(), 
            [](const auto& a, const auto& b) {
                return a.second > b.second;
            }
        );
        for (int i = 0; i < k; i++) {
            ans.push_back(freq_vec[i].first);
        }
        return ans;
    }
};
