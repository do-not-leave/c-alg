#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 20
#define SKIPLIST_P  0.25

typedef struct SkipListNode {
    int value;
    struct SkipListNode *backward;
    struct SkipListLevel {
        struct SkipListNode *forward;
    } level[];
} SkipListNode;

typedef struct SkipList {
    SkipListNode *head, *tail;
    unsigned int totalLevel;
} SkipList;

SkipListNode *CreateSkipListNode(int level, int value) {
    SkipListNode *node = malloc(sizeof(SkipList) + level * sizeof(struct SkipListLevel));
    node->value = value;
    return node;
}

SkipList *CreateSkipList() {
    SkipList *list = malloc(sizeof(SkipList));

    list->totalLevel = 1;
    list->head = CreateSkipListNode(MAX_LEVEL, 0);
    for (int j = 0; j < MAX_LEVEL; j++) {
        list->head->level[j].forward = NULL;
    }
    list->tail = NULL;
    return list;
}

/**
 *
 *  
 * 
 */
int RandomLevel(void) {
    int level = 1;
    while ((random()&0xFFFF) < (SKIPLIST_P * 0xFFFF)) {
        level += 1;
    }
    return (level < MAX_LEVEL) ? level : MAX_LEVEL;
}

void Insert(SkipList *skipL, int value) {
    SkipListNode *update[MAX_LEVEL], *tmp;

    for (int i = skipL->totalLevel - 1; i >= 0; i--) {
        while (tmp->level[i].forward && tmp->level[i].forward->value < value) {
            tmp = tmp->level[i].forward;
        }
        update[i] = tmp;
    }
}

void Find(SkipList *skipL, int value) {

}