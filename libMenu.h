#ifndef PROJECTMENU_LIBMENU_H
#define PROJECTMENU_LIBMENU_H
#define SIZE 100
#define FILE_NAME "contatos.ccf"
#include "stdio.h"

struct contact_t {
    char name[60];
    char phone [20];
    char email[251];
};

typedef struct contact_t contact;

void load_contact();
void show_contact(int i);
void contactSave(contact ctt, FILE *file);
int insert_contact(contact ctt);
void menu();
void createContact();
void availableContacts();
void searchContact();

#endif //PROJECTMENU_LIBMENU_H
