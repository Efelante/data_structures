/*
 *
 */
#ifndef LISTS_H
#define LISTS_H

/* type of return value */
enum {
	RETVAL_SUCCESS = 0,
	RETVAL_GENERAL_ERROR,
	RETVAL_MEM_ERROR
};

/* connecting lists */
struct list {
	struct list *next;
	struct list *prev;
	void *resource;
};

/* allocate empty list */
struct list *list_alloc_empty();

/* 
 *	add element to list. 
 */
struct list *list_add_head(struct list *head, void *resource);
struct list *list_add_tail(struct list *tail, void *resource);

/* remove element from the list */
int list_del(struct list *elem);

/* remove all elements form the list */
int list_del_all(struct list *head);

#endif