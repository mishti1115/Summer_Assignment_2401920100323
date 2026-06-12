class Solution {
public:
    int compress(vector<char>& chars) {
        int temp = 1;
        int left = 1;
        stack<int> st;
        for (int i = 1; i <= chars.size(); i++) {
            if (i != chars.size() && chars[i] == chars[i - 1]) {
                temp++;
            } else {
                if (temp > 1) {
                    while (temp > 0) {
                        st.push(temp % 10);
                        temp /= 10;
                    }
                }
                while (!st.empty()) {
                    chars[left] = (char)(st.top() + '0');
                    st.pop();
                    left++;
                }
                if (i != chars.size()) {
                    chars[left] = chars[i];
                    left++;
                    temp = 1;
                }
            }
        }
        return left;
    }
};
