#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;
#define WORD_SIZE 10

void SetWordArray(string word[])
{
    word[0] = "zero";
    word[1] = "one";
    word[2] = "two";
    word[3] = "three";
    word[4] = "four";
    word[5] = "five";
    word[6] = "six";
    word[7] = "seven";
    word[8] = "eight";
    word[9] = "nine";
}

int solution(string s)
{

    int answer = 0;
    string wordTable[WORD_SIZE];
    SetWordArray(wordTable);
    string find_str;

    for(int i=0; i<WORD_SIZE; i++)
    {       
        find_str = wordTable[i];
        s = regex_replace(s, regex(wordTable[i]), to_string(i));
    }
    answer = stoi(s);

    return answer;
}


int main(void)
{
    string input = "one4seveneight";
    cout<<solution(input)<<endl;
    
    return 0;
}

