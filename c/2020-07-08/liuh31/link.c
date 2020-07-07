#include <stdio.h>
#include <stdlib.h>

struct ValueObject {
    void *value;
};

struct LinkNode {
    struct ValueObject *value;
    struct LinkNode *next;
};

struct SingleLink {
    struct LinkNode *head;
    struct LinkNode *tail;
    int lenght;
};

struct ValueObject *NewValueObject() {
    struct ValueObject *p;
    p = malloc(sizeof(struct ValueObject));
    return p;
}

int IntCompare(struct ValueObject *v, void *value) {
    int *a, *b;
    a = (int *)(v->value);
    b = (int *)(value);
    if (*a < *b) {
        return -1; 
    } else if(*a > *b) {
        return 1;
    } else {
        return 0;
    }
}

void SetInt(struct ValueObject *v, int value) {
    v->value = malloc(sizeof(int));
    *(int *)v->value = value;
}

int GetInt(struct ValueObject *v) {
    return *(int *)(v->value);
}

struct LinkNode *NewLinkNode() {
    struct LinkNode *p;

    p = malloc(sizeof(struct LinkNode));
    p->value = NULL;
    p->next = NULL;
    return p;
}

struct SingleLink *NewSingleLink() {
    struct SingleLink *p;
    struct LinkNode *node;

    p = malloc(sizeof(struct SingleLink));
    node = NewLinkNode();
    p->head = node;
    p->head = node;
    p->lenght = 0;
    return p;
}

int Insert(struct SingleLink *link, int index, int value) {
    struct ValueObject *v;
    struct LinkNode *node, *current;

    v = NewValueObject();
    SetInt(v, value);
    node = NewLinkNode();
    node->value = v;

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

struct LinkNode *Find(struct SingleLink *link, void *value) {
    struct LinkNode *start;
    start = link->head;

    while (start->next != NULL) {
        start = start->next;
        if (IntCompare(start->value, value) == 0) {
            return start;
        }
    }
    return NULL;
}


void TraverseLink(struct SingleLink *link) {
    struct LinkNode *start;
    start = link->head;

    while (start->next != NULL) {
        start = start->next;
        printf("%d, ", GetInt(start->value));
    }
}

void ReverseLink(struct SingleLink *link) {
    struct LinkNode *current, *newCurrent;

    current = link->head->next;


    while (current != NULL) {
        newCurrent = current;
        current = current->next;

        if (newCurrent == link->tail) {
            break;
        }
        newCurrent->next = link->tail->next;
        link->tail->next = newCurrent;
    }

    link->tail = link->head->next;
    link->tail->next = NULL;
    link->head->next = newCurrent;
}


int main() {
    int data[7] = {1, 2, 3, 4, 5, 6, 7};

    struct SingleLink *link;

    link = NewSingleLink();

    for (int i = 0; i < 7; i++) {
        Insert(link, i, data[i]);
    }
    
    TraverseLink(link);

    printf("\n");
    ReverseLink(link);

    TraverseLink(link);

    return EXIT_SUCCESS;
}