//
//  Base.cpp
//  C++
//
//  Created by Xinhou Jiang on 23/4/17.
//  Copyright © 2017年 Xinhou Jiang. All rights reserved.
//

#include "Base.hpp"

Base::Base() {
    this->name = "base";
}

void Base::speak() {
    printf("base");
}

void Base::speak(int i) {
    printf("base:%i",i);
}


Child::Child() {
    Base();
}

void Child::speak() {
    printf("child");
}

//void Child::speak(int i) {
//    printf("child:%i",i);
//}

//void Child::speak2() {
//    printf("virtual child");
//}
