//
//  List.h
//  C++
//
//  Created by Xinhou Jiang on 2/6/2017.
//  Copyright © 2017 Xinhou Jiang. All rights reserved.
//

#ifndef List_h
#define List_h

typedef struct Node{
    int val;
    Node *next;
}List;

void InverseList(Node *head, Node*p){
    if (p == NULL) {
        return;
    }
    if (p->next == NULL) {
        head->next = p;
        return;
    }
    InverseList(head,p->next);
    p->next->next = p;
    p->next = NULL;
}

#endif /* List_h */
