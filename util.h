//utilitaires pour le projet mini shell

#include "csapp.h"
#define MAXJOBS 10


typedef struct job{
	pid_t pid;
	pid_t gpid;
	int etat; // Macros ST, FG, BG
	int num; //numero de job
	char* commande;
}job;

typedef struct table_jobs{
	job* job_premier_plan;
	job table_des_jobs[MAXJOBS];
	int index_cases_libres[MAXJOBS];
}table_jobs;

//Routines pour le type job

//lecture
pid_t my_get_pid( job j );
pid_t my_get_gpid( job j );
int get_etat( job j );
int get_num( job j );
char* get_commande( job j );

//ecriture
int my_set_pid( job* j, pid_t pid );
int my_set_gpid( job* j, pid_t gpid );
int set_etat( job* j, int etat );
int set_num( job* j, int num );
int set_commande( job* j, char* commande );

job create_job( pid_t pid,	pid_t gpid,	int etat, int num_job, char* commande );


//Routines pour le type table_job
int init_table_job( table_jobs les_jobs );

//lecture
job* get_job_premier_plan( table_jobs les_jobs );
job* get_job_n( table_jobs les_jobs, int num_job );
job* get_job_pid( table_jobs les_jobs, int num_pid );

int belong_job_n( table_jobs les_jobs, int num_job );
int belong_job_pid( table_jobs les_jobs, int num_pid );


job* case_libre( table_jobs les_jobs );

int add_job( table_jobs les_jobs, job j );

int del_job_n( table_jobs les_jobs, int num_job);
int del_job_pid( table_jobs les_jobs, pid_t pid);
int del_job( table_jobs les_jobs, int i);

pid_t pid_job_premier_plan( table_jobs les_jobs );

	 

