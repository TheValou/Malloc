#ifndef LIBMY_MALLOC_H_
# define LIBMY_MALLOC_H_
# define BLOCK_SIZE sizeof(t_block)

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define FREE 0
# define TAKEN 1

typedef	struct		s_block
{
  size_t		size;
  struct s_block	*prev;
  struct s_block	*next;
  int			free;
}			t_block;

int	my_putchar(char c);
int	my_putstr(char *str);
void	*malloc(size_t taille);
void	free(void *ptr);
void	*realloc(void *ptr, size_t taille);
void	putlist(t_block *elem, size_t taille);
void	*check_free(size_t size);

#endif /* !LIBMY_MALLOC_H_ */
