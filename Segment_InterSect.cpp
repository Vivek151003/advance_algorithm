#include <bits/stdc++.h>

using namespace std;
struct Point
{
    int x;
    int y;
};

int direction(Point X, Point Y, Point Z)
{
    // for X and Z
    int p1 = Z.x - X.x;
    int p2 = Z.y - X.y;

    Point P1;
    P1.x = p1;
    P1.y = p2;

    // for X and Y
    p1 = Y.x - X.x;
    p2 = Y.y - X.y;

    Point P2;
    P2.x = p1;
    P2.y = p2;

    int mul1 = P1.x * P2.y;
    int mul2 = P2.x * P1.y;

    int sub = mul1 - mul2;

    return sub;
}

bool On_Segment(Point P1, Point P2, Point P3)
{
    if ((min(P1.x, P2.x) <= P3.x && P3.x <= max(P1.x, P2.x)) &&
        (min(P1.y, P2.y) <= P3.y && P3.y <= max(P1.y, P2.y)))
        return true;
    else
        return false;
}

bool Segment_InterSect(Point p1, Point p2, Point p3, Point p4)
{
    int D1 = direction(p3, p4, p1);
    int D2 = direction(p3, p4, p2);
    int D3 = direction(p1, p2, p3);
    int D4 = direction(p1, p2, p4);

    if ((D1 * D2) < 0 && (D3 * D4) < 0)
        return true;
    else if (D1 == 0 && On_Segment(p3, p4, p1))
        return true;
    else if (D2 == 0 && On_Segment(p3, p4, p2))
        return true;
    else if (D3 == 0 && On_Segment(p1, p2, p3))
        return true;
    else if (D4 == 0 && On_Segment(p1, p2, p4))
        return true;

    return false;
}

int main()
{
    Point p1;
    p1.x = 1;
    p1.y = 1;
    Point p2;
    p2.x = 4;
    p2.y = 8;
    Point p3;
    p3.x = 2;
    p3.y = 6;
    Point p4;
    p4.x = 6;
    p4.y = 3;

    if(Segment_InterSect(p1,p2,p3,p4) == true)
    cout<<"Lines Are InterSecting" ; 
    else
    cout<<"Lines Are Not InterSecting";
    return 0;
}
