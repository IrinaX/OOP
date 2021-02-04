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
