#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

bool validateInput(Point p1, Point p2, Point p3, Point p4) {
    return !(p1.x == p2.x && p1.y == p2.y) && !(p3.x == p4.x && p3.y == p4.y);
}

void findIntersection(Point p1, Point p2, Point p3, Point p4) {
    if (!validateInput(p1, p2, p3, p4)) {
        cout << "error" << endl;
        return;
    }

    // 计算A、B、C值
    double A1 = p2.y - p1.y;
    double B1 = p1.x - p2.x;
    double C1 = A1 * p2.x + B1 * p2.y;

    double A2 = p4.y - p3.y;
    double B2 = p3.x - p4.x;
    double C2 = A2 * p4.x + B2 * p4.y;

    // 计算行列式
    double detX = determinant(A1, B1, A2, B2);
    
    if (detX == 0) {
        if (determinant(p3.y - p1.y, p2.y - p1.y, p3.x - p1.x, p2.x - p1.x) == 0) {
        // if (determinant(A1, B1, A2, B2) == 0) {
            cout << "coincide" << endl;
        } else {
            cout << "parallel" << endl;
        }
        return;
    }
    
    // 使用克莱姆法则计算交点
    double x = determinant(C1, B1, C2, B2) / detX;
    double y = determinant(A1, C1, A2, C2) / detX;
    
    // 打印结果，保留两位小数
    cout << fixed << setprecision(2) << x << "," << y << endl;
}

int main() {
    Point p1, p2, p3, p4;

    cout << "请输入直线1的点(x11, y11)和(x12, y12): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    cout << "请输入直线2的点(x21, y21)和(x22, y22): ";
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    findIntersection(p1, p2, p3, p4);

    return 0;
}