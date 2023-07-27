Header File 📁
* lists.h: Header file containing definitions and prototypes for all types and functions written for the project.
Type/FileDefinition/Prototype
* struct list_s•char *str
* unsigned int len
* struct list_s *next
typedef list_tstruct list_s
0-print_list.csize_t print_list(const list_t *h);
1-list_len.csize_t list_len(const list_t *h);
2-add_node.clist_t *add_node(list_t **head, const char *str);
3-add_node_end.clist_t *add_node_end(list_t **head, const char *str);
4-free_list.cvoid free_list(list_t *head)

Tasks 📃
* 0. Print list
    * 0-print_list.c: C function that prints all the elements of a list_t list.
        * If str is NULL, the function prints [0] (nil).
* 1. List length
    * 1-list_len.c: C function that returns the number of elements in a linked list_t list.

