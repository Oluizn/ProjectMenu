#include "libMenu.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int counter = 0;
contact contacts[SIZE];

void contactSave(contact ctt, FILE *file){
    fputs(ctt.name, file);
    fputs(ctt.phone, file);
    fputs(ctt.email, file);
}

int insert_contact(contact ctt){
    int r = 0;
    FILE *file = fopen(FILE_NAME, "a+");

    if(file != NULL) {
        r = 1;
        contactSave(ctt, file);
        contacts[counter] = ctt;
        counter++;
    }
    fclose(file);
    return r;
}

void menu(){
    int op = 0;

    while (op != 9){
        printf("Choose one option:\n");
        printf("1 - New contact:\n");
        printf("2 - Contact list:\n");
        printf("3 - search contact:\n");
        printf("9 - exit.\n");

        scanf("%d", &op);
        fflush(stdin);

        if(op != 9){
            switch (op) {
                case 1: createContact();
                    break;
                case 2: availableContacts();
                    break;
                case 3: searchContact();
                    break;
                default:
                    printf("Invalid option, choose between 1 and 3, or 9 to exit out");
            }
        }
        else
            printf("Bye.\n");
    }
}

void show_contact(int i){
    printf("Name: %s", contacts[i].name);
    printf("Phone: %s", contacts[i].phone);
    printf("Email: %s", contacts[i].email);
}

void load_contact(){
    FILE *file = fopen(FILE_NAME, "r");
    if(file != NULL){
        counter = 0;
        while (!feof(file)){
            fgets(contacts[counter].name, 60, file);
            if(strcmp(contacts[counter].name, "") > 0) {
                fgets(contacts[counter].phone, 20, file);
                fgets(contacts[counter].email, 250, file);
                counter++;
            }
        }
    }
    else
        printf("Failed load file.");
    fclose(file);
}

void createContact(){
    printf("New contact.\n");

    contact ctt;
    printf("Name: ");
    fgets(ctt.name, 60, stdin);
    fflush(stdin);
    printf("Phone: ");
    fgets(ctt.phone, 20, stdin);
    fflush(stdin);
    printf("Email: ");
    fgets(ctt.email, 250, stdin);
    fflush(stdin);

    if (insert_contact(ctt) == 1)
        printf("Contact saved!\n");
    else
        printf("FAILED saving contact.\n");
}

void availableContacts(){
    printf("Contact list.\n");

    for (int i = 0; i < counter; ++i) {
        show_contact(i);
        printf("\n");
    }
}

void searchContact(){
    printf("Contact.\n");
}