#include "libmy_malloc.h"

t_block		*g_first = NULL;
t_block		*g_last = NULL;

void		*check_free(size_t size)
{
  t_block	*block;

  block = g_first;
  while (block != NULL)
    {
      if ((block->free == FREE) && (block->size > (size + BLOCK_SIZE)))
	{
	  block->free = TAKEN;
	  return (block);
	}
      block = block->next;
    }
  return (NULL);
}

void		putlist(t_block *elem, size_t taille)
{
  elem->free = TAKEN;
  elem->size = taille;
  elem->prev = g_last;
  elem->next = NULL;
  if (g_last)
    g_last->next = elem;
  else
    g_first = elem;
  g_last = elem;
}

void		*malloc(size_t taille)
{
  t_block	*elem;

  if (taille < 1)
    return (NULL);
  elem = check_free(taille);
  if (elem == NULL)
    {
      elem = sbrk(taille + BLOCK_SIZE);
      if (elem == (void *)-1)
	return (NULL);
      putlist(elem, taille);
    }
  return (elem + 1);
}

void		free(void *ptr)
{
  t_block	*my_ptr;

  if (ptr == NULL)
    return ;
  my_ptr = g_first;
  while (my_ptr && my_ptr != ptr)
    my_ptr = my_ptr->next;
  if (my_ptr == NULL)
    return ;
  my_ptr = (t_block *)ptr - 1;
  my_ptr->free = FREE;
  if (my_ptr->next == NULL)
    brk(my_ptr);
}

void		*realloc(void *ptr, size_t taille)
{
  void		*mrealoc;
  t_block	*my_ptr;
  t_block	*tmp;

  tmp = (t_block *)ptr - 1;
  my_ptr = g_first;
  if (ptr == NULL)
    return (malloc(taille));
  while (my_ptr && my_ptr != tmp)
    my_ptr = my_ptr->next;
  if (my_ptr)
    {
      if ((mrealoc = malloc(taille)) == NULL)
	return (NULL);
      memcpy(mrealoc, ptr, taille);
      free(ptr);
      return (mrealoc);
    }
  else
    return (malloc(taille));
}
