#include "libmx.h"


void mx_quicksort(char **arr, int left, int right) {
    if(arr != NULL) {
        int i, j, pivot;
        char *temp;

        if(left < right) {
            pivot = left;
            i = left;
            j = right;

            while(i < j) {
                while(mx_strcmp(arr[i],arr[pivot]) < 0 && i < right)
                    i++;
                while(mx_strcmp(arr[j],arr[pivot]) > 0)
                    j--;
                if(i < j) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        mx_quicksort(arr,left,j - 1);
        mx_quicksort(arr,j + 1,right);
        }
   }
}

