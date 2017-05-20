//
//  fstream.h
//  C++
//
//  Created by albeeert on 10/20/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//
#include <iostream>
#include <math.h>
using namespace std;

//Qwertyuiop
//asdfghjkl;
//zxcvbnm,./

struct node{
    int x;
    int y;
};

int main() {
    string dic = "Qwertyuiopasdfghjkl;zxcvbnm,./";
    string s;
    cin>>s;
    int len = (int)s.length();
    node *N = new node[len];
    for (int i=0; i<len; i++) {
        int index=0;
        for (int j=0; j<30; j++) {
            if (s[i]==dic[j]) {
                index=j;
            }
            N[i].x = index%10;
            N[i].y = 2-index/10;
        }
    }
    double distance=0;
    for (int i=0; i<len-1; i++) {
        distance+=sqrt(pow((N[i].x-N[i+1].x), 2)+pow((N[i].y-N[i+1].y), 2));
    }
    distance = round(distance*100000)/100000;
    cout<<distance<<endl;
    return 0;
}

//int main() {
//    int flag;
//    string s;
//    int code[4]={0,0,0,0};
//    int step=0;
//    bool iszipping=false;
//    cin>>flag;
//    
//    // 压缩
//    if (flag == 0) {
//        cin>>s;
//        step = 0;
//        iszipping = true;
//        for (int i=0; i<27; i++) {
//            if (s[i]==':') {
//                step++;
//                iszipping = true;
//            }else{
//                if (s[i]=='0') {
//                    code[step]++;
//                }else{
//                    iszipping = false;
//                    continue;
//                }
//            }
//        }
//        
//        for (int i=code[0]; i<6; i++) {
//            cout<<s[i];
//        }
//        cout<<':';
//        for (int i=7+code[1]; i<13; i++) {
//            cout<<s[i];
//        }
//        cout<<':';
//        for (int i=14+code[2]; i<20; i++) {
//            cout<<s[i];
//        }
//        cout<<':';
//        for (int i=21+code[3]; i<27; i++) {
//            cout<<s[i];
//        }
//        cout<<endl;
//        
//    }
//    // 解压
//    else if (flag == 1) {
//        cin>>s;
//        step = 0;
//        for (int c=0; c<4; c++) {
//            code[c]=0;
//        }
//        for (int i=0; i<s.length(); i++) {
//            if (s[i]==':') {
//                step++;
//            }else {
//                code[step]++;
//            }
//        }
//        
//        step=0;
//        iszipping=true;
//        for (int i=0; i<s.length(); i++) {
//            if (iszipping) {
//                for (int i=0; i<6-code[step]; i++) {
//                    cout<<'0';
//                }
//                iszipping=false;
//            }
//            cout<<s[i];
//            if (s[i]==':') {
//                step++;
//                iszipping=true;
//                if (i==s.length()-1) {
//                    cout<<"000000";
//                }
//            }
//        }
//        cout<<endl;
//    }
//}
