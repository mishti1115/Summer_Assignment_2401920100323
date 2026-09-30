class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        stringstream ss(s);

        while (ss >> word)
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> used;

        for (int i = 0; i < pattern.size(); i++) {

            char c = pattern[i];
            string w = words[i];

            if (mp.count(c) && mp[c] != w)
                return false;

            if (used.count(w) && used[w] != c)
                return false;

            mp[c] = w;
            used[w] = c;
        }

        return true;
    }
};