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
{
	int		i;

	i = 0;
	while (str[i])												// While str[i] exists
	{
I		if (str[i] != '#' && str[i] != '.' && str[i] != '\n') // if character is not hash, . , or new line
			return (1); 										// kill program
		++i; 													// skip to new part of array until non hash, . or new line is not found;
	}															// finish checking for hashes in str[4]
	return (0); 												// end program
}	
			/* ------------------------------------------------------------------------------------ */
			/* Checks if values given in parameter as an array are Valid with the proper characters,*/
			/* with other checks involved, such as main_check                                       */
			/* ------------------------------------------------------------------------------------ */
static int		check_if_valid(char *str)
{
	int			len;

	len = ft_strlen(str);				// new int variable len given the Length of str from parameter of this function
	if (legal_char(str)) 				// go through the legal_char function above,
		return (1);						// if not kills the program (error)
	if (main_check(str))				// go through main_check function (need to learn that)
		return (1);						// if not kills the function (error)
	if (check_hash(str)) 				// Check Hashes
		return (1); 					// if not Kill the funciton (error)
	else
		return (0); 					//else works..
}			

			/* ---------------------------------------------------------------*/
			/* appends the ptr with newptr using the value of "*ptr" and the  */
			/* byte size of what ever "size_t size"		  		  			  */
			/* ---------------------------------------------------------------*/

static char		*ft_append_str(void *ptr, size_t size)
{
	void		*newptr;
	size_t		old_size;

	newptr = (char*)malloc(sizeof(char) * size);// array of new pointer is given the size of what was given in parameter for size_t size
	ft_memset(newptr, 0, size);					// newptr is set to correct memory size based on size
	old_size = ft_strlen(ptr); 					// old_size is now set to strlen from *ptr in parameter
	ft_memcpy(newptr, ptr, old_size); 			// copy the string ptr to the newptr area with the old_size
	free(ptr); 									// free ptr for some reason.
	return (newptr); 							// finish program with the newptr varible as a result.
}
			 /*-----------------------------------------------------------------*/
			 /* this function says to open the filename, sets a "tetrimino" for */
			 /* use with a 21 byte (ft_strnew), then sets a "temp" int with the */
			 /* same value, while ret is equal to the value of temp after read  */
			 /* from fc, with 21 bytes, combine what was read from the filename */
			 /* to the end of the new str with 21 bytes as well, then adding an */
			 /* extra 21 to size giving value of size 43 . Using this newly     */
			 /* added value for Size with 43, we will append the tetrimino		*/
			 /* string with the Size int of 43, as well as set memory to the 	*/
			 /* temp to all 0's throughout the 21 bytes it has been allocated.. */
			 /*-----------------------------------------------------------------*/

char			*ft_extract_tetrimino(char *filename)
{
	char		*tetrimino;
	char		*temp;
	int			fd;
	int			ret;
	int			size;

	size = 22;										// "size" variable(int) set to 22
	fd = open(filename, O_RDONLY);					// "fd" variable(int) set to open the filename given in parameter of function call with O_RDONLY access
	tetrimino = ft_strnew(21);						// tetrimino is now set with 21 for something
	temp = ft_strnew(21);							// temp is now set with 21 for something aswell
	while ((ret = read(fd, temp, 21)))				// while ret is equal to temp "codewiki.wikidot.com/c:system-calls:read"
	{
		ft_strcat(tetrimino, temp); 				// adding the tetrimino to the end of temp
		size += 21;									// size added 21 to its overall count being 43
		tetrimino = ft_append_str(tetrimino, size); // the array of the tetrimino is given the value of itself, plus the extra size variable that is going to be used..
		ft_memset(temp, 0, 21);						// setting all the value in "temp" to 0 and byte count to 21
	}
	if (check_if_valid(tetrimino)) 					// If it fails the tests described in check_if_valid function,
	{
		ft_putstr("error\n"); 						// then dosplay an error message
		exit(1);									// Kill program
	}
	return (tetrimino);								//otherwise your answer will be returned under the tetrimino variable"
}nt
