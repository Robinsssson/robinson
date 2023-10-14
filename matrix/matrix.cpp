#include "matrix.h"
#include <iostream>

using namespace robinson::matrix;
//row 行数 column 列数

Matrix::Matrix(int row, int col, const double *mat) : m_col(col), m_row(row) {
    m_mat = std::make_unique<std::vector<double>>(col * row);
    for (int i = 0; i < col * row; i++) {
        m_mat->at(i) = *(mat + i);
    }
}

Matrix::Matrix(int row, int col) : m_col(col), m_row(row) {
    m_mat = std::make_unique<std::vector<double>>(col * row);
}

Matrix::Matrix(int row, int col, std::initializer_list<double> list) : m_col(col), m_row(row) {
    m_mat = std::make_unique<std::vector<double>>(col * row);
    int n = 0;
    for (auto i = list.begin(); i < list.end(); i++) {
        m_mat->at(n) = *i;
        n++;
    }

}

void Matrix::print() const {
    for (int i = 0; i < m_row; i++) {
        std::cout << '[';
        for (int j = 0; j < m_col; j++) {
            std::cout << m_mat->at(j + i * m_col);
            if (j != m_col - 1) {
                std::cout << ' ';
            }
        }
        std::cout << ']' << '\n';
    }
}

double &Matrix::operator[](int x) const {
    return m_mat->at(x);
}

double &Matrix::at(int row, int col) const {
    return m_mat->at(col + row * m_col);
}

void Matrix::set(int row, int col, double val) {
    m_mat->at(col + row * m_col) = val;
}

Matrix &robinson::matrix::operator+(const Matrix &m1, const Matrix &m2) {
    auto *m3 = new Matrix(m1.m_row, m1.m_col);
    if (m1.m_col != m2.m_col || m1.m_row != m2.m_row) {
        std::cout << "Plus error" << std::endl;
        return *m3;
    }
    for (int i = 0; i < m3->m_row * m3->m_col; i++) {
        m3->m_mat->at(i) = m1.m_mat->at(i) + m2.m_mat->at(i);
    }
    return *m3;
}

Matrix &robinson::matrix::operator-(const Matrix &m1, const Matrix &m2) {
    auto *m3 = new Matrix(m1.m_row, m1.m_col);
    if (m1.m_col != m2.m_col || m1.m_row != m2.m_row) {
        std::cout << "dis error" << std::endl;
        return *m3;
    }
    for (int i = 0; i < m3->m_row * m3->m_col; i++) {
        m3->m_mat->at(i) = m1.m_mat->at(i) - m2.m_mat->at(i);
    }
    return *m3;
}

Matrix::Matrix(Matrix const &matrix) {
    m_row = matrix.m_row;
    m_col = matrix.m_col;
    m_mat = std::make_unique<std::vector<double>>(m_col * m_row);
    int n = 0;
    for (auto i: *matrix.m_mat) {
        m_mat->at(n) = i;
        n++;
    }
}

Matrix &robinson::matrix::operator*(const Matrix &m1, const Matrix &m2) {
    auto *m3 = new Matrix(m1.m_row, m2.m_col);
    if (m1.m_col != m2.m_row) {
        std::cout << "multi error" << std::endl;
        return *m3;
    }
    for (int row = 0; row < m1.m_row; row++) {
        for (int col = 0; col < m2.m_col; col++) {
            double val = 0;
            for (int i = 0; i < m1.m_col; i++) {
                val += m1.at(row, i) * m2.at(i, col);
            }
            m3->at(row, col) = val;
        }
    }
    return *m3;
}

std::vector<double> Matrix::get_col(int col) const {
    std::vector<double> v;
    v.reserve(m_row);
    for (int i = 0; i < m_row; i++) {
        v.push_back(m_mat->at(col + i * m_col));
    }
    return v;
}

std::vector<double> Matrix::get_row(int row) const {
    std::vector<double> v;
    v.reserve(m_col);
    for (int i = 0; i < m_col; i++) {
        v.push_back(m_mat->at(m_col * row + i));
    }
    return v;
}

Matrix &Matrix::operator=(const Matrix &m) {
    m_col = m.get_colsize();
    m_row = m.get_rowsize();
    m_mat = std::make_unique<std::vector<double>>(m_col * m_row);
    int n = 0;
    for (auto i: *m.m_mat) {
        m_mat->at(n) = i;
        n++;
    }
    return *this;
}