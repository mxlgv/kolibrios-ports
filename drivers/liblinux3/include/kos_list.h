#ifndef _KOS_LIST_H_
#define _KOS_LIST_H_

#include <linux/types.h>

typedef struct kos_lhead_s {
  struct kos_lhead_s *prev;
  struct kos_lhead_s *next;
} kos_lhead_t;

#define KOS_LIST_INITIALIZE(name) \
	kos_lhead_t name = { .prev = &name, .next = &name }

#define kos_list_get_instance(link, type, member) \
  ((type *)(((u8_t *)(link)) - ((u8_t *)&(((type *)NULL)->member))))

static inline 
void kos_lhead_initialize(kos_lhead_t *link)
{
	link->prev = NULL;
	link->next = NULL;
}

static inline 
void kos_list_initialize(kos_lhead_t *head)
{
	head->prev = head;
	head->next = head;
}

static inline 
void kos_list_append(kos_lhead_t *link, kos_lhead_t *head)
{
	link->prev = head->prev;
	link->next = head;
	head->prev->next = link;
	head->prev = link;
}

static inline
void kos_list_remove(kos_lhead_t *link)
{
	link->next->prev = link->prev;
	link->prev->next = link->next;
	kos_lhead_initialize(link);
}

static inline 
bool kos_list_empty(kos_lhead_t *head)
{
    return head->next == head ? true : false;
}

static inline 
void kos_list_prepend(kos_lhead_t *link, kos_lhead_t *head)
{
	link->next = head->next;
	link->prev = head;
	head->next->prev = link;
	head->next = link;
}

static inline 
void kos_list_insert(kos_lhead_t *new, kos_lhead_t *old)
{
   new->prev = old->prev;
   new->next = old;
   new->prev->next = new;
   old->prev = new;
}

#endif // _KOS_LIST_H_