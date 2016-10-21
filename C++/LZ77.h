//
//  LZ77.h
//  C++
//
//  Created by albeeert on 10/20/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//

#ifndef LZ77_h
#define LZ77_h

#include <iostream>
using namespace std;

typedef struct _Tuple
{
    int p ;  // 当前位置
    int l ;  // 识别的重复长度
    char c ; // 下一个字符
    struct _Tuple *next ;
} Tuple ;

typedef struct
{
    char *data ;
    int len ;
    int curr ;
    int sb_len ;
    int lab_len ;
} LAB ;

int matchString(char *a, char *b, int len_a)
{
    int matchedCount = 0;
    while(a[matchedCount] == b[matchedCount] && matchedCount < len_a)
    {
        matchedCount++ ;
    }
    return matchedCount ;
}

Tuple longestMatchedString(LAB *lab)
{
    int longestLen = 0 ;
    int matchedLen = 0 ;
    int position = 0 ;
    Tuple C ;
    int min, max ;
    min = lab->curr - lab->sb_len ;
    if(min < 0)
        min = 0 ;
    max = lab->curr + lab->lab_len - 1;
    if(max >= lab->len)
        max = lab->len - 1 ;
    int i ;
    for(i = min; i < lab->curr; i++)
    {
        matchedLen = matchString(lab->data + lab->curr, lab->data + i,lab->len) ;
    }
    if(matchedLen > longestLen)
    {
        longestLen = matchedLen ;
        position = lab->curr - i ;
    }
    C.p = position ;
    C.l = longestLen ;
    lab->curr += longestLen ;
    C.c = lab->data[lab->curr];
    C.next = NULL ;
    return C ;
}

Tuple *Encode_LZ77(LAB lab)
{
    Tuple *C = new Tuple ;
    Tuple *CPtr = NULL ;
    CPtr = C ;
    while(lab.curr < lab.len)
    {
        *CPtr = longestMatchedString(&lab);
        lab.curr++ ;
        if(lab.curr < lab.len)
        {
            CPtr->next = new Tuple ;
            CPtr = CPtr->next ;
        } else
        {
            CPtr->next = NULL ;
        }
    }
    return C;
}

void Decode_LZ77(Tuple *C, LAB *lab) {
    Tuple *Cnext ;
    Cnext = C ;
    while(Cnext) {
        for(int i = 0; i < Cnext->l; i++) {
            lab->data[lab->curr]=lab->data[lab->curr - Cnext->p];
            lab->curr++ ;
        }
        lab->data[lab->curr] = Cnext->c ;
        lab->curr++ ;
        Cnext = Cnext->next ;
    }
}

int main(int argc, char *argv[])
{
    LAB lab;
    Tuple *C, *Cnext;
    char defaultMessage[] = "cabbdcbaacbdddabda";
    if(argc <= 1)
    {
        lab.data = defaultMessage ;
    }
    else
    {
        lab.data = argv[1] ;
        lab.sb_len = 7 ;
        lab.lab_len = 3 ;
        lab.curr = 0 ;
        lab.len = (int)strlen(lab.data);
        printf("Encoding Message %s\n", lab.data);
        C = Encode_LZ77(lab) ;
        Cnext = C ;
        while(Cnext)
        {
            printf("(%d, %d, %c)\n", Cnext->p, Cnext->l, Cnext->c);
            Cnext = Cnext->next ;
        }
        lab.sb_len = 7 ;
        lab.lab_len = 3 ;
        lab.curr = 0 ;
        lab.len = 0 ;
        lab.data[0] = 0 ;
        Decode_LZ77(C, &lab);
        while(C)
        {
            Cnext = C->next ;
            delete C;
            C=Cnext;
        }
        printf("Decoded Message %s\n", lab.data);
        return 0;
    }
}

#endif /* LZ77_h */
