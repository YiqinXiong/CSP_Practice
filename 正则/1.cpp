#include <regex>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void match()
{
    /////////////////////////////////////////////////////////////////////////
    //std::regex_match
    //std::regex_match: 正则表达式需要匹配整个字符串序列, 也就是说正则表达式要与
    //字符串完全匹配, 因此, 它是单次匹配, 否则匹配失败.
    //此外, 它还可以获取子匹配的组

    std::string text = "Date:2017-10-10";

    //构造正则表达式
    //这里 "()" 用于捕获组, 捕获组的编号是按照 "(" 出现的顺序, 从左到右, 从1开始进行编号的
    std::string pattern = "Date.(\\d{4})-(\\d{2}-(\\d{2}))";
    std::regex express(pattern);

    //匹配
    std::cout.setf(std::ios_base::boolalpha);
    /*模板函数1-1*/
    //第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
    //这里使用的是 std::string::iterator 迭代器, 与 begin()/ end() 返回的迭代器类型(std::string::iterator)要一致
    std::match_results<std::string::iterator> results1;
    if (std::regex_match(text.begin(), text.end(), results1, express))
    {
        std::match_results<std::string::iterator>::const_iterator iter;
        for (iter = results1.begin(); iter != results1.end(); iter++)
        {
            std::cout << iter->length() << ": " << iter->str() << std::endl;
        }
    }
    /*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

    /*模板函数1-2*/
    //第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
    //std::smatch == std::match_results<std::string::const_iterator>
    std::smatch s_results1;
    if (std::regex_match(text.cbegin(), text.cend(), s_results1, express))
    {
        std::match_results<std::string::const_iterator>::const_iterator iter;
        for (iter = s_results1.begin(); iter != s_results1.end(); iter++)
        {
            std::cout << iter->length() << ": " << iter->str() << std::endl;
        }
    }
    /*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

    /*模板函数2*/
    //显示字符串是否符合正则表达式, 用于检测字符串规则
    std::cout << std::regex_match(text.begin(), text.end(), express) << std::endl;

    /*模板函数3*/
    //第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
    //std::cmatch == std::match_results<const char*>
    std::cmatch c_results3;
    if (std::regex_match(text.c_str(), c_results3, express))
    {
        for (auto iter = c_results3.begin(); iter != c_results3.end(); iter++)
        {
            std::cout << iter->length() << ": " << iter->str() << std::endl;
        }
    }
    /*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

    /*模板函数4*/
    //显示字符串是否符合正则表达式, 用于检测字符串规则
    std::cout << std::regex_match(text.c_str(), express) << std::endl;

    /*模板函数5*/
    //第0组一般是整个正则表达式匹配结果, 其他依次是捕获组的结果
    std::match_results<std::string::const_iterator> s_results5;
    if (std::regex_match(text, s_results5, express))
    {
        for (size_t index = 0; index < s_results5.size(); index++)
        {
            //sub_match: 子匹配, match_results里面都存放的是sub_match
            //sub_match 可以理解为 std::pair 的扩展, 它继承了 std::pair,
            //其中 first 实际上存放的是获取的字符串头指针地址, second 为尾指针地址
            std::ssub_match sub = s_results5[index];
            std::cout << sub.length() << ": " << sub.str() << std::endl;
        }
    }
    /*输出
	15: Date:2017-10-10
	4: 2017
	5: 10-10
	2: 10
	*/

    /*模板函数6*/
    //显示字符串是否符合正则表达式, 用于检测字符串规则
    std::cout << std::regex_match(text, express) << std::endl;
    /////////////////////////////////////////////////////////////////////////
}

void my_match()
{
    string text = "201704111809";
    string pattern = "(\\d{4})(\\d{2})(\\d{2})(\\d{2})(\\d{2})";

    regex express(pattern); //要匹配的表达式
    //测试regex_match
    smatch res1;
    if (regex_match(text, res1, express))
    {
        for (smatch::const_iterator it = res1.begin() + 1; it != res1.end(); it++)
        {
            cout << it->length() << " " << it->str() << endl;
        }
    }
    cout << endl;
    //测试regex_search
    smatch res2;
    if (regex_search(text, res2, express))
    {
        for (smatch::const_iterator it = res2.begin() + 1; it != res2.end(); it++)
        {
            cout << it->length() << " " << it->str() << endl;
        }
    }
    cout << endl;

    //测试regex_replace
    string src = "12345678-22345678-32345678-abcd1234";
    string instead = " ";
    cout << regex_replace(src, regex("23\\d*"), instead) << endl;
    cout << endl;

    //测试regex_iterator
    regex r("\\b\\d+\\b");
    string source = "12345678-22345678-32345678-abcd1234";
    regex_iterator<string::const_iterator> reg_iter(src.begin(), src.end(), r); //等于sregex_iterator reg_iter(src.begin, src.end, r)
    sregex_iterator end;
    for (auto it = reg_iter; it != end; it++)
    {
        cout << it->length() << " " << it->str() << endl;
    }
}

int main()
{
    my_match();
    return 0;
}