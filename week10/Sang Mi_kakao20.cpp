#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        int bs = 1;
        string before = s.substr(0, i), astr = "";
        for (int j = i; j < s.size() - i; j += i) {
            if (s.substr(j, i) == before) {
                bs++;
            }
            else {
                if (bs != 1) astr += to_string(bs);
                astr += before;
                bs = 1;
                before = s.substr(j, i);
            }
        }
        if (s.size() % i == 0 && s.substr(s.size() - i, i) == before) {
            bs++;
            astr += to_string(bs);
            astr += before;
        }
        else {
            if (bs != 1) astr += to_string(bs);
            astr += before;
            astr += s.substr(s.size() - ((s.size() % i == 0) ? i : s.size() % i), (s.size() % i == 0) ? i : s.size() % i);
        }
        answer = (astr.size() < answer) ? astr.size() : answer;
        //cout << astr << endl;
    }
    return answer;
}