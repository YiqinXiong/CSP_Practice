/*
*   用时 40分
*   得分 100分
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string strUpper(string str)
{
    string upperStr = "";
    for(int i=0; i<str.length(); i++)
    {
        upperStr.append(1,toupper(str[i]));
    }
    return upperStr;
}

int main()
{
    string sample;
    int n;
    int sensitive;
    vector<string> lines;
    cin >> sample;
    cin >> sensitive;
    if(!sensitive) sample=strUpper(sample);
    //cout <<"sample: "<<sample<<endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string temp, upperTemp;
        cin >> temp;
        upperTemp = strUpper(temp);
        //cout <<"upperTemp: "<<upperTemp<<endl;
        if(!sensitive)
        {
            if(upperTemp.find(sample)!=string::npos)
                cout << temp << endl;
        }
        else
        {
            if(temp.find(sample)!=string::npos)
                cout << temp << endl;
        }
    }
    return 0;
}
