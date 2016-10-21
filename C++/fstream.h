//
//  fstream.h
//  C++
//
//  Created by albeeert on 10/20/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//

#ifndef fstream_h
#define fstream_h

#include <iostream>
#include <string>  // 字符串
#include <fstream> // 文件流
using namespace std;

int main()
{
    // 定义文件输入流
    ifstream fin("test.txt");
    // 检测文件是否成功打开
    if (!fin) {
        cout<<"can not open the file!"<<endl;
        return 0;
    }
    // 数据缓冲
    int a,b;
    string line;
    
    // 读入两个数据【fin在读入数据时会以空格和回车键作为数据间的分隔符】
    fin>>a>>b;
    // 打印读入的数据和两个数据的和
    cout<<a<<" "<<b<<" "<<a+b<<endl;
    
    // 读入整行数据【会从上面读取到的位置继续读取改行剩下的数据】
    getline(fin, line);
    // 打印整行数据
    cout<<line<<endl;
    return 0;
}

#endif /* fstream_h */
