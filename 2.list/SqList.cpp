#include<stdio.h>
#include<stdbool.h>
#include<iostream>
using namespace std;

#define MaxSize 50

typedef struct {
    char data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, char e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    int j;
    for (j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length ++;
    if (L.length > MaxSize) {
        return false;
    }
    return true;
}

bool ListDelet(SqList &L, int i, char &e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    e = L.data[i - 1];
    int j;
    for (j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length --;
    if(L.length < 1) {
        return false;
    }
    return true;
}
int LocatElem(SqList &L, char e) {
    int i;
    for(i = 0; i < L.length; i++) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

bool Del_Min(SqList &L, char &value) {
    if(L.length == 0) {
        return false;
    }
    value = L.data[0];
    int i;
    int index;
    for (i = 1; i < L.length; i++) {
        if(L.data[i] < value) {
            value = L.data[i];
            index = i;
        }
    }
    L.data[index] = L.data[L.length - 1];
    L.length --;
    return true;
}
void Reverse(SqList &L) {
    int index = L.length / 2;
    int i, j;
    char temp;
    for(i = 0; i < index; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

void Del_x(SqList &L, char x) {
    int i;
    int k = 0;
    for(i = 0; i < L.length; i++) {
        if(L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
int main(int argc, char const *argv[]) {
    SqList l;
    bool ins = 0;
    char s = 'x';
    int i;
    char a[8] = {'a', 'b', 'c', 'd', 'f', 'g', 'g', 'e'};
    for(i = 0; i < 8; i++) {
        l.data[i] = a[i];
    }
    l.length = 8;
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    printf("\n");


    //insert elem to the list
    ins = ListInsert(l, 1, s);
    if(ins) {
        for(i = 0; i < l.length; i++) {
            printf("%c", l.data[i]);
        }
    }
    printf("\n");


    //delect the index 5 elem and return it by reference
    ins = ListDelet(l, 5, s);
    if(ins) {
        for(i = 0; i < l.length; i++) {
            printf("%c", l.data[i]);
        }
    }
    printf("\n");
    cout << s << endl;


    //get the index of char 'c'
    i = LocatElem(l, 'c');
    cout << i << endl;


    //delect min elem
    ins = Del_Min(l, s);
    cout << s << endl;
    if(ins) {
        for(i = 0; i < l.length; i++) {
            printf("%c", l.data[i]);
        }
    }
    printf("\n");


    //resverse the list
    Reverse(l);
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    printf("\n");


    //delect all char 'g'
    Del_x(l,'g');
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    printf("\n");
    return 0;
}
