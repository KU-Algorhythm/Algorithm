#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char retCopy[50];
    
    int retCur = 0;
    for(int cur = 0; cur < strlen(s); cur++)
    {
        int currentChar = s[cur];
        
        if(currentChar < 58)
        {
            retCopy[retCur] = currentChar;
        }
        else
        {
            if(currentChar == 102)  //f
            {
                cur++;
                currentChar = (int)s[cur];
                if(currentChar == 105)
                {
                    cur = cur + 2;
                    retCopy[retCur] = 53; //5
                }
                else
                {
                    cur = cur + 2;
                    retCopy[retCur] = 52;
                }
            }
            else if(currentChar == 115) //s
            {
                cur++;
                currentChar = (int)s[cur];
                if(currentChar == 105) //i
                {
                    cur = cur + 1;
                    retCopy[retCur] = 54;
                }
                else
                {
                    cur = cur + 3;
                    retCopy[retCur] = 55;
                }
            }
            else if( currentChar == 116) //t
            {
                cur++;
                currentChar = (int) s[cur];
                
                if(currentChar == 119) //w
                {
                    cur = cur + 1;
                    retCopy[retCur] = 50; //2
                }
                else
                {
                    cur = cur + 3;
                    retCopy[retCur] = 51; //3
                }
            }
            
            else if(currentChar == 101)
            {
                cur = cur + 4;
                retCopy[retCur] = 56;
            }
            
            else if(currentChar == 110)
            {
                cur = cur + 3;
                retCopy[retCur] = 57;
            }
            
            else if(currentChar == 122)
            {
                cur = cur + 3;
                retCopy[retCur] = 48;
            }
            else
            {
                cur = cur + 2;
                retCopy[retCur] = 49;
            }
        }
        
        retCur++;
    }

    retCopy[retCur] = '\0';
    return atoi(retCopy);
}
