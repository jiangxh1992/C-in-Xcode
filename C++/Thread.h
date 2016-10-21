//
//  Thread.h
//  C++
//
//  Created by albeeert on 10/16/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//
#include <thread>        // 线程

#ifndef Thread_h
#define Thread_h

void Hello(){
    cout<<"hello multi-thread!"<<endl;
}

/**
 * 多线程
 */
thread t(Hello);
t.join();

#endif /* Thread_h */
