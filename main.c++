#include <bits/stdc++.h>
#include <array>
#include <iostream>
#include <stdexcept>


// Create a custom class that mimics the behaviour of std::vector

class DynamicArray {
   private:
        int* arr;
        int capacity;
        int size;


    void resize() {
        capacity *= 2;
        int* newArr;
        for (int i = 0; i < size; ++i){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }    

    public:
         DynamicArray(int initialCapacity = 4) : capacity(initialCapacity), size(0) {
             int arr[capacity];
         }

         ~DynamicArray() {
            delete[] arr;
         }


    void insert(int data){
      if(size == capacity){
          resize();
      };
      arr[size++] = data;   
    };


    void remove(int data) {
      int index = -1;  
      for(int i = 0; i < size; ++i){
        if(arr[i] == data){
            index = i;
            break;
        }
      }

      if (index != -1){
        for(int i = index; i < size - 1; ++i){
            arr[i] = arr[i + 1];
        }
        --size;
      }
    };

    int retrieve( int index) {
       if(index < 0 || index >= size){
         throw std::out_of_range("Index out of range");
       }
       return arr[index];
    };

    int getSize() const {
        return size;
    }

    void display() const {
        for(int i = 0; i < size; ++i){
           std::cout << arr[i] << " "; 
        }
        std::cout << std::endl;
    }
};