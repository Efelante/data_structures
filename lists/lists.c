#include <stdlib.h>
#include "lists.h"

/* allocate empty list */
struct list *list_alloc_empty()
{
	struct list *list;
	list = (struct list *) malloc(sizeof(struct list));
	if(!list)
	{
		return NULL;
	}
	list->next = list->prev = list->resource = NULL;
	return list;
};

/* 
 *	add element to list. 
 */

struct list *list_add_head(struct list *head, void *resource)
{
	struct list *elem;
	if(!head)
	{
		head = list_alloc_empty();
		if(!head)
		{
			return NULL;
		}
		head->resource = resource;
		return head;
	}
	
	elem = (struct list *) malloc(sizeof(struct list));
	if(!elem)
	{
		return NULL;
	}
	elem->resource = resource;
	elem->prev = NULL;
	elem->next = head;
	head->prev = elem;
	return elem;
};

struct list *list_add_tail(struct list *tail, void *resource)
{
	struct list *elem;
	if(!tail)
	{
		tail = list_alloc_empty();
		if(!tail)
		{
			return NULL;
		}
		tail->resource = resource;
		return tail;
	}
	elem = (struct list *) malloc(sizeof(struct list));
	if(!elem)
	{
		return NULL;
	}
	elem->resource = resource;
	elem->prev = tail;
	elem->next = NULL;
	tail->next = elem;
	return elem;
};

/* remove element from the list */
int list_del(struct list *elem)
{
	if(!elem)
	{
		return -RETVAL_GENERAL_ERROR;
	}
	if(elem->prev)
	{
		elem->prev->next = elem->next;
	}
	if(elem->next)
	{
		elem->next->prev = elem->prev;
	}
	free(elem);
	return RETVAL_SUCCESS;
};

/* remove all elements form the list */
int list_del_all(struct list *head)
{
	struct list *curr;
	if(!head)
	{
		return -RETVAL_GENERAL_ERROR;
	}

	for(curr = head; head; curr = head)
	{
		head = curr->next;
		free(curr);
	}
	return RETVAL_SUCCESS;
};
