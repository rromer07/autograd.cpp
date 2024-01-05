// tensor.h

#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>
#include <type_traits>

class Tensor {
public:
    // Constructors
    Tensor(double value, bool requires_grad = false);
    Tensor(std::initializer_list<std::initializer_list<std::initializer_list<double>>> nestedList, bool requires_grad = false);

    // Overloaded << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Tensor& tensor);

    const std::vector<int>& Tensor::getShape() const;

    const std::vector<std::vector<double>>& Tensor::getData() const;

private:
    std::vector<std::vector<double>> data;
    std::vector<int> shape;
    bool requires_grad;

    // Recursive function for extracting shape from nested initializer list
    template <typename T>
    void extractShape(const T& nestedList);

    // Recursive function for extracting data from nested initializer list
    template <typename T>
    void extractData(const T& nestedList);

    template <typename T>
    void extractShapeAndData(const T& nestedList);
};
