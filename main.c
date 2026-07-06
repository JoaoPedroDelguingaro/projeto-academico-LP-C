#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto{
    int codigo;
    char nome[100];
    int quantidade;
    double preco;
} Produto;

typedef struct No{
    Produto produto;
    struct No *prox;
} No;

No *lista = NULL;

void listarRec(No *lista){
    
    if(lista == NULL) return;

    printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco Unitario: %.2f | Valor Total: %.2f.\n",
        lista->produto.codigo, lista->produto.nome, 
        lista->produto.quantidade, lista->produto.preco,
        lista->produto.quantidade * lista->produto.preco);

    listarRec(lista->prox);
}

void listarProdutos(No *lista){

    if(lista == NULL){
        printf("\nA lista esta vazia\n");
        return;
    }
    
    listarRec(lista);
}

int proximoCodigo() {
    if (lista == NULL) return 1;

    int maior = 0;
    No *aux = lista;

    while (aux != NULL) {
        if (aux->produto.codigo > maior){
            maior = aux->produto.codigo;
        }
        aux = aux->prox;
    }

    return maior + 1;
}

void adicionarProdutos(){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;

    printf("Nome: ");
    fgets(novo->produto.nome, sizeof(novo->produto.nome), stdin);
    novo->produto.nome[strcspn(novo->produto.nome, "\n")] = '\0'; 

    printf("Quantidade: ");
    scanf("%d", &novo->produto.quantidade);
    getchar();

    printf("Preco: ");
    scanf("%lf", &novo->produto.preco);
    getchar();

    novo->produto.codigo = proximoCodigo();
    novo->prox = NULL;

    if (lista == NULL){
        lista = novo;
    } else {
        No *aux = lista;

        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    printf("Produto cadastrado com sucesso!!!\n");
}

void excluirProdutos(){
     if (lista == NULL) {
        printf("\nA lista esta vazia.\n");
        return;
    }

    int codigoBuscado;
    printf("\nDigite o codigo do produto que deseja remover: ");
    scanf("%d", &codigoBuscado);
    getchar();

    No *atual = lista;
    No *anterior = NULL;

    while (atual != NULL && atual->produto.codigo != codigoBuscado) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto com o codigo %d nao foi encontrado.\n", codigoBuscado);
        return;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual); 
    printf("Produto removido com sucesso!!!\n");
}

void menu(){
    int opcao = -1;

    while(opcao != 0){
        printf("\n**** Menu de Cadastros\n");
        printf("1 - Listar Produtos \n");
        printf("2 - Adicionar Produtos\n");
        printf("3 - Excluir Produtos\n");
        printf(" \n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao){
            case 1:
                listarProdutos(lista);
                break;
            case 2:
                adicionarProdutos();
                break;
            case 3:
                excluirProdutos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao Invalida.\n");
        }
    }
}

void lerArquivo(char *arquivoNome){
    FILE *f = fopen(arquivoNome, "rb");

    if(f == NULL){
        printf("\nArquivo %s nao encontrado\n", arquivoNome);
        return ;
    }

    Produto p;
    int count = 0;
    No *ultimo = NULL;
    
    while(fread(&p, sizeof(Produto), 1, f) == 1){ 
        No *novo = (No*) malloc(sizeof(No));
        if(novo == NULL){
            fclose(f);
            return;
        }

        novo->produto = p;

        printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco Unitario: %.2f.\n",
        novo->produto.codigo, novo->produto.nome, 
        novo->produto.quantidade, novo->produto.preco);

        novo->prox = NULL;

        if(lista == NULL){
            lista = novo;
        } else {
            ultimo->prox = novo;
        }
        ultimo = novo;
        count++;
    }
    if (count == 0){
        printf("\nArquivo lido, porem vazio\n");
    }else{
        printf("\nNumero de Produtos lidos: %d\n", count);
    }

    fclose(f);
}

void salvarArquivo(char *arquivoNome){
    FILE *f = fopen(arquivoNome, "wb");
    if (f == NULL) {
        printf("Erro ao salvar os dados!\n");
        return;
    }

    No *atual = lista;
    while (atual != NULL) {
        fwrite(&(atual->produto), sizeof(Produto), 1, f);
        atual = atual->prox;
    }
    fclose(f);
}

void desalocarLista(No *lista){
    if(lista == NULL) return;

    desalocarLista(lista->prox);
    free(lista);
}
  
int main(){
    char *arquivoNome = "produtos.bin";
    lerArquivo(arquivoNome);
    menu();
    salvarArquivo(arquivoNome);
    desalocarLista(lista);
    return 0;  
}