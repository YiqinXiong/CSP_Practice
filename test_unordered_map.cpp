#include <unordered_map>
#include <map>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct hello
{
    int a;
    string b;
    vector<int> c;
    // hello(int a, vector<int> b) : a(a), b(b) {}
    // hello(int a) : a(a) {}
    hello(string &&b) : b(b) {}
};

int main()
{
    string a = "1234";
    to_integer<string>(a);
    return 0;
}