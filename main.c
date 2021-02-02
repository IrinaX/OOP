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

//todo: getIndex
void addListItem(list *myList, item *listItem);

void printList(list *myList);

int countListItems(list *myList);

void printMenu();

item *getItem(list *myList, int index);

item *removeItem(list *myList, int index);

void deleteItem(list *myList, int index);

void clearList(list *myList);

void insertItem(list *myList, item *newItem, int index);

int getIndex(list *myList, item *listItem);

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
    int variant = 0;
    while (variant <= 8) {
        printMenu();
        scanf("%d", &variant);
        switch (variant) {
            case 0: { //Add item to tail
                listItem = malloc(sizeof(item));
                addListItem(myList, listItem);
                printf("\nItem was added successfully!\n");
                break;
            }
            case 1: {//Show list
                printList(myList);
                break;
            }
            case 2: {//Count items
                int amountOfItems = countListItems(myList);
                printf("\namountOfItems = %d\n", amountOfItems);
                break;
            }
            case 3: {//Insert item
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    item *newItem = malloc(sizeof(item));
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    insertItem(myList, newItem, index);
                    printf("\nNew item was inserted successfully!\n");
                }
                break;
            }
            case 4: {//Get item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    item *element = getItem(myList, index);
                    if (element != 0) {
                        printf("#\tlistItem\tpPrev\t\tpNext\n");
                        printf("%d\t%p\t%p\t%p\n", index, element, element->pPrev, element->pNext);
                    }
                }
                break;
            }
            case 5: {//Get index of item
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    printf("\nEnter item address: ");
                    scanf("%p", &listItem);
                    int index = getIndex(myList, listItem);
                    if (index > -1) {
                        printf("\nindex = %d\n", index);
                    } else {
                        printf("\nElement doesn't exist.\n");
                    }
                }
                break;
            }
            case 6: {//Remove item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    item *removedElement = removeItem(myList, index);
                    if (removedElement != 0) {
                        printf("\n#\tremovedItem\tpPrev\t\tpNext\n");
                        printf("%d\t%p\t%p\t%p\n", index, removedElement, removedElement->pPrev, removedElement->pNext);
                    }
                }
                break;
            }
            case 7: {//Delete item by index
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    deleteItem(myList, index);
                }
                break;
            }
            case 8: {//Clear list
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    clearList(myList);
                }
                break;
            }
            case 9: {//Exit
                printf("Exit...");
                if (myList != NULL) {
                    clearList(myList);
                    free(myList);
                    myList = NULL;
                }
                if (listItem != NULL) {
                    free(listItem);
                    listItem = NULL;
                }
                break;
            }
            default:
                break;
        }
    }

    return 0;
}

/* голова - <0===> - хвост */
void addListItem(list *myList, item *listItem) {
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
    printf("\nList: %p\t\tHead: %p\tTail: %p\n", myList, myList->pHead, myList->pTail);
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

void printMenu() {
    printf("\nWhat do you want to do?\n");
    printf("0. Add item to tail\n");
    printf("1. Show list\n");
    printf("2. Count items\n");
    printf("3. Insert item\n");
    printf("4. Get item by index\n");
    printf("5. Get index of item\n");
    printf("6. Remove item by index\n");
    printf("7. Delete item by index\n");
    printf("8. Clear list\n");
    printf("9. Exit\n");
    printf(">");
}

item *getItem(list *myList, int index) {
    if (myList->pHead == NULL) {//если начальный эл-т в списке отсутствует, возвращяем 0
        printf("\nList is empty.\n");
        return 0;
    }
    item *element = myList->pHead;//присваиваем начальный элемент списка
    for (int i = 0; i < index; ++i) {
        if (element->pNext == NULL) {//если указатель на след. эл-т отсутствует, значит текущий эл-т последний
            printf("\nElement doesn't exist.\n");
            return 0;
        } else {
            element = element->pNext;
        }
    }
    return element;
}

void insertItem(list *myList, item *newItem, int index) {
    item *element = getItem(myList, index);
    if (element != 0) {
        if (element == myList->pHead) { //если выбран 0-ой эл-т
            newItem->pPrev = NULL;//у нового элемента обнуляем указатель на предыдущий элемент
            newItem->pNext = element;// у newItem присваиваем указателю на след элемент адрес головы
            element->pPrev = newItem;// у головы обновляем указатель на пред эл-т
            myList->pHead = newItem;//обновляем указатель на голову)))
            return;
        }
        if (element == myList->pTail) { //если выбран ласт эл-т
            newItem->pNext = NULL;//у нового элемента обнуляем указатель на след элемент
            newItem->pPrev = element;// у newItem присваиваем указателю на пред элемент адрес хвоста
            element->pNext = newItem;// у хвоста обновляем указатель на след эл-т
            myList->pTail = newItem;//обновляем указатель на хвост
        } else {
            element->pPrev->pNext = newItem;// у элемента index-1 присваиваем указателю на след элемент адрес newItem
            newItem->pPrev = element->pPrev;// у newItem присваиваем указателю на пред элемент адрес элемента index-1
            newItem->pNext = element; // у newItem присваиваем указателю на след элемент адрес элемента index
            element->pPrev = newItem; // у элемента index присваиваем указателю на пред элемент адрес элемента newItem
        }
    }
}

item *removeItem(list *myList, int index) {
    item *element = getItem(myList, index);
    if (element == 0) {
        return 0;
    }
    if (myList->pTail == myList->pHead) {//если в списке остался один элемент
        myList->pTail = NULL;//хвост обнуляем
        myList->pHead = NULL;//голову тоже
//        printf("\nList is empty.\n");
        return element;
    }
    if (element->pPrev == NULL) {//если удалить надо начальный элемент(голову) (индекс 0)
        element->pNext->pPrev = NULL;//обнуляем указатель на голову
        myList->pHead = element->pNext;//новая голова это эл-т с индексом 1
    } else {
        if (element->pNext == NULL) {//если удалить надо конечный элемент(хвост) (индекс n)
            element->pPrev->pNext = NULL;//обнуляем указатель на хвост
            myList->pTail = element->pPrev;//новый хвост это эл-т с индексом n-1
        } else {//если элемент находится посередине
            element->pPrev->pNext = element->pNext;//обновляем указатель на след элемент у пред элемента
            element->pNext->pPrev = element->pPrev;//обновляем указатель на пред элемент у след элемента
        }
    }
    return element;
}

void deleteItem(list *myList, int index) {
    item *removedItem = removeItem(myList, index);
    if (removedItem == 0) {
        free(removedItem);
        removedItem = NULL;
        return;
    }
    free(removedItem);
    removedItem = NULL;
    printf("\nItem was successfully deleted!\n");
}

void clearList(list *myList) {
    item *element = myList->pHead;//определяем начальный элемент списка для цикла
    while (element != NULL) {
        item *nextItem = element->pNext;//сохраняем указатель на следующий элемент
        free(element);//освобождаем память
        element = nextItem;//присваиваем текущему указателю сохраненный
    }
    myList->pHead = NULL;
    myList->pTail = NULL;
    printf("\nList was cleared successfully!\n");
}

int getIndex(list *myList, item *listItem) {
    int index = 0;
    int boolVar = 0;
    for (item *element = myList->pHead; element != NULL; element = element->pNext) {
        if (listItem == element) {//если указатель текущего элемента равен необходимому
            boolVar = 1;
            break;
        }
        ++index;
    }
    if (boolVar == 1) {//если адрес найден
        return index;
    } else {
        return -1;//если адрес был не найден
    }

}


