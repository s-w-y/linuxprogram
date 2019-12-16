#include"my.h"
pthread_rwlock_t rwloct;
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
//mutex= PTHREAD_MUTEX_INITIALIZER;
int g = 0;
void *fun(void *param)
{
	int i;
	pthread_rwlock_rdlock(&relock);
	for(i = 0;i<LOOP;i++)
	{
		pthread_mutex_lock(&mutex);
		g++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&relock);
	return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int i, ret;

	ret = pthread_relock_init(&reloct,NULL);

	if(ret)
	{
		perror("lock init failed!\n");
		exit(1);
	}
	pthread_relock_init(&rwlock);
	for(i=0;i<NUM;i++)
	{
		ret=pthread_create(&tid[i], NULL, fun, NULL);
		if(ret != 0)
		{
			perror("thread crete failed!\n");
			exit(2);
		}
	}
	pthread_relock_init(&rwlock);
	for(i=0;i<NUM;i++)
	{
		pthread_join(tid[i], NULL);
		pthread_relock_destory(&relock);
		printf("thread num			:%d\n", NUM);
		printf("loops per thread	:%d\n", NUM);
		printf("except result		:%d\n", NUM);
		printf("actual result		:%d\n", NUM);
		return 0;
	}
}
