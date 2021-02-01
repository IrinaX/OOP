#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    struct Item *pPrev;
    struct Item *pNext;
} item;

typedef struct List {
    struct Item *pTail;
    struct Item *pHead;
} list;

void addListItem(item *listItem, list *myList);

void printList(list *myList);

int countListItems(list *myList);

int main() {
    //creating empty list
    item *listItem = NULL;
    listItem = malloc(sizeof(item));
    listItem->pPrev = 0;
    listItem->pNext = 0;
    list *myList = NULL;
    myList = malloc(sizeof(list));
    myList->pHead = 0;
    myList->pTail = 0;
    //добавление элемента в хвост
    addListItem(listItem, myList);
    listItem = malloc(sizeof(item));//создаем элемент(адрес ячейки памяти)
    addListItem(listItem, myList);
    listItem = malloc(sizeof(item));
    addListItem(listItem, myList);
    //вывод списка на экран
    printList(myList);
    //подсчет кол-ва эл-ов в списке
    int amountOfItems = countListItems(myList);
    printf("amountOfItems = %d", amountOfItems);
    return 0;
}

/* голова - <0===> - хвост */
void addListItem(item *listItem, list *myList) {
    if (myList->pHead == NULL) {//если нет элементов в списке
        listItem->pPrev = NULL;//добавленный элемент ни на что не указывает
        listItem->pNext = NULL;
        myList->pHead = listItem;//голова и хвост в списке это добавленный элемент
        myList->pTail = listItem;
    } else {
        myList->pTail->pNext = listItem;//обновляем указатель на след. эл-т у текущего "хвоста"
        listItem->pPrev = myList->pTail; //у нового эл-та определяем указатель на пред. эл-т(т.е. прошлый хвост)
        listItem->pNext = NULL;//следущего эл-та нет, поэтому указатель на след эл-т null
        myList->pTail = listItem; //обновляем хвост списка
    }
}

void printList(list *myList) {
    printf("List: %p\t\tHead: %p\tTail: %p\n", myList, myList->pHead, myList->pTail);
    printf("#\tlistItem\tpPrev\t\tpNext\n");
    int i = 0;
    for (item *element = myList->pHead; element != NULL; element = element->pNext) {
        printf("%d\t%p\t%p\t%p\n", i, element, element->pPrev, element->pNext);
        ++i;
    }
}

int countListItems(list *myList) {
    int i = 0;
    for (item *element = myList->pHead; element != NULL; element = element->pNext) {
        ++i;
    }
    return i;
}

