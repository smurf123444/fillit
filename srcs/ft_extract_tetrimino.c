/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tetrimino.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:25:49 by lbogar            #+#    #+#             */
/*   Updated: 2018/08/11 10:39:21 by chmannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**this assumes that the old size passed includes a null,
**that the size is char and includes the previous size,
**and that the new size is getting bigger, not smaller
*/

static int		legal_char(char *str)

	int		i;

	i = 0;
	while (str[i])												
	{
I		if (str[i] != '#' && str[i] != '.' && str[i] != '\n') 
			return (1); 										
		++i; 
	}															
	return (0); 												
}	
			/* ------------------------------------------------------------------------------------ */
			/* Checks if values given in parameter as an array are Valid with the proper characters,*/
			/* with other checks involved, such as main_check                                       */
			/* ------------------------------------------------------------------------------------ */
static int		check_if_valid(char *str)
{
	if (legal_char(str)) 				
		return (1);				
	if (main_check(str))				
		return (1);				
	if (check_hash(str)) 				
		return (1); 					
	else
		return (0); 					
}			

			/* ---------------------------------------------------------------*/
			/* appends the ptr with newptr using the value of "*ptr" and the  */
			/* byte size of what ever "size_t size"		  		  */
			/* ---------------------------------------------------------------*/

static char		*ft_append_str(void *ptr, size_t size)
{
	void		*newptr;
	size_t		old_size;

	newptr = (char*)malloc(sizeof(char) * size);
	ft_memset(newptr, 0, size);					
	old_size = ft_strlen(ptr); 					
	ft_memcpy(newptr, ptr, old_size); 			
	free(ptr); 									
	return (newptr); 							
}
			 /*-----------------------------------------------------------------*/
			 /* this function says to open the filename, sets a "tetrimino" for */
			 /* use with a 21 byte (ft_strnew), then sets a "temp" int with the */
			 /* same value, while ret is equal to the value of temp after read  */
			 /* from fc, with 21 bytes, combine what was read from the filename */
			 /* to the end of the new str with 21 bytes as well, then adding an */
			 /* extra 21 to size giving value of size 43 . Using this newly     */
			 /* added value for Size with 43, we will append the tetrimino	    */
			 /* string with the Size int of 43, as well as set memory to the    */
			 /* temp to all 0's throughout the 21 bytes it has been allocated.. */
			 /*-----------------------------------------------------------------*/

char			*ft_extract_tetrimino(char *filename)
{
	char		*tetrimino;
	char		*temp;
	int			fd;
	int			ret;
	int			size;

	size = 22;										
	fd = open(filename, O_RDONLY);					
	tetrimino = ft_strnew(21);						
	temp = ft_strnew(21);							
	while ((ret = read(fd, temp, 21)))				
	{
		ft_strcat(tetrimino, temp); 				
		size += 21;									
		tetrimino = ft_append_str(tetrimino, size); 
		ft_memset(temp, 0, 21);						
	}
	if (check_if_valid(tetrimino)) 					
	{
		ft_putstr("error\n"); 						
		exit(1);									
	}
	return (tetrimino);								
}
