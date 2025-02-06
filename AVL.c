#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *esquerda, *direita;
	short altura;
}No;


No *novoNo(int x){
	No *novo = malloc(sizeof(No));

	if(novo){
		novo->valor = x;
		novo->esquerda = NULL;
		novo->direita = NULL;
		novo->altura = 0;
	}
	else{
		printf("\nErro ao alocar o nó em novoNo!\n");
	}
	return novo;
}


short maior(short a, short b){
    return (a > b)? a : b;
}


short alturaDoNo(No *no){
    if (no == NULL){
        return -1;
    }
    else {
        return no->altura;
    }
}


short fatorDeBalanceamento(No *no){
    if(no){
        return (alturaDoNo(no->esquerda) - alturaDoNo(no->direita));
    }
    else{
        return 0;
    }
}


No *rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direita;
    f = y->esquerda;

    y->esquerda = r;
    r->direita = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}


No *rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerda;
    f = y->direita;

    y->direita = r;
    r->esquerda = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}


// Rotação dupla à esquerda
No *rotacaoEsquerdaDireita(No *r){
    r->esquerda = rotacaoEsquerda(r->esquerda);
    return rotacaoDireita(r);
}


// Rotação dupla à direita
No *rotacaoDireitaEsquerda(No *r){
    r->direita = rotacaoDireita(r->direita);
    return rotacaoEsquerda(r);
}


No *balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);

    // Rotação esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->direita) <= 0){
        raiz = rotacaoEsquerda(raiz);
    }

    // Rotação direita
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerda) >= 0){
        raiz = rotacaoDireita(raiz);
    }

    // Rotação dupla à esquerda
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerda) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
    }

    // Rotação dupla à direita
    else if(fb < -1 && fatorDeBalanceamento(raiz->direita) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
    }
    return raiz;
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
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;

    // Verifica se a árvore precisa ser rebalanceada
    raiz = balancear(raiz);

    return raiz;
}


No *remover(No *raiz, int chave){
	if(raiz == NULL){
        printf("Valor não encontrado!\n");
		return NULL;
	}
	else{
		if(raiz->valor == chave){
		    // Remove folha
			if(raiz->esquerda == NULL && raiz->direita == NULL){
				free(raiz);
				return NULL;
			}
			else{
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
		}

		// Recalcula a altura
		raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;

		// Verifica se a árvore precisa ser rebalanceada
		raiz = balancear(raiz);

		return raiz;
	}
}


void imprimirPreOrder(No *raiz){

	if(raiz){
        printf("[%d] ", raiz->valor);
		imprimirPreOrder(raiz->esquerda);
		imprimirPreOrder(raiz->direita);
	}
}


No *inicializar(){
    return NULL;
}


int main(){

    setlocale(LC_ALL, "Portuguese");
    No *raiz =  inicializar();
    int opcao, valor;

    do{
        printf("\n\t1 - inserir\n\t2 - preorder\n\t3 - remover\n\t99 - sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            imprimirPreOrder(raiz);
            printf("\n");
            break;
        case 3:
            printf("Digite o valor a ser removido: ");
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
