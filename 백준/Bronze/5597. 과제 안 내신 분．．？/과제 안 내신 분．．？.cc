#include <iostream>
using namespace std;
int main()
{
    int number;
    int list[30] = {0,};
    for (int i=0; i<30; i++)
    {
        cin >> number;
        list[number-1]++;
    }
    for(int i=0; i<30; i++){
        if(list[i] == 0){
            cout<<i+1<<endl;
        }
    }
}