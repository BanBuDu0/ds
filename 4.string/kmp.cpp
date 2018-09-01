#include<iostream>
using namespace std;

typedef struct{
    char ch[50];
    int length;
}Str;

/*
  删除串a中所有的char b, 这是一种把要删除字符后面所有字符串都往前移一位的算法的改进算法
  只需将两个b之间的串往前移就好
*/
void del(Str &a, char b){
    int renum = 0;
    for(int i = 0; i < a.length; ++i){
        if(a.ch[i] == b){
            ++renum;
            for(int j = i + 1; a.ch[j] != b && a.ch[j] != '\0'; ++j){
                a.ch[j - renum] = a.ch[j];
            }
            --a.length;
        }
    }
}

// next数组和KMP算法实现的是从下标0开始存储的串

void getnext(Str a, int next[]){
    next[0] = 0;
    int j = -1;
    int i = 0;
    while(i < a.length){
        if(j == -1 || a.ch[i] == a.ch[j]){
            ++i;
            ++j;
            next[i] = j + 1;        
        }else{
            j = next[j] -1;
        }
    }
}

//改良版的getnext
void getnextval(Str a, int next[]){
    next[0] = 0;
    int j = -1;
    int i = 0;
    while(i < a.length){
        if(j == -1 || a.ch[i] == a.ch[j]){
            ++i;
            ++j;
            if(a.ch[i] != a.ch[j]){
                next[i] = j + 1;
            }else{
                next[i] = next[j];
            }
        }else{
            j = next[j] -1;
        }
    }
}

int KMP(Str str, Str subs, int next[]){
    int i = 0, j = 0;
    while(i < str.length && j < subs.length){
        if(j == -1 || str.ch[i] == subs.ch[j]){
            ++j;
            ++i;
        }else{
            j = next[j] - 1;
        }
    }
    if(j >= subs.length){
        return i - subs.length;
    }else{
        return 0;
    }
}

int main(){
    Str str, subs;
    char b[] = "abababb";
    char a[] = "sfaabababbgdfhthfnm,uy";
    int len = 0;
    for(int i = 0; a[i] != '\0'; ++i){
        str.ch[i] = a[i];
        ++len;
    }
    str.length = len;
    len = 0;
    for(int i = 0; b[i] != '\0'; ++i){
        subs.ch[i] = b[i];
        ++len;
    }
    subs.length = len;
    int next[subs.length];
    getnextval(subs, next);

    int ot = 0;
    ot = KMP(str, subs, next);
    cout << ot;

}