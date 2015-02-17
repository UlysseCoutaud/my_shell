/* eval : interprete une ligne de commande passee en parametre       */
#include "myshell.h"
#include "util.h"

table_jobs nos_jobs;


// fonctions externes
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

void eval(char *cmdline)
{
    char *argv[MAXARGS]; // argv pour execve()
    char buf[MAXLINE];   // contient ligne commande modifiee
    int bg;              // arriere-plan ou premier plan ?
    pid_t pid;           // process id

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return;                      // ignorer lignes vides

    if (!builtin_command(argv)) {    // commande integree ?
        // si oui, executee directement
        if ((pid = Fork()) == 0) {   // si non, executee par un fils
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        if (!bg) { // le pere attend fin du travail de premier plan
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");
        }
        else       // travail d'arriere-plan, on imprime le pid
            printf("%d %s", pid, cmdline);
    }
    return;
}

// si le premier parametre est une commande integree,
// l'executer et renvoyer "vrai"
int builtin_command(char **argv)
{
	int num_job=0;

    if (!strcmp(argv[0], "quit")) // commande "quitter"
        exit(0);
    if (!strcmp(argv[0], "fg")){    // fg
        if (argv[1][0]=='%'){ //designé par num de job
        		//A FAIRE:
        		//Choper l'entier qui suit %
        		if ( belong_job_n(nos_jobs,num_job) ){ 
        			// DO STUFF
        		} else {
        			printf("my_shell: fg: %s : tache inexistante \n", argv[1]);
        		}
        } else {	//designé par pid
       		if ( belong_job_n(nos_jobs,num_job) ){ 
        			set_etat( get_job_n(nos_jobs, ETAT_FG);
        			//REste des trucs a faire 
        		} else {
        			printf("my_shell: fg: %s : tache inexistante \n", argv[1]);
        		}
        }
		}
    if (!strcmp(argv[0], "bg"))    // bg
        return 1;
     if (!strcmp(argv[0], "stop"))    // stop
        return 1;
    if (!strcmp(argv[0], "&"))    // ignorer & tout seul
        return 1;
        
       
        
        
        
        
        
        
        
        
    return 0;                     // ce n'est pas une commande integree
}
