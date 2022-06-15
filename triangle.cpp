#include "triangle.h"
#include <cmath>
using namespace std;
#define __DBL_EPSILON__ 1e-12
#define M_PI 3.14

triangle::triangle() { //конструктор по умолчанию
    this->a = 0;
    this->b = 0;
    this->angC = 0;
}
triangle::triangle(float first, float second, int ang)   { //конструктор с параметрами
    if (first <= __DBL_EPSILON__ || second <= __DBL_EPSILON__ || ang <= 1 || ang >= 178) {
        cout << ":)>Wrong initialization" << endl;
    }
    else {
        this->a = first;
        this->b = second;
        this->angC = ang;
    }
}
triangle::triangle(const triangle& src) { //конструктор копирования
    this->a = src.a;
    this->b = src.b;
    this->angC = src.angC;
}
triangle& triangle::operator== (double x) { //перегрузка оператора ==
    this->a == x;
    this->b == x;
    return *this;
}
triangle::~triangle() { //деструктор
    this->a = 0;
    this->b = 0;
    this->angC = 0;
    delete this;
}

float triangle::third_side() { //вычисление 3 стороны треугольника
    float c,a;
    a = sqrt(this->a * this->a + this->b * this->b - 2 * this->a * this->b * cos(this->angC * M_PI / 180));
    c = round(a * 10) / 10;
    return c;
}
void triangle::type() { // тип треугольника
    float a, b, c;
    double angle0, angle1, angle2, maxAngle;
    a = this->a;
    b = this->b;
    c = this->third_side();
    angle0 = acos((b * b + c * c - a * a) / (2 * b * c));
    angle1 = acos((c * c + a * a - b * b) / (2 * a * c));
    angle2 = acos((a * a + b * b - c * c) / (2 * a * b));
    maxAngle = angle0 > angle1 ? (angle0 > angle2 ? angle0 : angle2) : (angle1 > angle2 ? angle1 : angle2);
    if (a + b > c || b + c > a || c + a > b) {
    if (maxAngle == M_PI / 2) {
        cout << ":)>right\n";
    }
    else if (maxAngle > M_PI / 2) {
        cout << ":)>obtuse\n";
    }
    else {
        cout << ":)>ocute\n";
    }
   }
    else
        cout << ":)>impossible\n";//нет такого
    getchar();
}
void triangle::perimeter() { //вычисление периметра
    float P, c, a;
    c = this->third_side();
    a = (this->a + this->b + c);
    P = round(a * 10) / 10;
    cout << ":)>perimeter : " << P << endl;
    getchar();
}
void triangle::opis_radius() { //вычисление радиуса описанной окружности
    float r, p, c;
    c = this->third_side();
    p = (this->a + this->b + c) / 2;
    r = this->a * this->b * c / (4 * sqrt(p * (p - this->a) * (p - c) * (p - this->b)));
    cout << ":)>Radius opisannoy okryzhnosti : " << round(r * 10) / 10 << endl;
    getchar();
}
void triangle::corner() { //определение наименьшего угла
    float a,b,c,h;
    double angle0, angle1, angle2, minAngle;
    a = this->a;
    b = this->b;
    c = this->third_side();
    angle0 = acos((b * b + c * c - a * a) / (2 * b * c));
    angle1 = acos((c * c + a * a - b * b) / (2 * a * c));
    angle2 = acos((a * a + b * b - c * c) / (2 * a * b));
    if (angle0 < angle1 || angle0 < angle2) {
        h = angle0;
    }
    else if (angle1 < angle2 || angle1 < angle0) {
        h = angle1;
    }
    else {
        h = angle2;
    }
    cout << ":)>smallest angle : " << h  << endl;
    getchar();
}

istream& operator >> (istream& in, triangle& tr) { //оператор ввода треугольника
    cout << "Enter side A : ";
    in >> tr.a;
    if (tr.a < __DBL_EPSILON__) {
        cout << ":)>Wrong data. Enter again : ";
        in >> tr.a;
    }
    cout << "Enter side B : ";
    in >> tr.b;
    if (tr.b < __DBL_EPSILON__) {
        cout << ":)>Wrong data. Enter again : ";
        in >> tr.b;
    }
    cout << "Enter angle between sides A and B : ";
    in >> tr.angC;
    if (tr.angC <= 0 || tr.angC >= 178) {
        cout << ":)>Wrong data. Enter again : ";
        in >> tr.angC;
    }
    return in;
}
ostream& operator << (ostream& stream, triangle& tr) { //оператор вывода треугольника
    stream << "A = " << tr.a << ", B = " << tr.b << ", Between angle = " << tr.angC << endl;
    return stream;
    
}