class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // If k digits are still left, remove from the end
        while (k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeroes
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        return st.empty() ? "0" : st;
    }
};