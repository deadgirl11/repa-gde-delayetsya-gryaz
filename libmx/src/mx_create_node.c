#include "libmx.h"

t_list  *mx_create_node(void *data) {
	t_list *head = (t_list*)malloc(sizeof(t_list));
	if(head) {
		head->data = data;
		head->next = NULL;
	}
	return head;
}
