#include <iostream>
#include <list>

auto savelifenumber(int n, int k) {
    std::list<int> savelife;
    for(int i=1; i<=n; i++) savelife.push_back(i);
    auto killpoint = savelife.begin();
    while (savelife.size() > 2) {
        if((killpoint = savelife.erase(killpoint)) == savelife.end()) killpoint = savelife.begin();
        for (int i = 0; i < k-1 ; i++) {
            if(++killpoint == savelife.end()) killpoint = savelife.begin();
        }
    }
    return savelife;
}

int main() {
    auto result = savelifenumber(6, 3);
    std::cout << result.front() << " " <<result.back() << std::endl;
}

