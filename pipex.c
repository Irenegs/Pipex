# include "pipex.h"

int validation_input(int argc, char **argv)
{
    if (argc == 5)
    {
        if (access(argv[1], R_OK) == 0)
        {
            if (access(argv[4], W_OK) == 0)
            {
                //printf("hi\n");
                //if (access(argv[2], X_OK) == 0 && access(argv[3], X_OK) == 0)
                return (0);
            }
        }
    }
    perror("Error");
    return (1);
}

int main(int argc, char **argv)
{
    /*int     fd[2];
    pid_t   childpid;
    char    string[] = "Hello, world!\n";
    char    readbuffer[80];*/
    char    *argumentos[] = {"/usr/bin/ls", "-l", "pipex.h", NULL};
    /*int     input_fd;
    int     output_fd;*/

    if (validation_input(argc, argv) != 0)
        exit (1);
    printf("Todo chachi\n");
    if (execve("/usr/bin/wc", argumentos, NULL) == -1)
        perror("execve");
    exit (0);
    /*
    pipe(fd);
    childpid = fork();
    printf("childpid 0: %d\n", childpid);
    if(childpid == -1)
    {
        perror("fork");
        exit(1);
    }
    if(childpid == 0)
    {*/
        /* Child process closes up input side of pipe*/
        /*
        input_fd = open(argv[1],O_RDONLY);
        printf("childpid 1: %d\n", childpid);
        dup2(0, fd[0]);
        execve("cat", argumentos, NULL);
        printf("childpid 2: %d\n", childpid);
        */
        /* Send "string" through the output side of pipe*/
        /*
        write(fd[1], string, (strlen(string)+1));
        printf("childpid 3: %d\n", childpid);
        close(input_fd);
        exit(0);
        
    }
    else
    {*/
        /* Parent process closes up output side of pipe*/
        /*
        close(fd[1]);
        printf("childpid 4: %d\n", childpid);*/
        /* Read in a string from the pipe*/
        /*
        read(fd[0], readbuffer, sizeof(readbuffer));
        printf("childpid 5: %d\n", childpid);
        printf("Received string: %s", readbuffer);
        printf("childpid 6: %d\n", childpid);
    }
    return(0);
    */
}


/*
- validación de datos argc >= 5
- permisos de lectura y escritura en los archivos (access)
- permisos de ejecución de los comandos? (access x?)
- crear pipe, establece unos fd[0] y fd[1]
- crear proceso hijo fork() asignado en childprocess, que en el padre es != 0 y en el hijo es == 0
- establecer los pasos de cada proceso:
    - hijo, cierra fd[0] y ejecuta el primer comando sobre (read) input_file y lo escribe (write) en fd[1]
    - padre, cierra fd[1] y ejecuta el segundo comando sobre (read) fd[0] y escribe (write) sobre output_file
*/