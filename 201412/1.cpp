/* 
*   用时 12分
*   得分 100分
*/
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

const int N=1005;
map<int,int> record;
int n;

int  main()
{
    int id;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> id;
        record[id]++;
        cout << record[id] << " ";
    }
    cout << endl;
    return 0;
}