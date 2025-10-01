#include <iostream>
#include "func.h"


int main () {
    std::cout << "Введите координаты точки: ";
    Tochka p = ReadTochka();
    PrintTochka(p);

    std::cout << "Введите координаты центра круга: ";
    Circle krug = ReadCircle();
    CountAreaC(krug);
    CountLength(krug);
    PrintCircle(krug);

    std::cout << "Введите координаты верхнего левого угла квадрата: ";
    Quadrate q = ReadQuadrate();
    CountAreaQ(q);
    CountPerimeter(q);
    PrintQuadrate(q);

    std::cout << "Точка строго внутри круга? " << (TochkaInCircle(p, krug) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго на окружности? " << (TochkaOnCircle(p, krug) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго внутри квадрата? " << (TochkaInQuadrate(p, q) ? "Да" : "Нет") << "\n";
    std::cout << "Точка строго на границе квадрата? " << (TochkaOnQuadrate(p, q) ? "Да" : "Нет") << "\n";


    std::cout << "\nПересечение двух кругов\n";
    std::cout << "Введите координаты центра первого круга:\n";
    Circle c1 = ReadCircle();
    CountAreaC(c1); CountLength(c1);

    std::cout << "Введите координаты центра второго круга:\n";
    Circle c2 = ReadCircle();
    CountAreaC(c2); CountLength(c2);

    std::cout << "Пересекаются два круга? " << (IntersectCircles(c1, c2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПересечение двух квадратов\n";
    std::cout << "Введите координаты верхнего левого угла первого первого квадрата:\n";
    Quadrate q1 = ReadQuadrate();
    CountAreaQ(q1); CountPerimeter(q1);

    std::cout << "Введите координаты верхнего левого угла первого второго квадрата:\n";
    Quadrate q2 = ReadQuadrate();
    CountAreaQ(q2); CountPerimeter(q2);

    std::cout << "Пересекаются два квадрата? " << (IntersectQuadrates(q1, q2) ? "Да" : "Нет") << "\n";

    std::cout << "\nПересечение круга и квадрата\n";
    std::cout << "Введите координаты центра круга:\n";
    Circle c3 = ReadCircle();
    CountAreaC(c3); CountLength(c3);

    std::cout << "Введите координаты верхнего левого угла квадрата:\n";
    Quadrate q3 = ReadQuadrate();
    CountAreaQ(q3); CountPerimeter(q3);

    std::cout << "Пересекаются круг и квадрат? " << (IntersectCircleQuadrate(c3, q3) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: круг внутри круга\n";
    std::cout << "Введите координаты центра первого круга:\n";
    Circle cc_in = ReadCircle();
    CountAreaC(cc_in); CountLength(cc_in);

    std::cout << "Введите координаты центра круга:\n";
    Circle cc_out = ReadCircle();
    CountAreaC(cc_out); CountLength(cc_out);

    std::cout << "Первый круг строго внутри второго? " << (CircleInCircle(cc_in, cc_out) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: квадрат внутри квадрата\n";
    std::cout << "Введите координаты верхнего левого угла первого квадрата:\n";
    Quadrate qq_in = ReadQuadrate();
    CountAreaQ(qq_in); CountPerimeter(qq_in);

    std::cout << "Введите координаты верхнего левого угла второго квадрата:\n";
    Quadrate qq_out = ReadQuadrate();
    CountAreaQ(qq_out); CountPerimeter(qq_out);

    std::cout << "Первый квадрат строго внутри второго? " << (QuadrateInQuadrate(qq_in, qq_out) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: квадрат внутри круга\n";
    std::cout << "Введите координатв верхнего левого квадрата:\n";
    Quadrate qi = ReadQuadrate();
    CountAreaQ(qi); CountPerimeter(qi);

    std::cout << "Введите координаты центра круга:\n";
    Circle co = ReadCircle();
    CountAreaC(co); CountLength(co);

    std::cout << "Квадрат строго внутри круга? " << (QuadrateInCircle(qi, co) ? "Да" : "Нет") << "\n";

    std::cout << "\nПринадлежность: круг внутри квадрата\n";
    std::cout << "Введите координаты центра круга:\n";
    Circle ci = ReadCircle();
    CountAreaC(ci); CountLength(ci);

    std::cout << "Введите координаты левого верхнего угла квадрата:\n";
    Quadrate qo = ReadQuadrate();
    CountAreaQ(qo); CountPerimeter(qo);

    std::cout << "Круг строго внутри квадрата? " << (CircleInQuadrate(ci, qo) ? "Да" : "Нет") << "\n";
    return 0;
}