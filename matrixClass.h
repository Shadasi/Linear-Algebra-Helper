#include <vector>

#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H


class matrixClass
{
public:
    matrixClass();
    void initialize();
    void menu();
    void addValues();
    void printmatrixClass(std::vector<std::vector<int>>&);
    void mtxAddition();
    void mtxSubtraction();
    void mtxMultiplication();
private:
    std::vector<std::vector<int>> mtx1;
    std::vector<std::vector<int>> mtx2;
    std::vector<std::vector<int>> result;
};

#endif // matrixClass_H
