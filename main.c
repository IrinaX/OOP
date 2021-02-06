#include "list.h"
#include "subj.h"

int main() {
    list *myList = createList(); //creating empty list
    Base *listItem; //указатель на объект класса Base
    int variant = 0;
    while (variant != 12) {
        printMenu();
        scanf("%d", &variant);
        switch (variant) {
            case 0: { //Add item to tail
                listItem = createObject(itName);//создаем обьект типа itName
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nName was added successfully!\n");
                break;
            }
            case 1: { //Add item to tail
                listItem = createObject(itSurname);//создаем обьект типа itSurname
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nSurname was added successfully!\n");
                break;
            }
            case 2: { //Add item to tail
                listItem = createObject(itMiddleName);//создаем обьект типа itMiddleName
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nMiddleName was added successfully!\n");
                break;
            }
            case 3: { //Add item to tail
                listItem = createObject(itEmail);//создаем обьект типа itEmail
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nEmail was added successfully!\n");
                break;
            }
            case 4: { //Add item to tail
                listItem = createObject(itTelNumber);//создаем обьект типа itTelNumber
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nTelNumber was added successfully!\n");
                break;
            }
            case 5: { //Add item to tail
                listItem = createObject(itDate);//создаем обьект типа itDate
                inputData(listItem);//ввод данных с клавиатуры
                addListItem(myList, (item *)listItem);//добавляем в список
                printf("\nDate was added successfully!\n");
                break;
            }
            case 6: {//Show list
                printNewList(myList);
                break;
            }
            case 7: {//Count items
                int amountOfItems = countListItems(myList);
                printf("\namountOfItems = %d\n", amountOfItems);
                break;
            }
            case 8: {//Get item by index
                if (myList->pHead) {//если начальный эл-т отсутствует, то список пуст
                    int index = 0;
                    printf("\nEnter index of element: ");
                    scanf("%d", &index);
                    item *element = getItem(myList, index);
                    if (element != 0) {
                        printf("#\tlistItem\tpPrev\t\tpNext\n");
                        printf("%d\t%p\t%p\t%p\n", index, element, element->pPrev, element->pNext);
                    }
                } else {
                    printf("\nList is empty.\n");
                }
                break;
            }
            case 9: {//Remove item by index
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
            case 10: {//Delete item by index
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
            case 11: {//Clear list
                if (myList->pHead == NULL) {//если начальный эл-т отсутствует, то список пуст
                    printf("\nList is empty.\n");
                } else {
                    clearList(myList);
                }
                break;
            }
            case 12: {//Exit
                printf("Exit...");
                return 0;
            }
            default:
                printf("Variant not found.");
                break;
        }
    }
    return 0;
}




