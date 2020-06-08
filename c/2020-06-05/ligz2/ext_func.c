#include <stdio.h>

static int a=10;
static char b = 'm';
static int getcs() {
    printf("static c\n");
    return 1;
}
int geta() {
    return a;
}
char getb() {
    getcs();
    return b;
}
