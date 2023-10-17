//
// Created by robinson on 2023/10/14.
//

#ifndef ROBINSON_POINT_H
#define ROBINSON_POINT_H

#include <iostream>

namespace robinson {
    namespace point {
        template<class T>
        class Point {
        public:
            Point(T x, T y) : m_x(x), m_y(y) {}

            Point(Point<T> &p) {
                m_x = p.m_x;
                m_y = p.m_y;
            }

            ~Point() = default;

            Point<T> &operator+(const Point<T> p) {
                this->m_y += p.m_y;
                this->m_x += p.m_x;
                return this;
            }

            void print() const {
                std::cout << '(' << m_x << ", " << m_y << ')' << std::endl;
            }

        private:
            T m_x, m_y;
        };

    } // robinson
} // point

#endif //ROBINSON_POINT_H
