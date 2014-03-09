#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
	int val;
	struct nod *next;
}nod;

void afisL(nod *p){
	while(p != NULL)
		{
		printf("%d ",p->val);
		p = p->next;
		}
	printf("\n");
}

void add(nod * &l, int n){
	nod *q, *t;
	t = l;
	while (l->next != NULL)
		l = l -> next;
	q = (nod *)malloc(sizeof(nod));
	q->val = n;
	q->next = NULL;
	l->next = q;
	l = t;
	//return l;
}

int main(){
	nod *nod1;
	nod1 = (nod *) malloc (sizeof(nod));
	nod1->val = 7;
	nod1->next = NULL;
	add(nod1, 8);
	afisL(nod1);
	return 0;
}
