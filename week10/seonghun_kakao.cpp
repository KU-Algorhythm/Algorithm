#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length();

    if (s.length() == 1)
        return 1;

    for (int i = 1; i <= s.length() / 2; i++) {
        int count = 1;
        string sub = s.substr(0, i);

        string cmp, cp;

        for (int j = i; j < s.length(); j += i) {
            cmp = s.substr(j, i);

            if (!(sub.compare(cmp))) { count++; }
            else {
                if (count == 1) {
                    cp += sub;
                    sub = cmp;
                } else {
                    cp = cp + to_string(count) + sub;
                    sub = cmp;
                    count = 1;
                }
            }

            if (j + i >= s.length()) {
                if (count != 1) {
                    cp = cp + to_string(count) + sub;
                    break;
                } else {
                    cp = cp + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > cp.length()) ? cp.length() : answer;
    }
    return answer;
}