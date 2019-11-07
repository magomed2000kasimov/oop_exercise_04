#pragma once

#include "point.h"

template<class T>
struct octagon {
private:
    point<T> a1,a2,a3,a4,a5,a6,a7,a8;
public:
    point<T> center() const;
    void print(std::ostream& os) const;
    double area() const;
    octagon(std::istream& is);
};

template<class T>
point<T> octagon<T>::center() const {
    T x,y;
    x = (a1.x + a2.x + a3.x + a4.x + a5.x + a6.x + a7.x + a8.x) / 8;
    y = (a1.y + a2.y + a3.y + a4.y + a5.y + a6.y + a7.y + a8.y) / 8;
    return {x,y};
}

template<class T>
octagon<T>::octagon(std::istream &is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8;
}

template<class T>
void octagon<T>::print(std::ostream& os) const {
    os << "coordinate:\n"<<"{\n"<< a1 << '\n' << a2 << '\n' << a3 << '\n' << a4 << '\n' << a5 << '\n' << a6 << '\n' << a7 << '\n' << a8 << "}\n";
}

template<class T>
double octagon<T>::area() const {
    return (-0.5) * ((a1.x*a2.y + a2.x*a3.y + a3.x*a4.y + a4.x*a5.y + a5.x*a6.y + a6.x*a7.y + a7.x*a8.y + a8.x*a1.y) - ( a1.y*a2.x + a2.y*a3.x + a3.y*a4.x + a4.y*a5.x + a5.y*a6.x + a6.y*a7.x + a7.y*a8.x + a8.y*a1.x));
}
