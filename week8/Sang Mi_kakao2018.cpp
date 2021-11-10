#include <string>
#include <cstring>
#include <cctype>

using namespace std;


int solution(string str1, string str2) {
    int cnt1[26][26], cnt2[26][26];
    memset(cnt1, 0, sizeof(int) * 26 * 26);
    memset(cnt2, 0, sizeof(int) * 26 * 26);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;
        int j = ('a' <= str1[i] && str1[i] <= 'z') ? str1[i] - 'a' : str1[i] - 'A';
        int k = ('a' <= str1[i + 1] && str1[i + 1] <= 'z') ? str1[i + 1] - 'a' : str1[i + 1] - 'A';
        cnt1[j][k]++;
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;
        int j = ('a' <= str2[i] && str2[i] <= 'z') ? str2[i] - 'a' : str2[i] - 'A';
        int k = ('a' <= str2[i + 1] && str2[i + 1] <= 'z') ? str2[i + 1] - 'a' : str2[i + 1] - 'A';
        cnt2[j][k]++;
    }

    int a = 0, b = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            a += min(cnt1[i][j], cnt2[i][j]);
            b += max(cnt1[i][j], cnt2[i][j]);
        }
    }

    int answer;
    if (b == 0) answer = 65536;
    else answer = int(double(a) / b * 65536);
    return answer;
}