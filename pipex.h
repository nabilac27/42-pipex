/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:10:11 by nchairun          #+#    #+#             */
/*   Updated: 2024/12/27 00:56:46 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <unistd.h>    // open, close, read, write, access
					    // fork, pipe, execve, exit, unlink
                        // dup, dup2
# include <fcntl.h>
# include <stdio.h>     // perror
# include <stdlib.h>    // malloc, free, exit
# include <string.h>    // strerror
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>  // wait, waitpid

#endif

/*
	Header files
	are used in C to declare functions, constants, structures,
	and other elements that are shared across multiple source files
*/