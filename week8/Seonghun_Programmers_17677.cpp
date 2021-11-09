#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    vector<string> string1;
    vector<string> string2;

    //모두 소문자로
    std::transform(str1.begin(), str1.end(), str1.begin(), (int (*)(int)) tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), (int (*)(int)) tolower);

    //알파벳 유무 검사후 넘어줌
    for (int i = 0; i < str1.length() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            string1.push_back(str1.substr(i, 2));
        }
    }

    for (int i = 0; i < str2.length() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            string2.push_back(str2.substr(i, 2));
        }
    }

    int hap = string1.size() + string2.size();
    if (hap == 0) return 65536; // 둘 다 비어있는 경우
    int cha = 0;
    //string1을 기준으로 string2에 중복되는 문자가 있는지 확인하고 지움
    for (auto i = string1.begin(); i != string1.end(); i++) {
        auto j = find(string2.begin(), string2.end(), *i);
        if (j != string2.end()) {
            string2.erase(j);
            cha ++;
        }
    }
    if (cha == 0) return 0; // 교집합 전혀 없음.
    int answer = floor(((double) cha / (hap-cha)) * 65536);
    return answer;
}
