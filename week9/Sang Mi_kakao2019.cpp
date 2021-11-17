#include <string>
#include <vector>
#include<algorithm>

using namespace std;

typedef struct STAGE
{
    double failure_rate;
    int stage_num;
}Stage;

bool compare(Stage a, Stage b)
{
    if (a.failure_rate == b.failure_rate)
        return a.stage_num < b.stage_num;

    else
        return a.failure_rate > b.failure_rate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Stage> s;
    int size = stages.size();
    double player_num[501] = { 0.0 };

    for (int i = 0; i < size; i++)
    {
        player_num[stages[i]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        double f = 0;
        if (player_num[i] == 0)
            f = 0;
        else
        {
            f = player_num[i] / size;
            size = size - player_num[i];
        }
        Stage stage;
        stage.failure_rate = f;
        stage.stage_num = i;

        s.push_back(stage);
    }

    sort(s.begin(), s.end(), compare);

    for (int i = 0; i < s.size(); i++)
        answer.push_back(s[i].stage_num);

    return answer;
}