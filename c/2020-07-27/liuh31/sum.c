#include <stdio.h>
#include <stdlib.h>

#define INIT_TABLE_SIZE 100

typedef struct SumValue {
    int key;
    int x;
    int y;
    struct SumValue *next;
} SumValue;

typedef struct SumMap {
    SumValue *ht[INIT_TABLE_SIZE];
} SumMap;

SumMap *NewMap() {
    SumMap *p;
    p = malloc(sizeof(SumMap));

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        p->ht[i] = NULL;
    }

    return p;
}

int GetHtIndex(SumMap *sm, int key) {
    return key % INIT_TABLE_SIZE;
}

void Set(SumMap *sm, SumValue *v) {
    int idx = GetHtIndex(sm, v->key);
    SumValue *current;
    current = sm->ht[idx];

    if (current == NULL) {
        sm->ht[idx] = v;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = v;
    }
}

SumValue *Get(SumMap *sm, int key) {
    SumValue *current;
    int idx = GetHtIndex(sm, key);
    current = sm->ht[idx];

    while (current != NULL) {
        if (current->key == key) {
            break;
        } else {
            current = current->next;
        }
    }

    return current;
}



int main () {
    int num_list[7] = {1, 3, 5, 6, 9, 20, 7};
    SumValue *v;
    SumMap *m = NewMap();

    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            v = malloc(sizeof(SumValue));
            v->key = num_list[i] + num_list[j];
            v->x = num_list[i];
            v->y = num_list[j];
            v->next = NULL;
            Set(m, v);
        }
    }

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        v = m->ht[i];
        while (v != NULL) {
            printf("key : %d; x: %d; y: %d\n", v->key, v->x, v->y);
            v = v->next;
        }
    }

    return EXIT_SUCCESS;
}