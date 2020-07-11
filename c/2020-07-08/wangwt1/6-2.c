#include <stdio.h>
//定义点结构
struct point {
    int x;
    int y;
};
//定义矩形结构
struct rect {
    struct point pt1;
    struct point pt2;
};
//定义生成点的方法
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
};
//定义点相加
struct addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p2.y += p2.y;
    return p1;
};


int main()
{
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2, (screen.pt1.y+screen.pt2.y)/2);
    
    return 0;
}