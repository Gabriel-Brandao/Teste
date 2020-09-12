#include <stdio.h>
#include <stdlib.h>

struct No{
	int chave;
	struct No *prox;
};

struct Fila{
	struct No *primeiro;
	struct No *ultimo;
	int n;
};

void menu();
int opcao(struct Fila *f);
void inicica_fila(struct Fila *f);
int isEmpty(struct Fila *f);
int enqueue(struct Fila *f, int k);
int dequeue(struct Fila *f);
void imprimir(struct Fila *f);

void menu(){
	printf("\n1. Enqueue\n"
			"2. Dequeue\n"
			"3. Imprimir\n"
			"4. Primeiro\n"
			"5. isEmpty\n"
			"6. numero de elementos na fila\n"
			"7. Sair\n\n");
}

int opcao(struct Fila *f){
	int op, k;

	scanf("%d", &op);
	system("cls");

	switch(op){
		case 1:
			printf("Informe elemento a enfileirar:\n");
			scanf("%d", &k);
			if(enqueue(f, k))
				printf("Elemento enfileirado com sucesso\n");
			else
				printf("Queue Overflow!!\n Nao foi possivel enfileirar elemento\n");
			break;
		case 2:
			if((k = dequeue(f)) == -1)
				printf("Queue Underflow!!");
			else
				printf("\"%d\" desenfileirado com sucesso\n", k);
			break;
		case 3:
			imprimir(f);
			break;

		case 4:
			if((k = primeiro(f)) == -1)
				printf("Fila vazia\n");
			else
				printf("\"%d\" eh o primeiro\n", k);
			break;

		case 5:
			if(isEmpty(f))
				printf("Fila vazia\n");
			else
				printf("Fila nao vazia\n");
			break;

		case 6:
			printf("A lista tem \"%d\" elementos\n", num_elementos(f));
			break;
		case 7:
			break;
		default:
			printf("opcao invalida\n");
	}
	return op;
}

void inicica_fila(struct Fila *f){
	f->primeiro = NULL;
	f->ultimo = NULL;
	f->n = 0;
}

int isEmpty(struct Fila *f){

	if(f->n == 0)
		return 1;
	else
		return 0;
}

int enqueue(struct Fila *f, int k){
	struct No *novo = (struct No *) malloc(sizeof(struct No));

	if(novo == NULL) //memeoria cheia
		return 0;
	else
		novo->chave = k;
		novo->prox = NULL;

		if(isEmpty(f))//prmeiro elemneto a ser enfileirado
			f->primeiro = novo;
		else
			f->ultimo->prox = novo;

		f->ultimo = novo; //fila nao vazia
		f->n ++;
		return 1;
}

int dequeue(struct Fila *f){
	struct No *q = f->primeiro;
	int ret;

	if(isEmpty(f))
		return -1;

	ret = q->chave;

	if(f->n == 1)//apenas um elemento
		f->primeiro = NULL;
	else //mais elementos
		f->primeiro = f->primeiro->prox;

	f->n --;
	free(q);
	return ret;
}

void imprimir(struct Fila *f){
	struct No *q = f->primeiro;

	if(isEmpty(f))
		printf("Fila vazia\n");
	else

	while(q != NULL){
		printf("%d ", q->chave);
		q = q->prox;
	}
}

int primeiro(struct Fila *f){

	if(isEmpty(f))
		return -1;
	else
		return f->primeiro->chave;
}

int num_elementos(struct Fila *f){
	return f->n;
}

int main(){
	struct Fila *F = (struct Fila *) malloc(sizeof(struct Fila));
	int op;
	inicica_fila(F);

	do
	{
		menu();
		op = opcao(F);

	}while(op != 7);

}
