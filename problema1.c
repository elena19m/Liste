#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
	int val;
	struct nod *next;
}nod;

void print(nod *l){
	l = l->next;
	while(l != NULL){
		printf("%d ",l->val);
		l = l->next;
		}
	printf("\n");
}

nod *addI(nod *l, int val){
	nod *q;
	q = (nod *)malloc(sizeof(nod));
	q->val = val;
	if (l-> next == NULL){
		q->next = NULL;
		l->next = q;
		return l;
		}
	q->next = l->next;
	l->next = q;
	return l;
}

nod *addS(nod *l, int val){
	nod *q, *t;
	t = l;
	q = (nod *)malloc(sizeof(nod));
	q->val = val;
	while( l->next != NULL)
		l = l->next;
	q->next = NULL;
	l->next = q;
	l = t;
	return l;
}

nod *search(nod *l, int val){
	l = l->next;
	while (l != NULL){
		if(l->val == val)
			return l;
		l = l-> next;
		}
	return l;
}

nod *addV(nod *l, int n, int val){
	nod *q, *t, *p;
	t = search(l,n);
	if (t == NULL)
		{
		l = addS(l,val);
		return l;
		}
	q = (nod *)malloc(sizeof(nod));
	q->val = val;
	q->next = t->next;
	t->next = q;
	return l;
}

nod *delete(nod *l, int val){
	nod *q;
	q = search(l,val);
	if (q == NULL)
		return l;
	nod *p;
	p = l;
	while(l->next->val != val)
		l = l->next;
	q = l->next;
	l->next = l->next->next;
	free(q);
	l = p;
	return l;
}

nod *init(nod *l){
	l = (nod *)malloc(sizeof(nod));
	l->next = NULL;
}

void afisL(nod *l){
	l = l->next;
	while(l != NULL){
		printf("%d ",l->val);
		l = l->next;
		}
	printf("\n");
}

nod * reverse(nod *l){
	nod *aux1 = NULL, *aux2 = l->next, *aux3;
	while(aux2->next != NULL){
		aux3 = aux2->next;
		aux2->next =  aux1;
		aux1 = aux2;
		aux2 = aux3;
		}
	aux2->next = aux1;
	l->next = aux2;
	return l;
}

int main(){
	nod *l;
	l = init(l);
	l = addI(l,7);
	afisL(l);
	l = addS(l,5);
	afisL(l);
	l = addI(l,4);
	afisL(l);
	l = addS(l,1);
	afisL(l);
	l = addV(l,5,2);
	afisL(l);
	l = addV(l,10,3);
	afisL(l);
	l = delete(l, 5);
	afisL(l);
	l = reverse(l);
	afisL(l);
	return 0;	
}
