#include <iostream>
#include <limits>  // For max/min limits
#include <stdexcept>

template<typename T>
class GenericArray {
private:
    T* array;
    int array_size;

public:
    // Constructor
    GenericArray() {
        array = nullptr;
        array_size = 0;
    }

    // Destructor
    ~GenericArray() {
        delete[] array;
    }

    // Add element to the end of the array
    void addElement(T element) {
        T* new_array = new T[array_size + 1];
        for (int i = 0; i < array_size; i++) {
            new_array[i] = array[i];
        }
        new_array[array_size] = element;
        delete[] array;
        array = new_array;
        array_size++;
    }

    // Return value at index param
    T at(int param) {
        if (param >= 0 && param < array_size) {
            return array[param];
        }
        throw std::out_of_range("Index out of range");
    }

    // Return size of the array
    int size() {
        return array_size;
    }

    // Return sum of all elements
    T sum() {
        T total = 0;
        for (int i = 0; i < array_size; i++) {
            total += array[i];
        }
        return total;
    }

    // Return maximum element
    T max() {
        if (array_size == 0) throw std::runtime_error("Array is empty");
        T max_val = array[0];
        for (int i = 1; i < array_size; i++) {
            if (array[i] > max_val) {
                max_val = array[i];
            }
        }
        return max_val;
    }

    // Return minimum element
    T min() {
        if (array_size == 0) throw std::runtime_error("Array is empty");
        T min_val = array[0];
        for (int i = 1; i < array_size; i++) {
            if (array[i] < min_val) {
                min_val = array[i];
            }
        }
        return min_val;
    }

    // Return a new array with sliced elements from begin to end (inclusive)
    T* slice(int begin, int end) {
        if (begin < 0 || end >= array_size || begin > end) {
            throw std::out_of_range("Slice indices out of bounds");
        }

        int new_size = end - begin + 1;
        T* sliced = new T[new_size];
        for (int i = 0; i < new_size; i++) {
            sliced[i] = array[begin + i];
        }
        return sliced;
    }
};


