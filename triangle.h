#ifndef triangle_hpp
#define triangle_hpp
#include <iostream>

class triangle {
  
    float a,b;
    int angC;
public:
    triangle(); //конструктор по умолчанию
    triangle(float first, float second, int ang); //конструктор с параметрами
    triangle(const triangle &src); //конструктор копирования
    ~triangle(); //деструктор
    void type(); // метод определения треугольника
    float third_side(); //метод вычисление 3 стороны
    void perimeter(); //метод вычисление периметра
    void opis_radius(); //метод вычисление радиуса описанной окружности
    void corner(); //метод определение наименьшего угла
    triangle& operator==(double x); //перегрузка оператора ==
    friend std::istream& operator >> (std::istream&in, triangle &tr); //дружественный оператор ввода
    friend std::ostream& operator << (std::ostream&stream, triangle &tr); //дружественный оператор вывода
};

#endif /* triangle_hpp */
