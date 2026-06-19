#include <iostream>
#include <cstdlib>
#include <ctime>

void task1() {
    std::cout << "--- Task 1 (Enter: int, float, double, char, bool) ---" << std::endl;
    
    int* pInt = new int;
    float* pFloat = new float;
    double* pDouble = new double;
    char* pChar = new char;
    bool* pBool = new bool;

    std::cin >> *pInt;
    std::cin >> *pFloat;
    std::cin >> *pDouble;
    std::cin >> *pChar;
    std::cin >> *pBool;

    std::cout << "Result 1:" << std::endl;
    std::cout << *pInt << std::endl;
    std::cout << *pFloat << std::endl;
    std::cout << *pDouble << std::endl;
    std::cout << *pChar << std::endl;
    std::cout << std::boolalpha << *pBool << std::endl;

    delete pInt;
    delete pFloat;
    delete pDouble;
    delete pChar;
    delete pBool;
}

void task2() {
    std::cout << "\n--- Task 2 (Enter: double) ---" << std::endl;
    
    double* pDouble = new double;
    double& refDouble = *pDouble;

    std::cin >> refDouble;
    std::cout << "Result 2: " << refDouble << std::endl;

    delete pDouble;
}

void task3() {
    std::cout << "\n--- Task 3 (Enter: array size) ---" << std::endl;
    
    int size;
    std::cin >> size;

    if (size <= 0) return;

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = size - 1 - i;
    }

    std::cout << "Result 3: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
}

void print3DArray(float*** arr, int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; ++i) {
        std::cout << "Page " << i << ":" << std::endl;
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                std::cout << arr[i][j][k] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void task4() {
    std::cout << "\n--- Task 4 (3D Array Automatically Generated) ---" << std::endl;
    int dim1 = 3, dim2 = 3, dim3 = 3;

    float*** arr = new float**[dim1];
    for (int i = 0; i < dim1; ++i) {
        arr[i] = new float*[dim2];
        for (int j = 0; j < dim2; ++j) {
            arr[i][j] = new float[dim3];
        }
    }

    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                arr[i][j][k] = static_cast<float>(std::rand()) / RAND_MAX * 100.0f;
            }
        }
    }

    print3DArray(arr, dim1, dim2, dim3);

    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    task1();
    task2();
    task3();
    task4();

    return 0;
}
