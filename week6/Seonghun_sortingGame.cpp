#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;


int bfs(const vector<int> &perm, int arrSize) {
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    queue<vector<int>> q;
    map<vector<int>, int> distance;

    distance[perm] = 0;
    q.push(perm);
    while (!q.empty()) {
        vector<int> here = q.front();
        q.pop();

        if (here == sorted) return distance[here];
        int cost = distance[here];
        for (int i = 0; i < arrSize; i++)
        {
            for (int j = i + 2; j <= arrSize; ++j)
            {
                reverse(here.begin() + i, here.begin() + j);
                if (distance.count(here) == 0)
                {
                    distance[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
    return -1;
}

int main(void) {
    int arrSize;
    cin >> arrSize;

    vector<int> array(arrSize);

    for (int i = 0; i < arrSize; i++)
        cin >> array[i];

    int minSortNum;
    minSortNum = bfs(array, arrSize);
    cout << minSortNum << endl;
}
