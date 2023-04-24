#include "task.hpp"

// MARK: Удалить все строки короче 3 символов из массива строк
// MARK: Remove all strings shorter than 3 characters from the string array

custom_array findIndexs(char**& strings, int& array_length, int& str_length) {
    struct custom_array array;
    
    int ind_count = 0;
    int* indexs = (int*) malloc(ind_count * sizeof(int));
    
    for (int i = 0; i < array_length; i++) {
        int count = 0;
        
        for (int j = 0; strings[i][j] != '\0'; j++) { count += 1; }
        
        if (count < 3) {
            ind_count += 1;
            indexs = (int*) realloc(indexs, ind_count * sizeof(int));
            indexs[ind_count - 1] = i;
        }
    }
    
    array.ptr = indexs;
    array.length = ind_count;
    
    return array;
}

void deleteElemet(char**& strings, int& array_length, int index) {
    free(strings[index]);
    
    for (int i = index; i < array_length - 1; i++) {
        strings[i] = strings[i + 1];
    }
    
    array_length -= 1;
    
    strings = (char**) realloc(strings, array_length * sizeof(char*));
}

int main() {
	int str_length = 10;
    int array_length = 5;
    
    char** strings = (char**) malloc(array_length * sizeof(char*));
    
    for (int i = 0; i < array_length; i++) {
        strings[i] = (char*) malloc(str_length * sizeof(char));
        scanf("%s", strings[i]);
    }
    
    print2DArray(strings, array_length, str_length);
    
    // ptr_array, length
    struct custom_array ind_array = findIndexs(strings, array_length, str_length);
    
    for (int i = 0; i < ind_array.length; i++) {
        deleteElemet(strings, array_length, ind_array.ptr[i] - i);
    }
    
    print2DArray(strings, array_length, str_length);
    
    for (int i = 0; i < array_length; i++) {
        free(strings[i]);
        strings[i] = nullptr;
    }
    
    free(strings);
    free(ind_array.ptr);
    
    strings = nullptr;
    ind_array.ptr = nullptr;
}
