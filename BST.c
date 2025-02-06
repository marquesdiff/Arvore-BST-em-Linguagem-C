#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct no{

    int valor;
    struct no *esquerda, *direita;
}No;


No *novoNo(int x){

	No *novo = malloc(sizeof(No));

	if(novo){
		novo->valor = x;
		novo->esquerda = NULL;
		novo->direita = NULL;
		return novo;
	}
	else{
		printf("Erro ao alocar o nó em novoNo!\n");
	}
	return novo;
}


No *inserir(No *raiz, int num){

    if(raiz == NULL){
        return novoNo(num);
	}
	else{
		if(num < raiz->valor){
			raiz->esquerda = inserir(raiz->esquerda, num);
		}
		else if (num > raiz->valor){
			raiz->direita = inserir(raiz->direita, num);
		}
		else{
            printf("\nInserção não realizada!\nO elemento %d já existe!\n", num);
		}

		return raiz;
	}
}


void imprimirPreOrder(No *raiz){

	if(raiz){
        printf("[%d]", raiz->valor);
		imprimirPreOrder(raiz->esquerda);
		imprimirPreOrder(raiz->direita);
	}
}


void imprimirInOrder(No *raiz){

	if(raiz){
		imprimirInOrder(raiz->esquerda);
		printf("[%d]", raiz->valor);
		imprimirInOrder(raiz->direita);
	}
}


void imprimirPosOrder(No *raiz){

	if(raiz){
		imprimirPosOrder(raiz->esquerda);
		imprimirPosOrder(raiz->direita);
		printf("[%d]", raiz->valor);
	}
}


void imprimirReverso(No *raiz) {
    if (raiz) {
        imprimirReverso(raiz->direita);
        printf("[%d]", raiz->valor);
        imprimirReverso(raiz->esquerda);
    }
}


int altura(No *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esquerdo = altura(raiz->esquerda);
        int direito = altura(raiz->direita);
        if(esquerdo > direito){
            return esquerdo +1;
        }
        else {
            return direito +1;
        }
    }
}


void imprimirAltura(No *raiz){
    if (raiz != NULL){
        printf("%d\n", altura(raiz));
    }
    else{
        printf("0\n");
    }
}


int qtdFolhas(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    else if (raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }
    else {
        return qtdFolhas(raiz->esquerda) + qtdFolhas(raiz->direita);
    }
}


bool caminho(No *raiz, int chave) {
    No *aux = raiz;
    bool encontrado = false;

    // Alocação dinâmica inicial
    int capacidade = 10;
    int *caminhoValores = malloc(capacidade * sizeof(int));
    int i = 0;

    while (aux != NULL) {
        if (i == capacidade) {
            capacidade *= 2;
            caminhoValores = realloc(caminhoValores, capacidade * sizeof(int));
        }

        caminhoValores[i++] = aux->valor;

        if (chave == aux->valor) {
            encontrado = true;
            break;
        } else if (chave < aux->valor) {
            aux = aux->esquerda;
        } else {
            aux = aux->direita;
        }
    }

    if (encontrado) {
        for (int j = 0; j < i; j++) {
            printf("[%d]", caminhoValores[j]);
        }
        printf("\n");
    } else {
        printf("\n");
    }

    free(caminhoValores); // Liberar a memória alocada
    return encontrado;
}


No *remover(No *raiz, int chave){
    if(raiz == NULL){
        printf("Valor não encontrado!\n");
		return NULL;
	}
	else{
		if(raiz->valor == chave){
			if(raiz->esquerda == NULL && raiz->direita == NULL){
				free(raiz);
				return NULL;
			}
			else{
				//outros casos com filhos...
				// 2 filhos
			  if(raiz->esquerda != NULL && raiz->direita != NULL){
			     No *aux = raiz->esquerda;
			     while(aux->direita != NULL){
			     	aux = aux->direita;
			     }
			     raiz->valor = aux->valor;
			     aux->valor = chave;
			     raiz->esquerda = remover(raiz->esquerda, chave);
			     return raiz;
			     }
			  // 1 filho
			  else{
			  	No *aux;
				if(raiz->esquerda != NULL){
					aux = raiz->esquerda;
				}
				else{
					aux = raiz->direita;
				}
			     free(raiz);
			     return aux;
			   }
			 }
		}
		else{
			if(chave < raiz->valor){
			   raiz->esquerda = remover(raiz->esquerda, chave);
			}
			else{
			   raiz->direita = remover(raiz->direita, chave);
			}
			return raiz;
		}
	}
}


No *inicializar(){

    return NULL;
}


int main(){

    setlocale(LC_ALL, "Portuguese");
    No *raiz = inicializar();
    int opcao, valor;

    do{
        printf("\n\t1 - inserir\n\t2 - preorder\n\t3 - inorder\n\t4 - posorder\n\t5 - reverso");
        printf("\n\t6 - altura\n\t7 - qtdFolhas\n\t8 - caminho\n\t9 - remover\t\n\t99 - sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\nDigite um número inteiro que deseja inserir na ávore Binária de Busca(BST): ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            imprimirPreOrder(raiz);
            printf("\n");
            break;
        case 3:
            imprimirInOrder(raiz);
            printf("\n");
            break;
        case 4:
            imprimirPosOrder(raiz);
            printf("\n");
            break;
        case 5:
            imprimirReverso(raiz);
            printf("\n");
            break;
        case 6:
            imprimirAltura(raiz);
            break;
        case 7:
            printf("%d\n", qtdFolhas(raiz));
            break;
        case 8:
            printf("\nDigite o número inteiro que deseja procurar na árvore e exibir o seu caminho até esse mesmo número: ");
            scanf("%d", &valor);
            caminho(raiz, valor);
            break;
        case 9:
            printf("\nDigite um número inteiro que deseja remover da ávore Binária de Busca(BST): ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if(opcao != 99){
                printf("\nOpção inválida!\n");
            }
            break;
        }

    }while(opcao != 99);

    return 0;
}
