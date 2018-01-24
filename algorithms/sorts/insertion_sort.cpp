#include <iostream>

void insertion_sort(int * numbers, const int size){
    int temp;
    for (int i = 1; i < size; i++) {
        for(int j = i ; j > 0 ; j--){
            if(numbers[j] < numbers[j-1]){
                temp = numbers[j];
                numbers[j] = numbers[j-1];
                numbers[j-1] = temp;
            }
        }
    }
}

int main(){

    int size = 7;
    int numbers[] = {900,3,5,1,4352642,34,329};

    insertion_sort(numbers, size);

    for(int i = 0; i < size; i++){
        std::cout << numbers[i] << " ";
    }

};