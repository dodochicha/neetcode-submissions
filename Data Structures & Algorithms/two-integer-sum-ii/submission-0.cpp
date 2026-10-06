class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int a = 0;
        int b = n - 1;
        while (a < b && numbers[a] + numbers[b] != target) {
            if (numbers[a] + numbers[b] > target) {
                b--;
            }
            else {
                a++;
            }
        }
        return vector<int>{a+1, b+1};
    }
};
