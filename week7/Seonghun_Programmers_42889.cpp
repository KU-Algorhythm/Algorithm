#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(const pair<double, int> &a, const pair<double, int> &b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second < b.second) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failrate;

    sort(stages.begin(), stages.end());

    int trynum = stages.size();
    int index = 0;

    for (int i = 1; i <= N; i++) {

        if (trynum == 0) {
            failrate.push_back(make_pair(0, i));
        }

        int failcnt = 0;
        while (stages[index] == i) {
            failcnt += 1;
            index++;
        }

        double rate = (double) failcnt / trynum;
        failrate.push_back(make_pair(rate, i));

        trynum -= failcnt;
    }
    sort(failrate.begin(), failrate.end(), comp);

    for (int i = 0; i < N; i++) {
        answer.push_back(failrate[i].second);
    }
