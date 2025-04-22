#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define _STRING_LENGTH_ 32
#define _SQL_SIZE_ 16

typedef struct SQList {
    int index;
    int length;
    char (*stringGroup)[_SQL_SIZE_]; // 二维字符数组: stringGroup[_SQL_SIZE_][_STRING_LENGTH_]
}SQList;

void PointerCheck ( SQList *ListPointer) {
    if ( ListPointer == NULL ) {
        printf("Cannot find the list !\n");
        exit(-1);
    }
    return;
}

void IndexCheck ( SQList *ListPointer,int index) {
    if ( index > ListPointer->length || index < 0) {
        printf("The value of index is illegal !\n");
        exit(-1);
    }
    return;
}

void InitalSQList ( SQList *ListPointer) {
    ListPointer->stringGroup = (char(*)[_SQL_SIZE_]) malloc( _SQL_SIZE_ * sizeof(char[_STRING_LENGTH_]) );
    // 分配 _SQL_SIZE_ 个 string[_STRING_LENGTH_]字符数组 的内存，并将其转化为 char(*)[_SQL_SIZE_] 
    // 的数据类型，派发内存空间给 stringGroup 指向的地址
    if ( ListPointer == NULL ) {
       printf("Memory allocation failed!\n");
       return;
    }
    ListPointer->index = 0;
    ListPointer->length = _SQL_SIZE_ - 1;
}

void AddElem ( SQList *ListPointer, int index, const char *String) {
    PointerCheck(ListPointer);
    IndexCheck(ListPointer, index);
    if ( strlen(String) > _STRING_LENGTH_ ) {
        printf("The length of string is exceed the limit !\n");
        return;
    }
    for ( int i = 0; i < _STRING_LENGTH_; i++) {
        ListPointer->stringGroup[index][i] = String[i];
    }
    return;
}

void ShowElem ( SQList *ListPointer, int index) {
    PointerCheck(ListPointer);
    IndexCheck(ListPointer, index);
    printf("%s\n",ListPointer->stringGroup[index]);
    return;
}

static public class main (String args[]) {
    printf("Hello world !\n");
}
/*
int main (int a) {
    SQList Table_1, *Table_p;
    Table_p = &Table_1;
    InitalSQList(Table_p);
    AddElem(Table_p, 0, "Kagami");
    AddElem(Table_p, 1, "Sama");
    AddElem(Table_p, 2, "is");
    AddElem(Table_p, 3, "kawai~");
    ShowElem(Table_p, 0);
    ShowElem(Table_p, 1);
    ShowElem(Table_p, 2);
    ShowElem(Table_p, 3);
    return 1;
}
*/