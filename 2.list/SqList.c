#include<stdio.h>
#include<stdbool.h>

#define MaxSize 50

typedef struct {
    char data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList *L, int i, char e) {
    // -> equals (*p).
    //the reason * L.data is wrong is . priority is greater than *
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    int j;
    for (j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length ++;
    if (L->length > MaxSize) {
        return false;
    }
    return true;
}

// e was the deleted elem
bool ListDelet(SqList *L, int i, char *e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    * e = L->data[i - 1];
    int j;
    for (j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length --;
    if(L->length < 1) {
        return false;
    }

    return true;
}
int LocatElem(SqList L, char e) {
    int i;
    for(i = 0; i < L.length; i++) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

bool Del_Min(SqList *L, char *value) {
    if(L->length == 0) {
        return false;
    }
    * value = L->data[0];
    int i;
    int index;

    for (i = 1; i < L->length; i++) {
        if(L->data[i] < (* value) ) {
            * value = L->data[i];
            index = i;
        }
    }
    L->data[index] = L->data[L->length - 1];
    L->length--;
    return true;
}
void Reverse(SqList *L) {
    int index = L->length / 2;
    int i, j;
    char temp;
    for(i = 0; i < index; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }
}

void Del_x(SqList *L, char x) {
    int i;
    int k = 0;
    for(i = 0; i < L->length; i++) {
        if(L->data[i] != x) {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}
int main(int argc, char const *argv[]) {
    SqList l;
    SqList *p = &l;
    bool ins = 0;
    char s = 'x';
    char *t = &s;
    int i;
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'g'};
    for(i = 0; i < 8; i++) {
        l.data[i] = a[i];
    }

    l.length = 8;
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    printf("\n");


    ins = ListInsert(p, 1, s);
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    puts("");

    printf("%c\n",*t);
    ins = ListDelet(p, 2, t);
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    puts("");
    printf("the deleted elem = %c \n", *t);


    i = LocatElem(l, 'c');
    printf("the index of c is = %d", i);
    puts("");


    ins = Del_Min(p, t);
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    puts("");
    printf("now I deleted the min elem, it's : %c", s);
    puts("");


    Reverse(p);
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    puts("");

    printf("now I deleted all g \n");
    Del_x(p,'g');
    for(i = 0; i < l.length; i++) {
        printf("%c", l.data[i]);
    }
    puts("");



    return 0;
}
