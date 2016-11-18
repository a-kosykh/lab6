#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct List {
    int a;
    List* next;
};

// Функция добавления элемента в начало списка
void addFirst(List *& pF, // Указатель на начало списка
              List* p) // Указатель на добавляемый элемент
{
    p->next = pF;
    pF = p;
}
// Удаление элемента из начала списка
List * delFirst(List *&pF) // Функция возвращает указатель на удаляемый элемент
{
    if (pF == 0) return 0;
    List *p = pF;
    pF = pF->next;
    return p;

}
// Добавление элемента перед заданным
bool add(List *&pF, List * pZad, List *p)
{
    // Функция возвращает true при нормальном завершении и false в случае ошибки
    if (pZad == pF) // Элемент будет первым
    {
        p->next = pF;
        pF = p;
        return true;
    }

    List *pPred = pF; // Указатель на предыдущий элемент перед pZad
    while (pPred->next != pZad && pPred->next)
        pPred = pPred->next;
    if (pPred->next == 0) return false; // Элемента pZad нет в списке
    p->next = pZad;
    pPred->next = p;
    return true;
}
// Удаление любого элемента p из списка
List * del(List*& pF, List *p) // Функция возвращает указатель на удаленный элемент
{
    if (pF == 0) return 0;
    if (pF == p) // Удаляем первый элемент
    {
        pF = pF->next;
        return p;
    }
    else
    {
        List *pPred = pF; // Указатель на предыдущий элемент перед p
        while (pPred->next != p && pPred->next)
            pPred = pPred->next;
        if (pPred->next == 0) return 0; // Элемента p нет в списке
        pPred->next = p->next;
        return p;
    }
    while (delFirst(pF)); // Очистка списка
}

int main()
{
    List *pF = 0; // Список пуст
    List *p;
    // Ввод списка
    int n=0;
    char Ch; // Переменная для ввода условия продолжения ввода
    do
    {
        p = (List *)malloc(sizeof(List)); // Выделяем память под элемент
        cin >> p -> a;
        addFirst (pF,p);
        n++;
        cout << "continiu" << endl;
        cin >> Ch;
    } while (Ch == 'Y' || Ch == 'y');

    return 0;
}
