//
// Created by IRA on 04.02.2021.
//

#ifndef INC_1_SUBJ_H
#define INC_1_SUBJ_H

#include "list.h"

typedef struct {//стуктура базового уровня
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;//табельный номер
} Base;

typedef struct {//фамилия
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    char surname[30];
} Surname;

typedef struct {//имя
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    char name[15];
} Name;

typedef struct {//отчество
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    char middleName[20];
} MiddleName;

typedef struct {//отчество
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    char email[30];
} Email;

typedef struct {//тел номер
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    char telNumber[20];
    char description[100];
} TelNumber;

typedef struct {//дата с доп информацией
    struct Item *pPrev;//наследование
    struct Item *pNext;
    eObjects type;//тип данных (фамилия, имя и тд)
    int personnelNumber;

    int day;
    int month;
    int year;
    char description[100];
} Date;

Base *createObject(eObjects type);

void inputData(Base *pCreatedObj);

void inputBase(Base *pBase);

void inputName(Name *pName);

void inputSurname(Surname *pSurname);

void inputMiddleName(MiddleName *pMiddleName);

void inputEmail(Email *pEmail);

void inputTelNumber(TelNumber *pTelNumber);

void inputDate(Date *pDate);


void printBase(Base *pBase);

void printItem(Base *pItem);

void printName(Name *pName);

void printSurname(Surname *pSurname);

void printMiddleName(MiddleName *pMiddleName);

void printEmail(Email *pEmail);

void printTelNumber(TelNumber *pTelNumber);

void printDate(Date *pDate);

void printNewList(list *pList);




#endif //INC_1_SUBJ_H
