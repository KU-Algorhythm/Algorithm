#include <stack>
#include <iostream>

using namespace std;

bool solution(const string& str) {
    stack<int> bracketStack;
    const string bracketOpen("[{("), bracketClose("]})");
    int index;
    for(int i=0;i<str.size();i++){
        if((index = bracketOpen.find(str[i])) != -1) {
            bracketStack.push(index);
        }
        else {
            if (bracketStack.empty()) return false;
            if (bracketClose[bracketStack.top()] != str[i]) return false;
            bracketStack.pop();
        }
    }
    if(!bracketStack.empty()) return false;
    return true;
}

int main(){
    std::cout << solution("()");
}