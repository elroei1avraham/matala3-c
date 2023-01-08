#include <stdio.h>
#include <math.h>
#define Size 50 

void shift_element(int *arr, int i){
    for( int j =i; j>0; j--){
        *(arr+j) = *(arr+j-1);
    }
}

void insertion_sort(int *arr, int len){
    int *ptr;
    int i, val, j, counter;
    for (i = 1; i < len; i++) {
        counter = 0;
        val = *(arr+i);
        j = i - 1;
    
        while (j >= 0 && *(arr+j) > val) {  
                counter++;      
                j = j-1;
            }
            if(counter!=0){
            ptr = (arr+i-counter);
                shift_element(ptr, counter);
                *(arr+i-counter) = val;
            }
    }               
}

int main(){
    int arr [Size];
    for(int i=0; i<Size; i++ ){
        scanf("%d", arr+i);
    }
    insertion_sort(arr, Size);
    for(int i=0; i<Size; i++){
        printf("%d", *(arr+i));
        if(i!=Size-1){
            printf(",");
        }
    }
    printf("\n");

    return 0;
}