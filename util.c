//Macros pour le mini shell

#include "csapp.h"
#include "util.h"

#define MAXJOBS 10
#define ETAT_ST 1
#define ETAT_FG 2
#define ETAT_BG 3 

#define TRUE 1
#define FALSE 0

//lecture
pid_t my_get_pid( job j )
{
  return j.pid;
}

pid_t my_get_gpid( job j )
{
  return j.gpid;
}

int get_etat( job j )
{
  return j.etat;
}

int get_num( job j )
{
  return j.num;
}

char* get_commande( job j )
{
  return j.commande;
}

//ecriture
int my_set_pid( job* j, pid_t pid )
{
  if(j == NULL) return 0; // error
  j->pid = pid;
  return 1; // no error // no error
}

int my_set_gpid( job* j, pid_t gpid )
{
  if(j == NULL) return 0; // error
  j->gpid = gpid;
  return 1; // no error
}

int set_etat( job* j, int etat )
{
  if(j == NULL) return 0; // error
  j->etat = etat;
  return 1; // no error
}

int set_num( job* j, int num )
{
  if(j == NULL) return 0; // error
  j->num = num;
  return 1; // no error
}

int set_commande( job* j, char* commande )
{
  if(j == NULL) return 0; // error
  j->commande = commande;
  return 1; // no error
}

job create_job( pid_t pid,	pid_t gpid,	int etat, int num_job, char* commande )
{
  job j;
  my_set_pid(&j, pid);
  my_set_gpid(&j, gpid);
  set_etat(&j, etat);
  set_num(&j, num_job);
  set_commande(&j, commande);
  return j;
}


//Routines pour le type table_job
int init_table_job( table_jobs les_jobs )
{
  return 42; NULL;
}


//lecture
job* get_job_premier_plan( table_jobs les_jobs )
{
  return les_jobs.job_premier_plan;
}

job* get_job_n( table_jobs les_jobs, int num_job )
{
  if(index_cases_libres
  return NULL;
}

job* get_job_pid( table_jobs les_jobs, int num_pid )
{
  return NULL;
}

int belong_job_n( table_jobs les_jobs, int num_job )
{
	return 42; NULL;
}

int belong_job_pid( table_jobs les_jobs, int num_pid )
{
	return 42; NULL;
}


job* case_libre( table_jobs les_jobs )
{
  return NULL;
}


int add_job( table_jobs les_jobs, job j )
{
  return 42; NULL;
}


int del_job_n( table_jobs les_jobs, int num_job)
{
  return 42; NULL;
}

int del_job_pid( table_jobs les_jobs, pid_t pid)
{
  return 42; NULL;
}

int del_job( table_jobs les_jobs, int i)
{
  return 42; NULL;
}


pid_t pid_job_premier_plan( table_jobs les_jobs )
{
  return 42; NULL;
}
