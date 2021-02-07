//
// Created by IRA on 04.02.2021.
//
#include "subj.h"

Base *createObject(eObjects type) {//создаем элемент с определенным типом
    Base *pCreatedObject = NULL;
    switch (type) {
        case itName: {
            pCreatedObject = malloc(sizeof(Name));
            break;
        }
        case itSurname: {
            pCreatedObject = malloc(sizeof(Surname));
            break;
        }
        case itMiddleName: {
            pCreatedObject = malloc(sizeof(MiddleName));
            break;
        }
        case itEmail: {
            pCreatedObject = malloc(sizeof(Email));
            break;
        }
        case itTelNumber: {
            pCreatedObject = malloc(sizeof(TelNumber));
            break;
        }
        case itDate: {
            pCreatedObject = malloc(sizeof(Date));
            break;
        }
        default: {
            printf("\nUndefined object.\n");
            break;
        }
    }
    if (pCreatedObject) {
        pCreatedObject->pNext = 0;//обнуляем указатели
        pCreatedObject->pPrev = 0;
        pCreatedObject->type = type;//созданному обьекту присваиваем его тип
    }
    return pCreatedObject;
}

void inputData(Base *pCreatedObj) {
    if (pCreatedObj) {
        switch (pCreatedObj->type) {
            case itName: {
                inputName((Name *) pCreatedObj);
                break;
            }
            case itSurname: {
                inputSurname((Surname *) pCreatedObj);
                break;
            }
            case itMiddleName: {
                inputMiddleName((MiddleName *) pCreatedObj);
                break;
            }
            case itEmail: {
                inputEmail((Email *) pCreatedObj);
                break;
            }
            case itTelNumber: {
                inputTelNumber((TelNumber *) pCreatedObj);
                break;
            }
            case itDate: {
                inputDate((Date *) pCreatedObj);
                break;
            }
            default: {
                printf("\nUndefined object.\n");
                break;
            }
        }
    } else {
        printf("\nUndefined pCreatedObj (func: void inputData(Base *pCreatedObj)).\n");
    }
}

void inputBase(Base *pBase) {
    printf("\nEnter personnel number: ");
    scanf("%d", &(pBase->personnelNumber));
}

void inputName(Name *pName) {
    inputBase((Base *) pName);
    printf("\nEnter name (max 15 symbols): ");
    scanf("%s", pName->name);
}

void inputSurname(Surname *pSurname) {
    inputBase((Base *) pSurname);
    printf("\nEnter surname (max 30 symbols): ");
    scanf("%s", pSurname->surname);
}

void inputMiddleName(MiddleName *pMiddleName) {
    inputBase((Base *) pMiddleName);
    printf("\nEnter middle name (max 20 symbols): ");
    scanf("%s", pMiddleName->middleName);
}

void inputEmail(Email *pEmail) {
    inputBase((Base *) pEmail);
    printf("\nEnter email (max 30 symbols): ");
    scanf("%s", pEmail->email);
}

void inputTelNumber(TelNumber *pTelNumber) {
    inputBase((Base *) pTelNumber);
    printf("\nEnter telephone number (max 20 symbols): ");
    scanf("%s", pTelNumber->telNumber);
    printf("\nEnter description (max 100 symbols): ");
    scanf("%s", pTelNumber->description);
}

void inputDate(Date *pDate) {
    inputBase((Base *) pDate);
    printf("\nEnter day: ");
    scanf("%d", &(pDate->day));
    printf("\nEnter month: ");
    scanf("%d", &(pDate->month));
    printf("\nEnter year: ");
    scanf("%d", &(pDate->year));
    printf("\nEnter description (max 100 symbols): ");
    scanf("%s", pDate->description);
}

void printItem(Base *pItem) {
    if (pItem) {
        switch (pItem->type) {
            case itName: {
                printName((Name *) pItem);
                break;
            }
            case itSurname: {
                printSurname((Surname *) pItem);
                break;
            }
            case itMiddleName: {
                printMiddleName((MiddleName *) pItem);
                break;
            }
            case itEmail: {
                printEmail((Email *) pItem);
                break;
            }
            case itTelNumber: {
                printTelNumber((TelNumber *) pItem);
                break;
            }
            case itDate: {
                printDate((Date *) pItem);
                break;
            }
            default: {
                printf("\nUndefined object.\n");
                break;
            }
        }
    } else {
        printf("\nUndefined pItem (func: void printItem(Base *pItem)).\n");
    }
}

void printBase(Base *pBase) {
    printf("Personnel number: %d\n", pBase->personnelNumber);
    printf("Pointer: %p prev: %p next: %p\n", pBase, pBase->pPrev, pBase->pNext);
}

void printName(Name *pName) {
    printf("\nType: Name\n");
    printBase((Base *) pName);
    printf("Name: %s\n", pName->name);
}

void printSurname(Surname *pSurname) {
    printf("\nType: Surname\n");
    printBase((Base *) pSurname);
    printf("Surname: %s\n", pSurname->surname);
}

void printMiddleName(MiddleName *pMiddleName) {
    printf("\nType: MiddleName\n");
    printBase((Base *) pMiddleName);
    printf("Middle name: %s\n", pMiddleName->middleName);
}

void printEmail(Email *pEmail) {
    printf("\nType: Email\n");
    printBase((Base *) pEmail);
    printf("Email: %s\n", pEmail->email);
}

void printTelNumber(TelNumber *pTelNumber) {
    printf("\nType: TelNumber\n");
    printBase((Base *) pTelNumber);
    printf("Telephone number: %s\n", pTelNumber->telNumber);
    printf("Description: %s\n", pTelNumber->description);
}

void printDate(Date *pDate) {
    printf("\nType: Date\n");
    printBase((Base *) pDate);
    printf("Day: %d\n", pDate->day);
    printf("Month: %d\n", pDate->month);
    printf("Year: %d\n", pDate->year);
    printf("Description: %s\n", pDate->description);
}

void printNewList(list *pList) {
    int i = 0;
    if (pList) {
        if (pList->pHead) {
            for (item *pItem = pList->pHead; pItem != NULL; pItem = pItem->pNext) {
                printf("\nIndex: %d", i);
                printItem((Base *) pItem);
                ++i;
            }
        } else {
            printf("\nList is empty.\n");
        }
    } else {
        printf("\nUndefined pointer pList. Func: void printNewList(list *pList)\n");
    }
}

void sortBySurname(list *pList) {
    int amountOfItems = countListItems(pList);

    if (amountOfItems == 0 || amountOfItems == 1)
        return;

    for (int j = 0; j < amountOfItems; ++j) {//все фамилии вставляем в начало списка
        if (((Base *) getItem(pList, j))->type == itSurname) {
            item *removedItem = removeItem(pList, j);
            insertItem(pList, removedItem, 0);
        }
    }

    for (int i = amountOfItems - 1; i > 0; --i) {//сортируем фамилии
        for (int j = 0; j < i; ++j) {
            if (((Base *) getItem(pList, j + 1))->type == itSurname) {
                if (strcmp(((Surname *) getItem(pList, j))->surname,
                           ((Surname *) getItem(pList, j + 1))->surname) > 0) {
                    swipeItems(pList, j);
                }
            }
        }
    }
// вставляем между фамилиями остальные данные с соответствующим табельным номером
    int savedPersonnelNumber;
    int savedIndex;
    for (int i = 0; i < amountOfItems - 1; ++i) {
        if (((Base *) getItem(pList, i))->type == itSurname) {
            savedPersonnelNumber = ((Base *) getItem(pList, i))->personnelNumber;
            savedIndex = i;
            for (int j = ++savedIndex; j < amountOfItems; ++j) {
                if (((Base *) getItem(pList, j))->type != itSurname) {
                    if (((Base *) getItem(pList, j))->personnelNumber == savedPersonnelNumber) {
                        item *removedItem = removeItem(pList, j);
                        insertItem(pList, removedItem, savedIndex);
                    }
                }
            }
        }
    }
}

void swipeItems(list *pList, int index) {//меняем местами элементы
    item *currItem = getItem(pList, index);
    item *prevItem = currItem->pPrev;
    item *nextItem = currItem->pNext;

    if (currItem == pList->pHead) {
        pList->pHead = nextItem;
    }
    if (nextItem == pList->pTail) {
        pList->pTail = currItem;
    }

    if (prevItem != NULL) {
        prevItem->pNext = nextItem;
    }

    if (nextItem->pNext != NULL) {
        nextItem->pNext->pPrev = currItem;
    }

    currItem->pNext = nextItem->pNext;
    currItem->pPrev = nextItem;
    nextItem->pNext = currItem;
    nextItem->pPrev = prevItem;
}

void searchKeyWordInTelNumberDescription(list *pList) {

}
