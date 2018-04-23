/* -- SLIST Knoten */
struct SList {
    int Data;
    struct SList *Next;
    struct SList *Prev;
};
typedef struct SList SLIST;

/* -- Ein Kopf-Knoten, der die Listenlaenge enthaelt */
struct SList_Header {
    int Len;
    SLIST *First, *Last;
};
typedef struct SList_Header SLIST_HEADER;

extern SLIST_HEADER *CreateSlist(void);
extern SLIST *InsertFirst(SLIST_HEADER*,int);
