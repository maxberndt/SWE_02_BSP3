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


//FIFO Funktionen

//Put
List * put(List *list, int data){
    List *new = (List *) malloc(sizeof(List));
    new->data        = data;
    new->left        = list;
    new->right       = list->right;
    list->right      = new;
    new->right->left = new;
    return new;
}

//Get gibt den aeltesten Wert aus und entfernt ihn
int get(){
    List *head = head;
    List *current = head;
    current = head -> right;
    printf("Get: %d \n", current->data);
    delete(current);
    return current->data;
}

//Top gibt den obersten Wert aus, entfernt ihn jedoch nicht
int last(List* list){
    List *head = list;
    List *current = list;
    current = head -> left;
    printf("Last: %d \n", current->data);
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
        printf("Liste ist nicht leer!\n");
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
    printf("FIFO geleert!\n");
}


//Testprogramm
int main(){

    //Erstellen einer neuen Liste
    struct node *head    = new_list();
    struct node *current = head;
    int i;

    //Befüllen mit 10 Werten
    for(i = 1; i <= 10; i++) {
        current = put(current, i);
    }

    //Testausgabe
    print(head);

    //Test FIFO Funktionen
    get();
    put(current,11);
    print(head);
    last(head);
    //Next versteh ich nicht
    length(head);
    empty();
    deleteall();
    print(head);

    return 0;
}
