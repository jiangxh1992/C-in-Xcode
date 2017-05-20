//
//  Base.hpp
//  C++
//
//  Created by Xinhou Jiang on 23/4/17.
//  Copyright © 2017年 Xinhou Jiang. All rights reserved.
//

#ifndef Base_hpp
#define Base_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Base {
public:
    string name;
    virtual void speak();
    virtual void speak(int i);
    //virtual void speak2()=0;
    Base();
};

class Child:public Base {
public:
    void speak();
    //void speak(int i);
    //virtual void speak2();
    Child();
};
#endif /* Base_hpp */
