#include <iostream>
#include <stack>
using namespace std;
bool isOperator(char a) {
    if (a >= '*' && a <= '^') return true;
    return false;
}
int getPriority(char a)
{
    if (a == '*' || a == '/')
        return 2;
    if (a == '+' || a == '-')
        return 1;
    if( a == '(') return -1;
    if (a == '^')
        return 3;
}

int main()
{
    std::stack<char> a;
    int n;
    cin >> n;
    char **arr = new char *[n];
    char **e = new char *[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[1000];
        e[i] = new char[1000];
        cin >> arr[i];
        k = 0;
        for (int j = 0; j < 1000; j++)
        {
            if (arr[i][j] == '(')
            {
                a.push('(');
            }
            else if (arr[i][j] == ')')
            {
                while (a.top() != '(')
                {
                    e[i][k++] = a.top();
                    a.pop();
                }
                a.pop();
            }
            else if (arr[i][j] >= '*' && arr[i][j] <= '^')
            {if(!a.empty()){
                 if(getPriority(a.top()) >= getPriority(arr[i][j])){
                    e[i][k++] = a.top();
                    a.pop();
               }
            }
              
                  a.push(arr[i][j]);
            }
            else if(arr[i][j] >= 'a' && arr[i][j] <= 'z'){
                e[i][k++] = arr[i][j];
            }
            else {
                while(!a.empty() && isOperator(a.top())){
                    e[i][k++] = a.top();
                    a.pop();
                }
                break;
            }
        }
    }
    for(int i = 0; i < n ; i++){
        cout << e[i] << endl;
    }
    return 0;
    
}