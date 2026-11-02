class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
vector<int> freq(26, 0);


    for(char ch : tasks) {
        freq[ch - 'A']++;
    }

    int maxFreq = 0;
    int countMax = 0;

    for(int f : freq) {
        if(f > maxFreq) {
            maxFreq = f;
            countMax = 1;
        }
        else if(f == maxFreq) {
            countMax++;
        }
    }

    int ans = (maxFreq - 1) * (n + 1) + countMax;

    return max((int)tasks.size(), ans);
}


};
