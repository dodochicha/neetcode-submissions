class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> cnts;
        std::unordered_map<char, int> cntt;
        if (s.size() != t.size()) return false;
        for (char l: s) {
            cnts[l]++;
        }
        for (char l: t) {
            cntt[l]++;
        }
        for (auto& pair: cnts) {
            if (cnts[pair.first] != cntt[pair.first]) return false;
        }
        return true;
    }
};
