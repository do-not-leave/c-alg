#include <stdio.h>
#include <stdlib.h>


typedef struct LinkNode {
    int value;
    struct LinkNode *next;
} LinkNode;

typedef struct SingleLink {
    LinkNode *head;
    LinkNode *tail;
    int lenght;
} SingleLink;


//构造链表节点
LinkNode *NewLinkNode() {
    struct LinkNode *p;

    p = malloc(sizeof(struct LinkNode));
    p->value = 0;
    p->next = NULL;
    return p;
}

//构造单链表
SingleLink *NewSingleLink() {
    SingleLink *p;
    LinkNode *node;

    p = malloc(sizeof(struct SingleLink));
    node = NewLinkNode();
    p->head = node;
    p->head = node;
    p->lenght = 0;
    return p;
}


//链表添加节点
int Insert(SingleLink *link, int index, int value) {
    LinkNode *node, *current;


    node = NewLinkNode();
    node->value = value;

    if (index == 0) {
        node->next = link->head->next;
        link->head->next = node;
        link->tail = node;
        link->lenght++;
    } else if (index == link->lenght) {
        link->tail->next = node;
        link->tail = node;
        link->lenght++;
    } else if (index > 0 && index < link->lenght) {
        current = link->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        link->lenght++;
    }

    return -1;
}

//构造一个环
void MakeCircle(SingleLink *link, int index) {
    LinkNode *start;
    int startCnt = 0;

    if (index >= link->lenght - 1 || index <= 0) {
        return;
    }
        
    start = link->head;
    while (start->next != NULL && startCnt <= index) {
        start = start->next;
        startCnt++;
    }
    link->tail->next = start;
}

int HasCircle(SingleLink *link) {
    LinkNode *slow, *fast, *now;
    int index = 0, location = -1;

    slow = link->head;
    fast = link->head;
    

    while (slow->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        index++;

        // printf("%d, %d\n", slow->value, fast->value);
        if (slow == fast) {
            break;
        }
    }
    if (index != 0){
        now = link->head;
        while (slow != now) {
            location++;
            slow = slow->next;
            now = now->next;
        }
        
    }
    return location;
}

int main () {

    int data[7] = {1, 2, 3, 4, 5, 6, 7};

    SingleLink *link;
    LinkNode *entry; 

    //构造链表
    link = NewSingleLink();

    //链表中插入节点
    for (int i = 0; i < 7; i++) {
        Insert(link, i, data[i]);
    }

    //构造一个环
    MakeCircle(link, 2);

    printf("环入口: %d\n", HasCircle(link));
    
    return EXIT_SUCCESS;
}