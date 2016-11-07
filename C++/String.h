//
//  String.h
//  C++
//
//  Created by Xinhou Jiang on 7/11/16.
//  Copyright © 2016年 Xinhou Jiang. All rights reserved.
//

#ifndef String_h
#define String_h

/*** String字符串容器 ***/
#include <iostream>
#include <algorithm> // reverse
#include <sstream>   // string与数值的相互转换
#include <string>
using namespace std;

// 将数值转换为string
template <typename T>
string convertToString(T x)
{
    ostringstream ostring;
    if (ostring << x)
        return ostring.str();
    return "error";
}
// 将string转换为数值
template <typename T>
T convertFromString(const string &s)
{
    istringstream istring(s);
    T x;
    if (istring >> x)
        return x;
    return 0;
}

int main(){
    /** 1.string对象的创建赋值与访问 **/
    // 直接赋值与打印
    string s = "123abc";
    cout<<s<<endl;
    printf("%s", s.c_str());
    
    // 使用字符数组指针赋值string
    char chars[3] = {'a','b','c'};
    s = chars;             // "abc"
    
    // 输入字符串到chars字符数组中
    scanf("%s",chars);
    cout<<chars<<endl;
    
    // string相当于一个字符数组，访问方式相同
    cout<<s<<endl;         // 打印整个字符串
    cout<<s[0]<<endl;      // 打印字符串的首字符
    
    /** 2.string字符串的拼接 **/
    string s2;
    s2 = s2 + 'a';         // "a"
    s2 = s2 + "bc";        // "abc"
    s2 = s2.append("d");   // "abcd"，不可以append 'd'
    s2 = s2.append("efg"); // "abcdefg"
    
    /** 3.string插入单个字符 **/
    string s3 = "abc";
    string::iterator it3 = s3.begin();
    s3.insert(it3+1, 'd');  // "adbc"
    
    /** 4.抹除字符串的字符元素或子串 **/
    string s4 = "abcdefg";
    string::iterator it4 = s4.begin();
    s4.erase(it4);          // "bcdefg"
    s4.erase(it4, it4+1);   // "cdefg", 还是只删除第一个
    s4.erase(it4, it4+3);   // "fg", 删除前三个
    
    /** 5.string字符串的长度 **/
    string s5 = "abc";
    cout<<s5.length()<<endl; // 3
    cout<<s5.empty()<<endl;  // 0, 判断是否为空
    
    /** 6.替换string字符串的子串 **/
    string s6 = "i521cpp";
    s6.replace(1, 3, "love"); // "ilovecpp", 从第2个字符开始连续3个字符替换为"love"
    
    /** 7.查找string的字符元素或子串 **/
    string s7 = "cat521dog";
    unsigned long index1 = s7.find("5"); // 3, 返回元素下标
    index1 = s7.find("dog");             // 6, 返回子串首字符下标
    index1 = s7.find("cat6");            // 找不到则返回一个上限极大数
    
    /** 8.string字符串比较 **/
    string s81 = "acc";
    string s82 = "aaz";
    string s83 = "xy";
    string s84 = "abc";
    string s85 = "ac";
    cout<<s81.compare(s84)<<endl; // 0, s81和s84相等
    cout<<s81.compare(s82)<<endl; // 2, s81比s82大
    cout<<s82.compare(s83)<<endl; // -23, s82比s83小
    cout<<s81.compare(s85)<<endl; // 1
    /* 关于输出结果的解释：这里的比较其实是从两个字符串各自的第一个字符开始比较，比较字符的ASCII码值，如果两个字符串长度相等且比到最后每个字符都相等，则表示两个字符串相等返回0；而如果比到某个字符两个字符不一样则返回他们的ASCII码的差值；如果其中一个字符串是另一个字符串的子串，则返回的是1或者-1，子串比长的串小 */
    
    /** 9.string子串的reverse反向排序 **/
    string s9 = "abcdefg";
    reverse(s9.begin()+2, s9.end()-1);
    cout<<s9<<endl; // "abfedcg"
    
    /** 10.sscanf字符串分离**/
    char cbuf[10];
    int ibuf;
    float fbuf;
    double dbuf;
    sscanf("abc 13,3.5$3.1415", "%s %d,%f$%lf", cbuf,&ibuf,&fbuf,&dbuf); // 其中空格逗号和$符都可以作为分隔符
    cout<<cbuf<<endl<<ibuf<<endl<<fbuf<<endl<<dbuf<<endl;
    
    /** 11.数值与string的相互转换 **/
    string cs = convertToString(3.5);
    double d = convertFromString<double>("3.1415926");
    
    return 0;
}

#endif /* String_h */
