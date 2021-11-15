#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FLAG -1
int main(void)
{
    
    vector<float> failureRates;
    vector<int> stages = { 1,1,1,1,1 };
    int N = 2;
    vector<int> answer;
    int p = stages.size();

    for(int i=0; i<N; i++)
    {
        int stageCount = count(stages.begin(), stages.end(), (i+1));
        float failureRate;
        if(p != 0)
            failureRate = (float)stageCount / (float)p;
        else
            failureRate = 0;
            
        failureRates.push_back(failureRate);
        p -= stageCount;
    }
    
    for(int i=0; i<failureRates.size(); i++)
    {
        int max_idx = max_element(failureRates.begin(), failureRates.end()) - failureRates.begin();
        failureRates[max_idx] = FLAG;
        answer.push_back(max_idx+1);
    }

    vector<int>::iterator iter;
    for(iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    
    return 0;
}