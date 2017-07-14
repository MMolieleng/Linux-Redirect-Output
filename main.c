/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoliele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:09:16 by mmoliele          #+#    #+#             */
/*   Updated: 2017/07/14 17:27:48 by mmoliele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void	ex()
{
	char *const args[] = {"/bin/ls", NULL};
	int	fd = open("out", O_RDWR | O_CREAT, 777);
	int *b;
//	signal(SIGCHLD, SIG_IGN);	
	if (fork() == 0)
	{
		dup2(fd, 1);
		dup2(fd, 2);
		close(fd);
		close(fd);
		execve(args[0], args, NULL);
		
		printf("test\n");
		perror("Failed");
	}
	printf("\nwhatever\n");
	wait(b);
//	exit(1);
}

int	main(void)
{
	int		file_fd;
	int		stdout_fd;
	pid_t	pid;
	char	*const params[] = {"/bin/ls", "-l", NULL};

	ex();
	printf("\nWorking\n");
/*	stdout_fd = 1;
	file_fd	= open("file", O_APPEND | O_WRONLY | O_RDONLY);
	if (file_fd < 0)
	{
		write(1, "Failed File Opening\n", 20);
		return (1);
	}
	if (dup2(stdout_fd, file_fd) < 0)
	{
		write(1, "Redirecting Filed\n", 18);
		return (1);
	}
	if ((pid = fork()) == 0)
	{
		execv(params[0], params);
	}
	close(file_fd);
	*/
	return (0);
}
