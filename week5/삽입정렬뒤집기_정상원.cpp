#include<iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;


int main() {
    vector <int> arr = {0, 1, 2, 1, 1};
    list <int> progresses; //오른쪽에있는 원소들이 왼쪽으로 움직인 횟수, 이 값을 통해서 왼쪽에 있는 원소들은 오른쪽으로 몇칸을 옮길지 결정
    list <int> :: iterator it;
    
    int value;
    
    for(int index = arr.size() - 1; index > -1; index--)
    {
       value = index + 1 - arr[index];
       
       it = progresses.begin();
       while(it != progresses.end())
       {
           if(*it > arr[index])
           {
               value++;
               *it = *it - 1;
               if(*it == 0)
               {
                   it = progresses.erase(it);
               }
               else
               {
                   it++;
               }
           }
           else
           {
               it++;
           }
       }
       
       if(arr[index] > 0)
       {
            progresses.push_back(arr[index]);
       }
       
       arr[index] = value;
    }
    
    for(int val: arr)
    {
        cout << val;
        cout << "  ";
    }
    
    return 0; 
}
