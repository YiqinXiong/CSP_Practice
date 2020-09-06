#include <map>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct hello
{
    string name;
    map<string, int> age;
    hello(string name, map<string, int> age) : name(name), age(age) {}
};

vector<hello> hellos;
map<string, hello> helloMap;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name = "xyq";
        name.append(1, 'a' + i);
        map<string, int> age;
        age["five"] = 5 + i;
        age["ten"] = 10 + i;
        hellos.push_back(hello(name, age));
        helloMap.insert(pair<string, hello>(name, hello(name, age)));
    }
    cout << helloMap.size() << endl;
    map<string, hello>::iterator it = helloMap.find("xyqa");
    cout << it->first << endl;
    cout << hellos[3].name << " :";
    map<string, int>::iterator iiit = hellos[3].age.begin();
    for (; iiit != hellos[3].age.end(); iiit++)
    {
        cout << iiit->first << "," << iiit->second << " ";
    }
    cout << endl;
    return 0;
}