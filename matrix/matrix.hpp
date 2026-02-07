#pragma once
#include <cstring>
#include <iostream>
#include <pthread.h>
class mat {
private:
  double *data;
  mat multiply(mat &a, mat &b);

public:
  int row, col;
  int len;
  mat(int rows, int cols) {
    row = rows;
    col = cols;
    data = new double[row * col];
    len = row * col;
  }
  ~mat() { delete[] data; }
  double get(int x, int y) { return data[y + col * x]; }
  void set(int x, int y, double value) { data[y + col * x] = value; }
  double *GetAddr() { return data; }
  void zero() {
    for (int i = 0; i < len; i++) {
      data[i] = 0.0f;
    }
  }
  void identity() {
    if (row == col) {
      this->zero();
      for (int i = 0; i < len; i += row + 1) {
        data[i] = 1.0f;
      }
    } else {
      std::cout << "that ain't a square is it?";
      throw std::invalid_argument("received incompatibe size");
    }
  }
  void print() {
    for (int i = 0; i < row * col; i++) {
      std::cout << '[' << data[i] << ']';
      if (((i + 1) % col) == 0) {
        std::cout << std::endl;
      }
    }
    std::cout << std::endl;
  }
};
inline mat *copy(mat &in) {
  mat *out = new mat(in.row, in.col);
  double *data = out->GetAddr();
  memcpy(data, in.GetAddr(), in.row * in.col * sizeof(double));
  return out;
}
inline mat multiply(mat &a, mat &b) {
  if (a.col != b.row) {
    throw std::invalid_argument("invalid matrix multiplication");
  }
  double sum;
  mat res = mat(a.row, b.col);
  double *data = res.GetAddr();
  for (int x = 0; x < res.row; x++)
    for (int y = 0; y < res.col; y++) {
      sum = 0.0f;
      for (int i = 0; i < a.col; i++) {
        sum += a.get(x, i) * b.get(i, y);
      }
      res.set(x, y, sum);
    }
  return res;
}
