#include <stdio.h>
#include <stdlib.h>

#define NMAX 100005
int N, L, R;

int a[NMAX];
int b[NMAX];

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

static int cmp(const void* p1, const void* p2)
{
    return(*((int*) p1) > *((int*) p2) ? 1 : -1);
}

int is_equal(int* a, int* b, int N)
{
    int i;
    for(i = 0; i < N; i++)
        if(a[i] != b[i])
           return(0);
    return(1);
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &L);
    scanf("%d", &R);

    L--; R--;

    int i;
    for(i = 0; i < N; i++)
        scanf("%d", &(a[i]));
    for(i = 0; i < N; i++)
        scanf("%d", &(b[i]));

    mergeSort(a, L, R);
    mergeSort(b, L, R);
//    qsort(a + L, R - L + 1, sizeof(int), cmp);
//    qsort(b + L, R - L + 1, sizeof(int), cmp);

    int res = is_equal(a, b, N);
    printf("%s\n", res ? "TRUTH" : "LIE");
}
