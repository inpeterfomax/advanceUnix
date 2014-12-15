#include<stdlib.h>
#include<pthread.h>

struct job{
    struct  job* j_next;
	struct  job* j_prev;
	pthread_t j_id;
}

struct queue{
    struct job *q_head;
	struct job *q_tail;
	pthread_rwlock_t q_lock;
}


int queue_init(struct queue *qb){
    int err;
	qb->q_head = NULL;
	qb->q_tail = NULL;
	
	err = pthread_rwlock_init(&qb->q_lock,NULL);
	if(err != 0)
			return err;
 
    return 0;
}

/*
  inset the job to queue head
*/
void job_insert(struct queue *qb, struct job *job){
		pthread_rwlock_wrlock(&qb->q_lock);

		job->j_next = qb->q_head;
		job->j_prev = NULL;

		if(qb->q_head != NULL)
				qb->q_head->j_prev = job;
		else
				qb->q_tail = job;

		qb->q_head = job;

		pthread_rwlock_unlock(&qb->lock);
}

/*
* append the job to queue tail
*/
void job_append(struct queue  *qb,struct job *job)
{
	pthread_rwlock_wrlock(&qb->q_lock);	
     job->j_next = NULL;
	 job->j_prev = qb->q_tail;

	 if(qb->q_tail != NULL)
			 qb->q_tail->j_next = job;
	 else
			 qb->q_head = job;
      qb->q_tail = job;
     pthread_rwlock_unlock(&qb->q_lock);
}


void job_remove(struct queue *qb , struct job *job)
{
        pthread_rwlock_wrlock(&qb->q_lock);
        if(job == qb->q_head){
              qb->q_head = job->j_next;
			  if(job == qb->q_tail)
					  qb->q_tail =NULL;
		}else if(job == qb->q_tail){
			qb->q_tail = job->j_prev;
			if(job == qb->q_head)
					qb->q_head = NULL;
		}else{
		   job->j_prev->j_next  = job->j_next;		
           job->j_next->j_prev = job->j_prev;
		}
		pthread_rwlock_wrlock(&qb->q_lock);

}


struct job* job_find(struct queue *qb,pthread_t id)
{
    struct job *jb;

	if(pthread_rwlock_rdlock(&qb->q_lock) != 0)
           return NULL;

	for(jb=qb->q_head;jb != NULL;jp = jb->j_next)
			if(pthread_equal(jb->j_id,id))
					break;
	pthread_rwlock_unlock(&qb->q_lock);

	return jb;

}

void main(void){
   struct queue *qb;
   queue_init(qb);

   pid_t pid[10];
   int i;
   for(i=0;i<10;i++){
       pthread_create(&pid[i],NULL,);


   }



}
