class Solution {
public:
    int getDay(string s) {
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));

        int total = day;

        for (int i = 0; i < month - 1; i++) {
            total += days[i];
        }

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int aStart = getDay(arriveAlice);
        int aEnd = getDay(leaveAlice);

        int bStart = getDay(arriveBob);
        int bEnd = getDay(leaveBob);

        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        return max(0, end - start + 1);
    }
};
