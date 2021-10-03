#include <iostream>
#include <list>
#include <iterator>

using namespace std;
struct A {
   int died;
   int numb;
};

int main()
{
    int N = 40;
    int K = 3;
    list <A> nodes;
    
    A tempA;
    
    for( int i = 0; i < N; i++)
    {
        tempA.died = 0;
        tempA.numb = i;
        nodes.push_back(tempA);
    }
    
    int ret[2];
    int count = N - 1;
    int liveCount = 0;
    list<A> :: iterator it= nodes.begin();
    
    (*it).died = 1;
    
    while(count > 1)
    {
        if(it == nodes.end())
        {
            it = nodes.begin();
        }
        else
        {
            it++;
        }
        
        if(!((*it).died))
        {
            liveCount++;
            if(liveCount == K)
            {
                (*it).died = 1;
                cout << "died: ";
                cout << (*it).numb;
                cout << '\n';
                count = count - 1;
                liveCount = 0;
            }
            else
            {
                cout << "skipped: ";
                cout << (*it).numb;
                cout << '\n';
            }
        }
    }
    ret[0] = (*it).numb + 1;
    
    while((*it).died)
    {
        if(it == nodes.end())
        {
            it = nodes.begin();
        }
        else
        {
            it++;
        }
    }
    ret[1] = (*it).numb + 1;
    
    if(ret[0] > ret[1])
    {
        int tmp = ret[0];
        ret[0] = ret[1];
        ret[1] = tmp;
    }
    
    cout << ret[0];
    cout << '\n';
    cout << ret[1];

    return 0;
}
