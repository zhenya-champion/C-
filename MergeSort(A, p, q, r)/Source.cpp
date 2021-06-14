//MergeSort(A, p, q, r)

#include <iostream>

using namespace std;

void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    int* L = new int[n1];
    int* M = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];{
        if (L[i] <= M[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = M[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        A[k] = M[j];
        j++;
        k++;
    }
}