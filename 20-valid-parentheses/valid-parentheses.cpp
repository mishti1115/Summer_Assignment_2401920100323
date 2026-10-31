class Solution {
public:
    bool isValid(string s) {
        while (true) {
            int pos = s.find("()");

            if (pos == -1) pos = s.find("{}");
            if (pos == -1) pos = s.find("[]");

            if (pos == -1) break;

            s.erase(pos, 2);
        }

        return s.empty();
    }
};