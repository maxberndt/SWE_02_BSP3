//
// Created by Max Berndt on 22.04.2018.
//

#ifndef LISTESELBST_HEADER_H
#define LISTESELBST_HEADER_H


//Struktur Listenelement
struct node {
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node List;


#endif //LISTESELBST_HEADER_H
