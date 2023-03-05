#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PESSOAS 100

struct Pessoa {
    int id;
    char nome[50];
    char apelido[50];
    char data_nascimento[11];
};

struct Pessoa lista_pessoas[MAX_PESSOAS];
int n_pessoas = 0;

//-----------------------------------------FUNÇÃO ADICIONAR PESSOA----------------------------------------

void adicionar_pessoa() {
    if (n_pessoas >= MAX_PESSOAS) {
        printf("Lista de pessoas está cheia.\n");
        return;
    }
    
    struct Pessoa nova_pessoa;
    printf("ID: ");
    scanf("%d", &nova_pessoa.id);
    printf("Nome: ");
    scanf("%s", nova_pessoa.nome);
    printf("Apelido: ");
    scanf("%s", nova_pessoa.apelido);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", nova_pessoa.data_nascimento);
    
    lista_pessoas[n_pessoas] = nova_pessoa;
    n_pessoas++;
    
    printf("Pessoa adicionada com sucesso.\n");
}


//-----------------------------------------FUNÇÃO ELIMINAR PESSOA----------------------------------------

void eliminar_pessoa() {
    int id_pessoa;
    printf("Digite o ID da pessoa a ser eliminada: ");
    scanf("%d", &id_pessoa);
    
    int i;
    for (i = 0; i < n_pessoas; i++) {
        if (lista_pessoas[i].id == id_pessoa) {
            int j;
            for (j = i; j < n_pessoas-1; j++) {
                lista_pessoas[j] = lista_pessoas[j+1];
            }
            n_pessoas--;
            printf("Pessoa eliminada com sucesso.\n");
            return;
        }
    }
    
    printf("Pessoa com o ID %d não foi encontrada.\n", id_pessoa);
}

void imprimir_pessoa(struct Pessoa pessoa) {
    printf("ID: %d, Nome: %s %s, Data de Nascimento: %s\n", pessoa.id, pessoa.nome, pessoa.apelido, pessoa.data_nascimento);
}


//-------------------------------------------------FUNÇÃO DA PESSOA MAIS VELHA----------------------------------------------
/**
void pessoa_mais_velha() {
    if (n_pessoas == 0) {
        printf("Lista de pessoas está vazia.\n");
        return;
    }
    
    int i, indice_pessoa_mais_velha = 0;
    struct tm data_pessoa_mais_velha = {0};
    strptime(lista_pessoas[0].data_nascimento, "%d/%m/%Y", &data_pessoa_mais_velha);
    
    for (i = 1; i < n_pessoas; i++) {
        struct tm data_pessoa_i = {0};
        strptime(lista_pessoas[i].data_nascimento, "%d/%m/%Y", &data_pessoa_i);
        if (difftime(mktime(&data_pessoa_i), mktime(&data_pessoa_mais_velha)) > 0) {
            indice_pessoa_mais_velha = i;
            data_pessoa_mais_velha = data_pessoa_i;
        }
    }
    
    printf("Pessoa mais velha: ");
    imprimir_pessoa(lista_pessoas[indice_pessoa_mais_velha]);
}

//-------------------------------------------------FUNÇÃO DA SEGUNDA PESSOA MAIS NOVA----------------------------------------------
void segunda_pessoa_mais_nova() {
    if (n_pessoas < 2) {
        printf("Lista de pessoas não contém pelo menos duas pessoas.\n");
return;
}

int indice_pessoa_mais_nova = 0, indice_segunda_pessoa_mais_nova = 1;
struct tm data_pessoa_mais_nova = {0}, data_segunda_pessoa_mais_nova = {0};
strptime(lista_pessoas[0].data_nascimento, "%d/%m/%Y", &data_pessoa_mais_nova);
strptime(lista_pessoas[1].data_nascimento, "%d/%m/%Y", &data_segunda_pessoa_mais_nova);

if (difftime(mktime(&data_segunda_pessoa_mais_nova), mktime(&data_pessoa_mais_nova)) > 0) {
    indice_pessoa_mais_nova = 1;
    indice_segunda_pessoa_mais_nova = 0;
    struct tm temp = data_pessoa_mais_nova;
    data_pessoa_mais_nova = data_segunda_pessoa_mais_nova;
    data_segunda_pessoa_mais_nova = temp;
}

int i;
for (i = 2; i < n_pessoas; i++) {
    struct tm data_pessoa_i = {0};
    strptime(lista_pessoas[i].data_nascimento, "%d/%m/%Y", &data_pessoa_i);
    if (difftime(mktime(&data_pessoa_i), mktime(&data_pessoa_mais_nova)) < 0) {
        indice_segunda_pessoa_mais_nova = indice_pessoa_mais_nova;
        indice_pessoa_mais_nova = i;
        data_segunda_pessoa_mais_nova = data_pessoa_mais_nova;
        data_pessoa_mais_nova = data_pessoa_i;
    } else if (difftime(mktime(&data_pessoa_i), mktime(&data_segunda_pessoa_mais_nova)) < 0) {
        indice_segunda_pessoa_mais_nova = i;
        data_segunda_pessoa_mais_nova = data_pessoa_i;
    }
}

printf("Segunda pessoa mais nova: ");
imprimir_pessoa(lista_pessoas[indice_segunda_pessoa_mais_nova]);

}

*/
//--------------------------------------------FUNÇÃO ELIMINAR PESSOA COM ID PAR----------------------------------------------
void eliminar_pessoas_id_par() {
int i, j = 0;
for (i = 0; i < n_pessoas; i++) {
if (lista_pessoas[i].id % 2 == 0) {
j++;
} else {
lista_pessoas[i-j] = lista_pessoas[i];
}
}
n_pessoas -= j;
printf("%d pessoas eliminadas com sucesso.\n", j);
}


//---------------------------------------------MENU DE NAVEGAÇÃO------------------------------------------------

int main() {
int opcao;
do {
printf("\n----- MENU -----\n");
printf("1. Adicionar pessoa\n");
printf("2. Eliminar pessoa\n");
printf("3. Pessoa mais velha\n");
printf("4. Segunda pessoa mais nova\n");
printf("5. Eliminar pessoas com ID par\n");
printf("0. Sair\n");
printf("Escolha uma opcao: ");
scanf("%d", &opcao);


    switch(opcao) {
        case 1:
            adicionar_pessoa();
            break;
        case 2:
            eliminar_pessoa();
            break;
       /* case 3:
            pessoa_mais_velha();
            break;
        case 4:
            segunda_pessoa_mais_nova();
            break;*/
        case 5:
            eliminar_pessoas_id_par();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
                }

    } while (opcao != 0);

    return 0;
}
