#include <iostream>
#include "triangle.h"
using namespace std;

int main(int argc, const char * argv[]) {
    triangle pipka(3,4,90), B;
    float third=pipka.third_side();
    int menu;
    do {
        system("CLS");
        cout << "1. triangle first and second site, angC" << endl;
        cout << "2. triangle B " << endl;
        cout << "3. third_side " << endl;
        cout << "4. type triangle " << endl;
        cout << "5. perimeter " << endl;
        cout << "6. opis_radius " << endl;
        cout << "7. small corner " << endl;
        cout << "0. Exit" << endl;
        cin >> menu;
        cin.ignore(32767, '\n');
        system("CLS");
        switch (menu) {
            case 1:
                cin >> B;
                break; // вписываем данные
            case 2:
                cout << B;
                getchar();                
                break; //присваиваются данные
            case 3:
                cout << ":)>third_side : " << B.third_side();
                getchar();                
                break; // вывожит 3 сторону
            case 4:
                B.type();                
                break; // выводит тип треугольника
            case 5:
                B.perimeter();
                break; // выводит периметр
            case 6:
                B.opis_radius();
                break; // выводит описанную окружность
            case 7:
                B.corner();
                break; // выводит наименьший угол в радианах
            default:
                break;
            }
    } while (menu != 0);
    return 0;
}
