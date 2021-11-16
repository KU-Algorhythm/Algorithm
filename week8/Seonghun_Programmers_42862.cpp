
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int arr[n];
    int out = 0;
    int answer = 0;
    std::fill_n(arr, n, 1);
    vector<int>::iterator iter;
    for (iter = lost.begin(); iter != lost.end(); iter++) { arr[(*iter - 1)]--; }
    for (iter = reserve.begin(); iter != reserve.end(); iter++) { arr[(*iter - 1)]++; }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            out++;
            if (i != n - 1 && arr[i + 1] == 2) {
                if (i != 0 && arr[i - 1] != 2) {
                out--;
                arr[i + 1]--;
                }
                else{
                    out--;
                    arr[i - 1]--;
                }

            }else if (i != 0 && arr[i - 1] == 2) {
                if (i != n - 1 && arr[i + 1] == 2) {
                    out--;
                    arr[i - 1]--;
                }
                out--;
                arr[i + 1]--;
            }
        }
    }
    answer = n - out;
    return answer;
}


int main() {
    vector<int> lost;
    lost.push_back(3);
    vector<int> reserve;
    reserve.push_back(1);
    cout << solution(2, lost, reserve);
    return 0;
}
