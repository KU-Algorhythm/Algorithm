#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MUL 65536

int main(void)
{
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    
    vector<string> multiSet_A;
    vector<string> multiSet_B;

    vector<string> ::iterator iter;
    for(int i=0; i<str1.length()-1; i++)
    {
        string tmp;
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            tmp += tolower(str1[i]);
            tmp += tolower(str1[i+1]);
            
            multiSet_A.push_back(tmp);
        }
    }

    for(int i=0; i<str2.length()-1; i++)
    {
        string tmp;
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            tmp += tolower(str2[i]);
            tmp += tolower(str2[i+1]);
            multiSet_B.push_back(tmp);
        }
    }

    if(multiSet_A.size() == 0 && multiSet_B.size() == 0) // 다중집합 A, B가 모두 공집합인 경우 
    {
        return MUL;
    }

    sort(multiSet_A.begin(), multiSet_A.end());
    sort(multiSet_B.begin(), multiSet_B.end());

    vector<string> intersection(multiSet_A.size() + multiSet_B.size());
    auto iter_a = set_intersection(multiSet_A.begin(), multiSet_A.end(), multiSet_B.begin(), multiSet_B.end(), intersection.begin());
    intersection.erase(iter_a, intersection.end()); // 남는 공간 비워주기
 
    // 다중집합의 합집합
    vector<string> multi_union(multiSet_A.size() + multiSet_B.size());
    auto iter_b = set_union(multiSet_A.begin(), multiSet_A.end(), multiSet_B.begin(), multiSet_B.end(), multi_union.begin());
    multi_union.erase(iter_b, multi_union.end());

    int Jaccard = 0;
    Jaccard = ((float)intersection.size() / (float)multi_union.size()) * 65536;
    return Jaccard;
    
}
