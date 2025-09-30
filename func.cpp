#include <iostream>
#include "func.h"
#include <cmath>

Tochka ReadTochka () {
    Tochka p{};
    std::cin  >> p.x >> p.y;    
    return p;
}

 void PrintTochka (Tochka& p) {
    std::cout << "Координаты точки: (" << p.x << "; " << p.y << ")" << std::endl;
 }

 Circle ReadCircle () {
    Circle krug{};
    std::cin >> krug.center.x >> krug.center.y;
    std::cout << "Введите радиус круга: ";
    std::cin >> krug.radius;
    return krug;
 }

 void PrintCircle (Circle& krug) {
    std::cout << "Координаты центра: (" << krug.center.x << "; " << krug.center.y << ")\n"
    << "Радиус: " << krug.radius << "\n"
    << "Площадь: " << krug.area << "\n"
    << "Длина окружности: " << krug.lenght << "\n";
}

 Circle CountAreaC (Circle& krug) {
    krug.area = M_PI * krug.radius * krug.radius;
   return krug;
 }

 Circle CountLength (Circle& krug) {
    krug.lenght = 2 * M_PI * krug.radius;
    return krug;
 }

 Quadrate ReadQuadrate() {
   Quadrate q{};
   std::cin >> q.angle.x >> q.angle.y;
   std::cout << "Введите длину стороны квадрата: ";
   std::cin >> q.side;
   return q;
 }

 Quadrate CountAreaQ (Quadrate& q) {
   q.area = q.side * q.side;
   return q;
 }

 Quadrate CountPerimeter (Quadrate& q) {
   q.perimeter = q.side * 4;
   return q;
 }

 void PrintQuadrate (Quadrate& q) {
   std::cout << "Координаты верхнего левого угла: (" << q.angle.x << "; " << q.angle.y << ")\n"
    << "Длина стороны: " << q.side << "\n"
    << "Площадь: " << q.area << "\n"
    << "Периметр: " << q.perimeter << "\n";
 }

bool TochkaInCircle(Tochka& p, Circle& c) {
   double dx = p.x - c.center.x;
   double dy = p.y - c.center.y;
   return dx*dx + dy*dy < c.radius * c.radius;  
}

bool TochkaInQuadrate(Tochka& p, Quadrate& q) {
   double left = q.angle.x;
   double right = q.angle.x + q.side;
   double top = q.angle.y;
   double bottom = q.angle.y - q.side;
   return (p.x > left) && (p.x < right) && (p.y > bottom) && (p.y < top); 
}

bool TochkaOnCircle(Tochka& p, Circle& c) {
   double dx = p.x - c.center.x;
   double dy = p.y - c.center.y;
   return dx*dx + dy*dy == c.radius * c.radius; 
}

bool TochkaOnQuadrate(Tochka& p, Quadrate& q) {
   double left = q.angle.x;
   double right = q.angle.x + q.side;
   double top = q.angle.y;
   double bottom = q.angle.y - q.side;

   bool on_left = (p.x == left)  && (p.y >= bottom) && (p.y <= top);
   bool on_right = (p.x == right) && (p.y >= bottom) && (p.y <= top);
   bool on_top = (p.y == top)   && (p.x >= left)   && (p.x <= right);
   bool on_bottom = (p.y == bottom)&& (p.x >= left)   && (p.x <= right);

   if ((p.x > left) && (p.x < right) && (p.y > bottom) && (p.y < top)) {
      return false;
   }
   return on_left || on_right || on_top || on_bottom;
}

bool IntersectCircles(Circle& a, Circle& b) {
   double dx = a.center.x - b.center.x;
   double dy = a.center.y - b.center.y;
   double d = std::sqrt(dx*dx + dy*dy);
   double rsum = a.radius + b.radius;
   double rdiff = std::abs(a.radius - b.radius);
   return (d <= rsum) && (d >= rdiff); 
}

bool IntersectQuadrates(Quadrate& q1, Quadrate& q2) {
   double a_left = q1.angle.x;
   double a_right = q1.angle.x + q1.side;
   double a_top = q1.angle.y;
   double a_bottom = q1.angle.y - q1.side;

   double b_left = q2.angle.x;
   double b_right = q2.angle.x + q2.side;
   double b_top = q2.angle.y;
   double b_bottom = q2.angle.y - q2.side;

   if (a_right < b_left || b_right < a_left || a_top < b_bottom || b_top < a_bottom)
       return false;

   bool a_in_b = (a_left > b_left) && (a_right < b_right) && (a_bottom > b_bottom) && (a_top < b_top);
   bool b_in_a = (b_left > a_left) && (b_right < a_right) && (b_bottom > a_bottom) && (b_top < a_top);
   if (a_in_b || b_in_a) {
      return false;
   }
   return true;
}

bool IntersectCircleQuadrate(Circle& c, Quadrate& q) {
   double left = q.angle.x;
   double right = q.angle.x + q.side;
   double top = q.angle.y;
   double bottom = q.angle.y - q.side;

   bool cx_inside = (c.center.x >= left) && (c.center.x <= right);
   bool cy_inside = (c.center.y >= bottom) && (c.center.y <= top);

   if (cx_inside && cy_inside) {
       double d_left   = c.center.x - left;
       double d_right  = right - c.center.x;
       double d_top    = top - c.center.y;
       double d_bottom = c.center.y - bottom;
       double min_edge = std::min(std::min(d_left, d_right), std::min(d_top, d_bottom));
       return c.radius >= min_edge;
   } else {
       double dx = 0.0;
       if (c.center.x < left) dx = left - c.center.x;
       else if (c.center.x > right) dx = c.center.x - right;

       double dy = 0.0;
       if (c.center.y < bottom) dy = bottom - c.center.y;
       else if (c.center.y > top) dy = c.center.y - top;

       double dist = std::sqrt(dx*dx + dy*dy);
       return dist <= c.radius;
   }
}

bool CircleInCircle(Circle& a, Circle& b) {
   double dx = a.center.x - b.center.x;
   double dy = a.center.y - b.center.y;
   double d = std::sqrt(dx*dx + dy*dy);
   return d + a.radius < b.radius; 
}

bool QuadrateInQuadrate(Quadrate& q1, Quadrate& q2) {
   double a_left = q1.angle.x;
   double a_right = q1.angle.x + q1.side;
   double a_top = q1.angle.y;
   double a_bottom = q1.angle.y - q1.side;

   double b_left = q2.angle.x;
   double b_right = q2.angle.x + q2.side;
   double b_top = q2.angle.y;
   double b_bottom = q2.angle.y - q2.side;

   return (a_left > b_left) && (a_right < b_right) && (a_bottom > b_bottom) && (a_top < b_top);
}

bool QuadrateInCircle(Quadrate& q, Circle& c) {
   double left = q.angle.x;
   double right = q.angle.x + q.side;
   double top = q.angle.y;
   double bottom = q.angle.y - q.side;

   double dx, dy;

   dx = left - c.center.x;  dy = top - c.center.y;
   if (!(dx*dx + dy*dy < c.radius * c.radius)) {
      return false;
   }
   dx = right - c.center.x; dy = top - c.center.y;
   if (!(dx*dx + dy*dy < c.radius * c.radius)) {
      return false;
   }
   dx = left - c.center.x;  dy = bottom - c.center.y;
   if (!(dx*dx + dy*dy < c.radius * c.radius)) {
      return false;
   }

   dx = right - c.center.x; dy = bottom - c.center.y;
   if (!(dx*dx + dy*dy < c.radius * c.radius)) {
      return false;
   }
   return true;
}

bool CircleInQuadrate(Circle& c, Quadrate& q) {
   double left = q.angle.x;
   double right = q.angle.x + q.side;
   double top = q.angle.y;
   double bottom = q.angle.y - q.side;

   return (c.center.x - c.radius > left)  &&
          (c.center.x + c.radius < right) &&
          (c.center.y + c.radius < top)   &&
          (c.center.y - c.radius > bottom);
}