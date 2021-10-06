#include <iostream>
#include <list>
#include <iterator>
#include<bits/stdc++.h>

using namespace std;

void recurse(vector<int> &preorder, int startIndex, int endIndex)
{
    int root = preorder[startIndex];
    
    int i;
    
    if( endIndex > startIndex)
    {
        for(i = startIndex + 1; i <= endIndex; i++)
        {
            if(preorder[i] > root)
                break;
        }
        
        int nextStartIndex = startIndex + 1;
        int nextEndIndex = i - 1;
        
        /*cout << "left: ";
            cout << "nextStartIndex : ";
            cout << nextStartIndex; 
            cout << " ";
            cout << "nextEndIndex: ";
            cout << nextEndIndex;
            cout << "\n";
        */
        
        if(nextStartIndex <= nextEndIndex)
        {
            
            recurse(preorder ,nextStartIndex, nextEndIndex);
        }
        
        nextStartIndex = i;
        nextEndIndex = endIndex;
        
        /*cout << "right: ";
            cout << "nextStartIndex : ";
            cout << nextStartIndex; 
            cout << " ";
            cout << "nextEndIndex: ";
            cout << nextEndIndex;
            cout << " ";
            cout << "\n";
         */
         
        if(nextStartIndex <= nextEndIndex)
        {
            
            recurse(preorder, nextStartIndex, nextEndIndex);
        }
    }
    
    cout << root;
    cout << " ";
}
int main()
{
    vector <int> arr = {31, 10, 5,13, 45, 33, 60};
    recurse(arr, 0, arr.size() -1 );
    return 0;
}
