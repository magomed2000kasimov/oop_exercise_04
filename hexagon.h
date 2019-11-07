#pragma once

#include "point.h"

template<class T>
struct hexagon {
private:
    point<T> a1,a2,a3,a4,a5,a6;
public:
    point<T> center() const;
    void print(std::ostream& os) const;
    double area() const;
    hexagon(std::istream& is);
};

template<class T>
point<T> hexagon<T>::center() const {
    T x,y;
    x = (a1.x + a2.x + a3.x + a4.x + a5.x + a6.x) / 6;
    y = (a1.y + a2.y + a3.y + a4.y + a5.y + a6.y) / 6;
    return {x,y};
}

template<class T>
hexagon<T>::hexagon(std::istream &is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
}

template<class T>
void hexagon<T>::print(std::ostream& os) const {
    os << "coordinate:\n"<<"{\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n' << a6 << "}\n";
}

template<class T>
double hexagon<T>::area() const {
    return (0.5) * abs(((a1.x*a2.y + a2.x*a3.y + a3.x*a4.y + a4.x*a5.y + a5.x*a6.y + a6.x*a1.y) - ( a1.y*a2.x + a2.y*a3.x + a3.y*a4.x + a4.y*a5.x + a5.y*a6.x + a6.y*a1.x )));
}