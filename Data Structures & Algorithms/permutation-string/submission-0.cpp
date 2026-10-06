class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> dict;
        int start = 0;
        for (int i = 0; i < s1.size(); i++) {
            dict[s1[i]]++;
        }
        int curLetter = 0;
        for (int i = 0; i < s2.size(); i++) {
            curLetter++;
            dict[s2[i]]--;
            while (dict[s2[i]] < 0) {
                dict[s2[start]]++;
                curLetter--;
                start++;
            }
            if (curLetter == s1.size()) return true;
        }
        return false;
    }
};
