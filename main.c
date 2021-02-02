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

void printMenu();

item *getItem(list *myList, int index);

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
    while (variant <= 3) {
        printMenu();
        scanf("%d", &variant);
        switch (variant) {
            case 0: { //добавление элемента в хвост

                listItem = malloc(sizeof(item));

                addListItem(listItem, myList);
                printf("\nItem was added successfully!\n");
                break;
            }
            case 1: {//вывод списка на экран
                printList(myList);
                break;
            }
            case 2: {//подсчет кол-ва эл-ов в списке
                int amountOfItems = countListItems(myList);
                printf("\namountOfItems = %d\n", amountOfItems);
                break;
            }
            case 3: {//получение элемента по индексу
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
            case 4: {//выход из программы
                printf("Exit...");
                if (myList != NULL) {
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
    printf("3. Get item by index\n");
    printf("4. Exit\n");
//    printf("4. Show notebook\n");
//    printf("5. Show person info by his number in notebook\n");
//    printf("6. Add person\n");
//    printf("7. Remove person\n");
//    printf("8. Save notebook\n");
//    printf("9. Load notebook from file\n");
//    printf("10. Delete file\n");
//    printf("11. Clear all data\n");
//    printf("12. Exit\n");
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

