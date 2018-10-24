#include <stdio.h>

#define TAM 10

void print(int *arr, int size);
void mergesort(int *arr, int start, int end);
void merge(int *arr, int startRight, int mid, int endLeft);

int main(){
    int v[TAM] = {TAM, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(v, TAM);
    mergesort(v, 0, TAM - 1);
    print(v, TAM);
}

void print(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", *arr++);
    printf("\n");
}

void mergesort(int *arr, int start, int end){
    void merge(int *arr, int startLeft, int mid, int endRight){
        int size = endRight - startLeft + 1;
        int temp[size];

        int right = mid + 1;
        int left = startLeft;
        int index = 0;
        while(right <= endRight && left <= mid){
            if(arr[right] < arr[left]){
                temp[index] = arr[right];
                right++;
            }
            else{
                temp[index] = arr[left];
                left++;
            }
            index++;
        }
        for(int i = right; i <= endRight; i++)
            temp[index++] = arr[i];
        for(int i = left; i <= mid; i++)
            temp[index++] = arr[i];
        index = 0;
        for(int i = startLeft; i <= endRight; i++)
            arr[i] = temp[index++];
    }
    if(start < end){
        int m = (start + end) / 2;
        mergesort(arr, start, m);
        mergesort(arr, m + 1, end);
        merge(arr, start, m, end);
    }
}

