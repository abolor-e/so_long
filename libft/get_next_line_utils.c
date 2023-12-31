#include "libft.h"
/*
void	free_list(t_gnl **list, t_gnl *new_node, char *str)
{
	t_gnl	*tmp;

	if (!(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (!new_node)
		return ;
	if (new_node->str_buf[0])
		*list = new_node;
	else
	{
		free(new_node);
	}
    free(str);
}
*/

void	free_list(t_gnl **list, t_gnl *new_node, char *str)
{
	t_gnl	*tmp;

	if (!(*list))
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	if (new_node)
	{
		if (new_node->str_buf)
			free(new_node->str_buf);
		free(new_node);
	}	
    free(str);
}

void	copy(t_gnl *list, char *new_str)
{
	int	i;
	int	a;

	a = 0;
	if (!list)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				new_str[a++] = '\n';
				new_str[a] = '\0';
				return ;
			}
			new_str[a++] = list->str_buf[i++];
		}
		list = list->next;
	}
	new_str[a] = '\0';
}

int	len_until_newline(t_gnl *list)
{
	int	len;
	int	i;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			++len;
			++i;
		}
		list = list->next;
	}
	return (len);
}

t_gnl	*ft_lstlast(t_gnl *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

int	newline_check_list(t_gnl *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}