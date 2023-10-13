#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>
#include <memory>
#include <iostream>

namespace robinson {
    namespace matrix {
        class Matrix {
        public:
            Matrix(int row, int col, const double *);

            Matrix(int row, int col, std::initializer_list<double> list);

            Matrix(int row = 0, int col = 0);

            Matrix(Matrix const &matrix);

            ~Matrix() { std::cout << "Destory" << std::endl; };

            friend Matrix &operator+(const Matrix &m1, const Matrix &m2);

            friend Matrix &operator-(const Matrix &m1, const Matrix &m2);

            friend Matrix &operator*(const Matrix &m1, const Matrix &m2);

            friend Matrix &operator/(const Matrix &m1, const Matrix &m2);

            Matrix &operator=(const Matrix &m);

            double &operator[](int x) const;

            void print() const;

            double &at(int row, int col) const;

            void set(int row, int col, double val);

            int get_colsize() const { return m_col; }

            int get_rowsize() const { return m_row; }


            std::vector<double> get_col(int col) const;

            std::vector<double> get_row(int row) const;

            const std::vector<double> get_arr() const { return *m_mat; }

        private:
            int m_col, m_row;
            std::unique_ptr<std::vector<double>> m_mat = nullptr;
        };
    }
}


#endif //MATRIX_MATRIX_H
