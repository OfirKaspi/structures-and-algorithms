#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display (struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

int BinarySearch(struct Array arr, int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while (l<=h)
    {
        mid=(l+h)/2;
        if (key==arr.A[mid])
        {
            return mid;
        }
        else if (key<arr.A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return -1;
}

int RecursiveBinarySearch(int a[], int l, int h, int key)
{
    int mid;
    
    if (l<=h)
    {
        mid=(l+h)/2;
        if (key==a[mid])
        {
            return mid;
        }
        else if (key<a[mid])
        {
            return RecursiveBinarySearch(a,l,mid-1,key);
        }
        else
        {
            return RecursiveBinarySearch(a,mid+1,h,key);
        }
    }

    return -1;
}

int main ()
{
    struct Array arr={{2,3,4,5,6},10,5};

    printf("%d\n", BinarySearch(arr,4));
    // printf("%d\n", RecursiveBinarySearch(arr.A,0,arr.length,2));
    Display(arr);

    return 0;
}
