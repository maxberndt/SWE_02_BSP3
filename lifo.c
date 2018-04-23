//
// Created by Max Berndt on 20.04.2018.
//

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

//Listenfunktionen
//Neue Liste anlegen
List * new_list(){
    List *new = (List*) malloc(sizeof(List));
    new->data  = -1; //Head hat Wert -1
    new->right = new;
    new->left  = new;
    return new; //Gib Pointer auf Liste zurueck
}

//Neuen Wert eintragen
List * push(List *list, int data){
    List *new = (List *) malloc(sizeof(List));
    new->data        = data;
    new->left        = list;
    new->right       = list->right;
    list->right      = new;
    new->right->left = new;
    return new;
}

//Listenelement loeschen
List * delete(List *list){
    list->right->left = list->left;
    list->left->right = list->right;
    return list->left;
}


void print(List* list){
    List *head = list;
    List *current = list;
    printf("%d ", head->data);
    while (head != (current = current->right)){
        printf("%d ", current->data);
    }
    printf("\n");
}


//LIFO Funktionen

//Push existiert schon

//Pop gibt den obersten Wert aus und entfernt ihn
int pop(List* list){
    List *head = list;
    List *current = list;
    current = head -> left;
    printf("Pop: %d \n", current->data); //Ausgabe ausserhalb der Funktion gab leider Probleme
    delete(current);
    return current->data;
}

//Top gibt den obersten Wert aus, entfernt ihn jedoch nicht
int top(List* list){
    List *head = list;
    List *current = list;
    current = head -> left;
    printf("Top: %d \n", current->data); //Ausgabe ausserhalb der Funktion gab leider Probleme
    return current->data;
}

int length(List* list){
    int i = 0;
    List *head = list;
    List *current = list;
    while (head != (current = current->right)){
        current->data;
        i++;
    }
    printf("Laenge: %i\n",i);

    return i;
}

int empty(){
    int i = 0;
    List *head = head;
    List *current = head;
    while (head != (current = current->right)){
        current->data;
        i++;
    }

    if (i==0){
        printf("Liste ist leer!\n");
        return 0;
    }else {
        printf("LIFO ist nicht leer!\n");
        return 1;
    };
}

void deleteall(){
    List *head = head;
    List *current = head;
    while (head != (current = current->right)){
        current->data;
        delete(current);
    }
    printf("Liste geleert!\n");
}


//Testprogramm
int main(){

    //Erstellen einer neuen Liste
    struct node *head    = new_list();
    struct node *current = head;
    int i;

    //Befüllen mit 10 Zahlen
    for(i = 1; i <= 10; i++) {
        current = push(current, i);
    }


    //Test LIFO Funktionen
    push(head,5);
    pop(head);
    top(head);
    print(head);
    top(head);

    length(head);
    empty();
    deleteall();
    print(head);

    return 0;
}
