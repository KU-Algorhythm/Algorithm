#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        vector<int> reverse;
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            reverse.push_back(k);
        }
        for (int i = n - 1; i >= 0; i--) {
            int j = i;
            int move = reverse[j];
            //i>0 안걸어주면 vector out of range 오류 뜸.
            while (i>0&&reverse[j]--) {
                swap(arr[i-move], arr[i-move+1]);
                i++;
            }
            i = j;
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}