#include<stdio.h>
#include<stdlib.h>

struct _node{
	int a;
	int b;
	char c;
	struct _node *next;
};


void init_list(struct _node *head)
{	
	//head->next = NULL;
	head = NULL;
}
void add_node(struct _node *node,struct _node *head)
{
	if( NULL == node )
		return ;
	else{
		struct _node *tmp=NULL;
		tmp = head->next;
		head->next = node;
		node->next = tmp;
	}

	while( head->next )
	{
		printf("%d %d %c \n",head->next->a,head->next->b,head->next->c);
		head = head->next;
	}
			
}

void del_node(int avalue,struct _node *head)
{
	for(;head->next != NULL;head=head->next){
		if(head->next->a == avalue){
			head->next = head->next->next;
		}
	}
}

int main(int argc,char *argvi[])
{
	
	struct _node *head;
	init_list(head);
	struct _node *tmp = malloc(sizeof(struct _node));
	tmp->a = 10;
	tmp->b = 11;
	tmp->c = 'a';

	add_node(tmp,head);

	return 0;
}
