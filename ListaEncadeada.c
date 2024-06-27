#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
    char nome_livro[100];
    struct Livro *prox;
};

struct livro *aloca (){ 
    return malloc(sizeof(struct Livro));
};

void addLviro(struct Livro *incio){
    struct Livro *aux, *novo;

    aux = incio;
    while (aux -> prox != NULL)
    {
        aux = aux -> prox;
    }

    novo = aloca();
    if (novo == NULL){
        printf("Erro ao alocar memória");

    }
    printf("Informe o nome do livro: ");
    fgets(novo->nome_livro, sizeof(novo->nome_livro), stdin);
    strtok(novo, "\n");
    novo -> prox = NULL;

    aux -> prox = novo;

};

int main(){
    struct Livro lib;
    lib.prox = NULL;

    addLviro(&lib);
    addLviro(&lib);
    printf("%s\n", lib.prox->nome_livro);
    printf("%s\n", lib.prox->prox->nome_livro);
}