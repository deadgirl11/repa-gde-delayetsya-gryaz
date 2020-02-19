#include "libmx.h"

static void list_swap(void **lst1, void **lst2) {
   void *temp = *lst1;
   *lst1 = *lst2;
   *lst2 = temp;
}
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)){
   if (lst && cmp) {
       for (t_list *node1 = lst; node1; node1 = node1->next)
           for (t_list *node2 = lst; node2->next; node2 = node2->next)
               if (cmp(node2->data, node2->next->data))
                   list_swap(&node2->data, &node2->next->data);
   }
   return lst;
}
