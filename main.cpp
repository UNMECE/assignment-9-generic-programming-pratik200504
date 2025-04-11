#include <iostream>
#include <limits>  // For max/min limits
#include <stdexcept>

template<typename T>
class GenericArray {
private:
    T* array;
    int array_size;

public:
    // constructor
    GenericArray() {
        array = nullptr;
        array_size = 0;
    }

    // destructor
    ~GenericArray() {
        delete[] array;
    }

    // add element to the end of the array
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

    // return value at index param
    T at(int param) {
        if (param >= 0 && param < array_size) {
            return array[param];
        }
        throw std::out_of_range("Index out of range");
    }

    // return size of the array
    int size() {
        return array_size;
    }

    // return sum of all elements
    T sum() {
        T total = 0;
        for (int i = 0; i < array_size; i++) {
            total += array[i];
        }
        return total;
    }

    // return maximum element
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

    // return minimum element
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

    // return a new array with sliced elements from start to end
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

int main() {
    GenericArray<int> int_array;

    //adding myself some elements
    int_array.addElement(10);
    int_array.addElement(20);
    int_array.addElement(30);
    int_array.addElement(40);
    int_array.addElement(50);
    int_array.addElement(60);
    int_array.addElement(70);
    int_array.addElement(80);
    int_array.addElement(90);
    int_array.addElement(100);

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is "
              << int_array.max() << "\t" << int_array.min() << std::endl;

    int* sliced_array = int_array.slice(5, 9);  // 6th to 10th elemetns
    std::cout << "sliced array is: ";
    for (int i = 0; i <= 9 - 5; ++i) {
        std::cout << sliced_array[i] << " ";
    }
    std::cout << std::endl;

    delete[] sliced_array;
    return 0;
}

