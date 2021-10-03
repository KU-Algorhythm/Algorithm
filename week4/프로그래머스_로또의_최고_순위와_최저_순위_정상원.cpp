#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroNum = 0;
    int matchedNum = 0;
    for(int numb : lottos)
    {
        if( numb == 0)
        {
            zeroNum ++;
        }
        else
        {
            for(int winNum: win_nums)
            {
                if(winNum == numb)
                {
                    matchedNum++;
                    break;
                }
            }
        }
    }
    int tmp = 7 - matchedNum;
    if( tmp > 6)
        tmp = 6;
    answer.push_back(7 - matchedNum - zeroNum);
    answer.push_back(tmp); 
    return answer;
}
