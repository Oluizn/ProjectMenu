#ifndef PROJECTMENU_LIBMENU_H
#define PROJECTMENU_LIBMENU_H
#define SIZE 100
#define FILE_NAME "contatos.ccf"
#include "stdio.h"

struct contact_t {
    char name[61];
    char phone [20];
    char email[251];
};

typedef struct contact_t contact;

void menu_edicao_exclusao();
void deletar_contato(int s);
void editar_contato();
void carregar_arquivo();
void mostrar_contatos(int i);
void salvar_contato(contact ctt, FILE *file);
int inserir_contato(contact ctt);
int buscar_nome(char *nome_fornecido, char *nome_na_lista, int indexador_inicio, int indexador_limitante);
void menu();
void criar_contato();
void contatos_disponiveis();
void buscar_contato();

#endif //PROJECTMENU_LIBMENU_H
