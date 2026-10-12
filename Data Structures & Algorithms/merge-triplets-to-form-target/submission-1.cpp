class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        const int n = triplets.size();
        vector<bool> valid(n, false);
        vector<bool> meet(3, false);
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                if (triplets[i][0] == target[0]) meet[0] = true;
                if (triplets[i][1] == target[1]) meet[1] = true;
                if (triplets[i][2] == target[2]) meet[2] = true;
            }
        }
        return (meet[0] && meet[1] && meet[2]);
    }
};
