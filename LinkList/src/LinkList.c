#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _LIST_SIZE_ 64

typedef struct ListNode{
    int elem;
    struct ListNode *next;
}ListNode;

void PointerCheck ( ListNode *ListPointer) {
    if ( ListPointer == NULL ) {
        printf("Cannot find the list !\n");
        exit(-1);
    }
    return;
}
/*
void IndexCheck ( ListNode *ListPointer,int index) {
    if ( index > ListPointer || index < 0) {
        printf("The value of index is illegal !\n");
        exit(-1);
    }
    return;
}
*/
ListNode* InitialHeadNode() {
    ListNode *HeadNode, *HeadPointer; // 创建头节点和头指针
    HeadNode = (ListNode*)malloc( sizeof( ListNode ) ); // 给头节点分配内存
    HeadNode->elem = 0;
    HeadNode->next = NULL;
    HeadPointer = HeadNode; // 头指针指向头节点
    return HeadPointer;
}

void InitialListNode ( ListNode *HeadNode, int NumOfNodes, int *Elems) {
    PointerCheck( HeadNode );
    ListNode *temp = HeadNode;
    for ( int i = 0; i < NumOfNodes; i++) {
        ListNode *NewNode = (ListNode*)malloc( sizeof(ListNode) ); // 创建新节点并分配内存
        temp->next = NewNode; // 编辑上一节点的指向
        NewNode->next = NULL;
        NewNode->elem = Elems[i];
        temp = NewNode; // 将临时指针指向本次创建的新节点，以进入下一次循环
    }
    return;
}

void ShowElems ( ListNode *HeadPointer) {
    PointerCheck(HeadPointer);
    ListNode *temp = HeadPointer->next; // 指向首元节点的指针
    while ( temp != NULL ) { // 遍历链表
        printf("%d ", temp->elem);
        temp = temp->next;
    };
    printf("\n");
    return;
}

void InserElem ( ListNode *HeadPointer, int InserPosition, int elem) {
    PointerCheck(HeadPointer);
    if (InserPosition < 0) { // 检查插入位置是否合法
        printf("Invalid position!\n");
        return;
    }
    ListNode *temp = HeadPointer; // 创建临时节点指针指向头节点

    for (int i =0; i < InserPosition; i++) { // 找到插入位置
        if (temp == NULL) { // 插入位置不存在
            printf("The position is not exist !\n");
            return;
        }
        temp = temp->next;
    }
    ListNode *NewNode = (ListNode*)malloc(sizeof(ListNode));
    NewNode->elem = elem;
    NewNode->next = temp->next;
    temp->next = NewNode;
    return;
}

void DeleteNode( ListNode *HeadPointer, int Value_Position, char mode) { 
    // mode: V->Delete the node with the value
    // mode: P->Delete the node in that position
    PointerCheck(HeadPointer);
    ListNode *temp = HeadPointer; // 创建临时节点指针指向头节点
    switch (mode){
    case 'V':
        while( temp->next != NULL) {
            if ( temp->next->elem == Value_Position) { // 找到节点了
                ListNode *toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
                return;
            } else {                             // 没找到,接着找 
                temp = temp->next;
            }
        }
        printf("Cannot find the node to delete !\n"); // 从头到尾找了一遍，没找到
        return;
        break;
    case 'P':
        if( Value_Position < 1) {
            printf("The Value_Position is incorrect !\n");
            return;
        }
        for (int i = 0; i < Value_Position-1; i++) {
            if (temp->next == NULL) { // 防止越界
                printf("Cannot find the node to delete !\n");
                break;
            }
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Cannot find the node to delete !\n");
            return;
        }else {                                 // 删尾巴 删中间
            ListNode *toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            return;
        }
        break;

    default :
        printf("Invalid mode!\n");
        return;
    }

}

void SearchForBeast(ListNode *HeadPointer) {
    int count = 0;
    ListNode *temp = HeadPointer->next;
    while (temp != NULL) {
        if (temp->elem == 1) count++;
        else if (count == 5 && temp->elem == 4) {
            printf("114514 get!\n");
        } else {
            count = 0;
        }
        temp = temp->next;
    }
}

int main () {
    int Elems[6] = {1, 1, 4, 5, 1, 4};
    ListNode *p_1 = InitialHeadNode();
    InitialListNode( p_1, 6, Elems);
    ShowElems(p_1);
    InserElem(p_1, 1, 9);
    InserElem(p_1, 2, 1);
    InserElem(p_1, 3, 9);
    InserElem(p_1, 4, 8);
    InserElem(p_1, 5, 1);
    InserElem(p_1, 6, 0);
    ShowElems(p_1);
    DeleteNode(p_1, 4, 'V');
    DeleteNode(p_1, 4, 'V');
    DeleteNode(p_1, 5, 'V');
    DeleteNode(p_1, 8, 'P');
    DeleteNode(p_1, 8, 'P');
    ShowElems(p_1);
    return 0;
}