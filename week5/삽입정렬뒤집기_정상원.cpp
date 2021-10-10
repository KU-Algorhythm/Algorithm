#include<iostream>
#include <utility>
#include <vector>

using namespace std;


class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
        int leftNum;
        int rightNum;
    };

    node* root;
    int count = 0;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    int insert(int x, node* t)
    {
       if( x < t-> data)
       {
           if( t -> leftNum == 0)
           {
               node * temp = new node;
               temp -> data = x;
               temp -> leftNum = 0;
               temp -> rightNum = 0;
                t -> left = temp;
                t -> leftNum = 1;
           }
           else
           {
               t -> leftNum = insert(x, t-> left);
           }
       }
       else
       {
           if( t -> rightNum == 0)
           {
               node * temp = new node;
               temp -> data = x;
               temp -> leftNum = 0;
               temp -> rightNum = 0;
                t -> right = temp;
                t -> rightNum = 1;
           }
           else
           {
               t -> rightNum = insert(x, t-> right);
           }
       }
       
       return t-> leftNum + t-> rightNum + 1;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        cout << "left childNum: ";
        cout << t->leftNum << " ";
        cout << "right childNum: ";
        cout << t->rightNum;
        cout << "\n";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }
    
    pair<int, int> findSmaller(node* t,int target, int adjustment )
    {
        
        if(t->data == target)
        {
            pair <int, int> temp = {t->data, t->leftNum + adjustment};
            return temp;
        }
        else if( t-> data > target)
        {
            if(t -> left == NULL)
            {
                pair<int, int> temp = {-1, -1};
                return temp;
            }
            else
            {
                return findSmaller(t -> left, target, adjustment);
            }
        }
        else
        {
            if( t-> right == NULL)
            {
                pair<int, int> temp = {t->data, t->leftNum + adjustment};
                return temp;
            }
            else
            {
                pair<int, int> temp = findSmaller(t -> right, target, adjustment + 1 + t->leftNum);
                if(temp.first < t -> data)
                {
                    temp = {t-> data, t->leftNum + adjustment};
                }
                
                return temp;
            }
        }
    }

    
public:
    BST(int x) {
        node * temp = new node;
        temp -> data = x;
        temp -> leftNum = 0;
        temp -> rightNum = 0;
        root = temp;
        count = 1;
    }

    void insert(int x) {
        insert(x, root);
        cout << "inserted: ";
        cout << x;
        cout << "\n";
        count++;
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
    
    pair<int,int> findSmallerThan(int target) //target이랑 같은 값이 그래프에 있어도 리턴된값에 미포함. 말그대로 그 수보다 작은수들의 수만 리턴
    {
        pair<int,int> takeRet;
        takeRet = findSmaller(root, target, 0);
        
        cout << "takeRet[0]: ";
        cout << takeRet.first;
        cout << " ";
        cout << "takeRet[1]: ";
        cout << takeRet.second;
        
        
        if(takeRet.first == -1)
        {
            takeRet.second = 0;
        }
        else if(takeRet.first < target) //takeRet.first보다 적은수만 리턴이 된다. 따라서 takeRet.first가 target보다 작으면 자기자신도 카운트
        {
            takeRet = {takeRet.first, takeRet.second + 1};
        }
        
        cout << " target ";
        cout << target;
        cout << " takeRet[0]: ";
        cout << takeRet.first;
        cout << " takeRet[1]: " ;
        cout << takeRet.second;
        cout << "\n";
        
        
        return takeRet;
    }
    
    int findBiggerThan(int target)
    {
        pair<int,int> takeRet;
        takeRet = findSmaller(root, target, 0);
        
        if(takeRet.first == -1)
        {
            takeRet.second = 0;
        }
        else if( takeRet.first == target)
        {
            takeRet.second = takeRet.second + 1;
        }
        
        cout << "bigger numb: ";
        cout << count - takeRet.second;
        cout << "\n";
        return count - takeRet.second;
        
    }
    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    vector <int> arr = {0, 0, 1, 0, 4};   //삽입정렬뒤집기 문제
    
    int N = arr.size();                   // 최대수
    
    int value = N - arr[N - 1];           //맨오른쪽은 바로 구할수 있으므로 그래프에 넣는다     
    BST t = BST(value);
    arr[N - 1] = value;
    
    for(int index = N - 2; index > -1; index--)
    {
       int currentKth = index + 1 - arr[index];           //현제 고른 원소가 남아있는 원소중에 앞에서 몇번째 원소인지
        
       int startNum = 1;
       int endNum = N;
       int mid;
       int kth;
       pair<int, int> returnedPair;
       
       bool breaked = false;                               //breaked는 디버그용 변수 입니다
       
       while(startNum <= endNum)
       {
           mid = (startNum + endNum) / 2;                  //이진탐색을 위한 mid. mid가 뽑히지 않았다고 가정하고, 남아있는것중에 몇번째일지
           returnedPair = t.findSmallerThan(mid);          //그래프에서 mid보다 작은수의 개수와 그래프 안에있는 mid보다 작은수중에 가장 큰수나 같은값을 리턴
           kth = mid - returnedPair.second;                //mid가 뽑히지 않았더라면 남아 있는 원소중에 몇번째인가
           
           if(currentKth > kth)                            //mid의 kth가 currentKth보다 작다면 mid보다 큰수 찾기
           {
               startNum = mid + 1;
               
           }
           else if(currentKth < kth)                       //mid의 kth가 currentKth보다 크다면 mid보다 작은수 찾기
           {
               endNum = mid - 1;
           }
           else                                            //currentKth랑 kth랑 같다면 
           {
               if(returnedPair.first == mid)  //mid가 그래프 안에 있다면, mid보다 큰게 되야된다
               {
                   startNum = mid + 1;
               }
               else                           //mid가 남아있는 원소중에 currentKth라면 
               {
                   breaked = true;
                   break;                     //break가 실행이 안되면 이 알고리즘에 버그가 있다는 뜻!
               }
           }
           
           
       }
       
       if(!breaked)                           //break문이 실행이 안됐다면 에러가 났다고 출력!
       {
           cout << "holy shit! there is a bug in the code!\n";
           cout << "error on index: ";
           cout << index;
           cout << " returned mid: ";
           cout << mid;
           cout << " calculated currentKth: ";
           cout <<currentKth;
           cout << "\n";
           t.display();
           cout << "\n";
       }
       
       t.insert(mid);                           //mid를 그래프에 넣는다.(이제는 실제값!)
       arr[index] = mid;                        //arr[index]답을 넣는다.
    }
    
    for(int val: arr)
    {
        cout << val;
        cout << "  ";
    }
    
    return 0; 
}
