/*  Matheus Joranhezon 15/0018428
*   Felipe Hargreaves - 15/0009313
*/

#include <stdio.h>
#include <stdlib.h>

#define max_length_name 30

typedef struct job {
  char customer_name [max_length_name];
  int complete_time;
  int job_importance;
  double factor_order;
} Job;

Job * order_jobs (Job *jobs, int jobs_size){
  for (int id_job = 0; id_job < jobs_size; id_job++) {
    int j = id_job;
    int smallest_factor_order = id_job;
    while (j < jobs_size) {
      if(jobs[j].factor_order > jobs[smallest_factor_order].factor_order){
        smallest_factor_order = j;
      }
      j++;
    }

    Job aux_job = jobs[id_job];
    jobs[id_job] = jobs[smallest_factor_order];
    jobs[smallest_factor_order] = aux_job;
  }

  return jobs;
}
void show_jobs(Job *jobs, int jobs_size) {
  for (int id_job = 0; id_job < jobs_size; id_job++) {
    printf("%s\n", jobs[id_job].customer_name);
  }
}

int main () {
  printf("Digite o numero de tarefas: ");
  int jobs_size = 0;
  scanf ("%d", &jobs_size);

  Job *jobs = (Job*) malloc (jobs_size * sizeof (Job));

  for (int id_job = 0; id_job < jobs_size; id_job++) {
    printf("Tarefa %2d\n", id_job+1);

    printf("Digite o nome do cliente %d: ", id_job+1);
    scanf("%s", jobs[id_job].customer_name);

    printf("Digite o tempo que a tarefa leva para terminar: ");
    scanf("%d", &jobs[id_job].complete_time);

    printf("Digite a importancia da tarefa: ");
    scanf("%d", &jobs[id_job].job_importance);

    jobs[id_job].factor_order = jobs[id_job].job_importance / jobs[id_job].complete_time;
    printf("\n\n\n\n");
  }

  jobs = order_jobs(jobs, jobs_size);

  printf("Schedule ideal: \n");
  show_jobs(jobs, jobs_size);
  return 0;
}
