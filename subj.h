//
// Created by IRA on 04.02.2021.
//

#ifndef INC_1_SUBJ_H
#define INC_1_SUBJ_H

#include "declaration.h"

typedef struct {//стуктура базового уровня
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;//табельный номер
} Base;

typedef struct {//фамилия
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;

    char surname[30];
} Surname;

typedef struct {//имя
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;

    char name[15];
} Name;

typedef struct {//отчество
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;

    char middleName[20];
} MiddleName;

typedef struct {//тел номер
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;

    char telNumber[20];
    char description[100];
} TelNumber;

typedef struct {//дата с доп информацией
    struct Item *pPrev;//наследование
    struct Item *pNext;

    int personnelNumber;

    int day;
    int month;
    int year;
    char description[100];
} Date;
#endif //INC_1_SUBJ_H
