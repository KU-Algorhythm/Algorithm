//프로그래머스 12948 풀이-개별문제
#include <cstring>
#include <vector>
#include <iostream>
#

using namespace std;

string solution(string phone_number) {
    int arr_size = phone_number.length();
    char answer[arr_size];
    strcpy(answer, phone_number.c_str());
    memset(answer, '*', (arr_size-4) * sizeof(char));
    return answer;
}

int main(){
    std::cout << solution("027778888");
}