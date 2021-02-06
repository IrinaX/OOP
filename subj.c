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
        default:
            break;
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
                break;
            }
            case itSurname: {
                break;
            }
            case itMiddleName: {
                break;
            }
            case itEmail: {
                break;
            }
            case itTelNumber: {
                break;
            }
            case itDate: {
                break;
            }
            default: {
                printf("\nUndefined object.\n");
                break;
            }
        }
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


