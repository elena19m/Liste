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

int main(){
	nod *nod1;
	nod1 = (nod *) malloc (sizeof(nod));
	nod1->val = 7;
	nod1->next = NULL;
	afisL(nod1);
	return 0;
}
