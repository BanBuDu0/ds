#include<iostream>
using namespace std;


//O(n²)
void InsertSort(int a[], int n){
    int temp;
    for(int i = 1; i < n; ++i){

        temp = a[i];
       /* for(int j = i - 1; j >= 0; --j){
            if(a[j] > temp){
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }*/
        //reduce assignment temp to a[j]
        int j = i - 1;
        while(j >= 0 && temp < a[j]){
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;
    }
}


//O(nlogn)
void QuickSort(int a[], int low, int high){
    int temp;
    int i = low, j = high;
    if(low < high){
        temp = a[low];
        while(i < j){
            while(j > i && a[j] >= temp){
                --j;
            }
            if(i < j){
                a[i] = a[j];
                ++i;
            }
            while(i < j && a[i] < temp){
                ++i;
            }
            if(i < j){
                a[j] = a[i];
                --j;
            }
        }
        a[i] = temp;
        QuickSort(a, low, i - 1);
        QuickSort(a, i + 1, high);
    }

}
int main(){
    int a[] = {12, 4, 43, 5435,22, 1, 23, 43};
    QuickSort(a, 0, 7);
    for(int i = 0; i < 8; ++i){
        cout << a[i] << " ";
    }

}
