#pragma once

#include "structs.h"

Tochka ReadTochka ();
void PrintTochka (Tochka&);

Circle ReadCircle ();
Circle CountAreaC (Circle&);
Circle CountLength (Circle&);
void PrintCircle (Circle&);

Quadrate ReadQuadrate ();
Quadrate CountAreaQ (Quadrate&);
Quadrate CountPerimeter (Quadrate&);
void PrintQuadrate (Quadrate&);

bool TochkaInCircle (Tochka&, Circle&);
bool TochkaInQuadrate (Tochka&, Quadrate&);
bool TochkaOnCircle (Tochka&, Circle&);
bool TochkaOnQuadrate (Tochka&, Quadrate&);

bool IntersectCircles (Circle&, Circle&);
bool IntersectQuadrates (Quadrate&, Quadrate&);
bool IntersectCircleQuadrate (Circle&, Quadrate&);

bool CircleInCircle (Circle&, Circle&);
bool QuadrateInQuadrate (Quadrate&, Quadrate&);
bool QuadrateInCircle (Quadrate&, Circle&);
bool CircleInQuadrate (Circle&, Quadrate&);