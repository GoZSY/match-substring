/***********************************************************
思路1.
先写一个判断纯数字的函数，注意小数点不能出现两次以上
以e和E为分隔符，在字符串中先判断他们的存在，若不存在则只需判断是否为正确的纯数字，存在则判断他们的位置是否正确，
然后判断他们的左右两边是否为数字，这里需要注意的是e和E的指数不能为小数
*******************************************************************/
class Solution {
public:
bool isNumber(char* str1, int length)
{
    if(length < 1)
        return false;
    int i =0;
    int d_N = 0;//记录点的个数
    for(i = 0; i < length; ++i)
    {
        if((*str1 == '+' || *str1 == '-') && i == 0)
        {
            str1++;
        }
        else if(*str1 >='0' && *str1 <= '9')
        {
            str1++;
        }
        else if(*str1 == '.')
        {
            d_N++;
            if(((str1-1)!=NULL&&(str1+1)!=NULL)&&(*(str1-1) >'0' && *(str1-1) <= '9')&&(*(str1+1) >='0' && *(str1+1) <= '9'))
                str1++;
            else
                return false;
        }
        else
            return false;
    }
    if(i == length && d_N <= 1)
        return true;
 
    return false;
}
bool isNumeric(char* string)
{
    if(string == NULL)
        return false;
    int length = strlen(string);
    int Eore = -1;
    int i;
    for(i = 0;i < length;++i)
    {
        if(string[i] == 'E' || string[i] == 'e')
        {
            Eore = i;
            break;
        }
    }
    if(Eore == 0 || Eore == length-1)
        return false;
    else if(Eore == -1)
        return isNumber(string,length);
    else
        return isNumber(string,Eore) && isNumber(string+Eore+1,length-Eore-1);
    return false;
}
 
 
};
/******************************************
思路2.使用C++自带的模板库的字符串匹配函数
需要添加头文件#include <regex>
*/

#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    regex pattern("(-|\\+)?\\d*(\\.)?\\d*((E|e)(-|\\+)?\\d+)?");
    cout << "输入数字：" << endl;
    string str;
    cin >> str;
    match_results<string::const_iterator> result;
    bool valid = regex_match(str,result,pattern);
    cout << "结果：" << valid << endl;
    return 0;
}
