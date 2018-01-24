#include <iostream>

void merge(const int * arr1, const int * arr2, const int size1, const int size2, int *res){
    int j = 0; int i = 0;
    while(i < size1 && j < size2){
        if(arr1[i] > arr2[j]){
            res[i+j] = arr2[j];
            j++;
        }else{
            res[i+j] = arr1[i];
            i++;
        }
    }
    // cleanup remaining numbers
    while(i < size1){
        res[i+j] = arr1[i];
        i++;
    }
    while(j < size2){
        res[i+j] = arr2[j];
        j++;
    }
}

void merge_sort(int * numbers, int size){
    if(size == 1) {
        return;
    }
    else{
        int size1 = size/2; int size2 = size - size1;
        int first_half[size1]; int second_half[size2];
        for(int i = 0; i < size; i++){
            if(i < size1){
                first_half[i] = numbers[i];
            } else {
                second_half[i - size1] = numbers[i];
            }
        }
        merge_sort(first_half, size1);
        merge_sort(second_half, size2);
        merge(first_half, second_half, size1, size2, numbers);
    }
}

int main(){

    int size = 7;
    int numbers[] = {900,3,5,1,4352642,34,329};

    merge_sort(numbers, size);

    for(int i = 0; i < size; i++){
        std::cout << numbers[i] << " ";
    }

};

