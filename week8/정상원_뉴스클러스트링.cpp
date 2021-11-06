#include <string>
#include <iostream>
#include <map>


using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    int str1GroupLen = 0;
    int str2GroupLen = 0;
    int common = 0;
    map<string, int> str1Map;
    
    for(int i = 0; i < str1.size() - 1; i++)
    {
        
        char temp[2];
        temp[0] = tolower(str1[i]);
        temp[1] = tolower(str1[i + 1]);
 
        if( temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z')
        {
            
            str1GroupLen++;
            string tempStr(temp);
            if(str1Map.find(tempStr) != str1Map.end())
            {
                str1Map[tempStr] = str1Map[tempStr] + 1;
            }
            else
            {
                str1Map.insert(pair<string, int>(tempStr, 1));
            }
        }
    }
    
    
    for(int i = 0; i < str2.size() - 1; i++)
    {
        
        char temp[2];
        temp[0] = tolower(str2[i]);
        temp[1] = tolower(str2[i + 1]);
 
        if( temp[0] >= 'a' && temp[0] <= 'z' && temp[1] >= 'a' && temp[1] <= 'z')
        {
            str2GroupLen++;
            string tempStr(temp);
            if(str1Map.find(tempStr) != str1Map.end())
            {
                if(str1Map[tempStr] > 0)
                {
                    str1Map[tempStr] = str1Map[tempStr] - 1;
                    common++;
                }
            }
            
        }
    }
    
    if(str1GroupLen == 0 && str2GroupLen == 0)
    {
        return 65536;
    }
    
    double ratio = ((double) common / (str1GroupLen + str2GroupLen - common));
    answer = (int) (ratio * 65536);
    return answer;
        
}

int main()
{
    cout<< solution("handshake", "shake hands");

    return 0;
}
