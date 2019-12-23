#include "my.h"

pthread_mutex_t g_mutex;
pthread_cond_t g_cond, c_cond;

int buffer = 3;


void *worker1(void *ptr)
{
    int i;
    for(i=0; i<=5; i++)
    {
        pthread_mutex_lock(&g_mutex); 

        while(buffer !=0) pthread_cond_wait(&g_cond, &g_mutex);
        printf("woker1 produce item %d\n",i);
        buffer = i;
        pthread_cond_signal(&g_cond);
        pthread_mutex_unlock(&g_mutex);
    }
    
    pthread_exit(0);

}

void *consumer(void *ptr)
{

    int i;
    for(i=0; i<=5; i++)
    {
        pthread_mutex_lock(&g_mutex);
        while(buffer ==0) pthread_cond_wait(&c_cond, &g_mutex);
        printf("consumer consume item %d\n",i);
        buffer = 0;
        pthread_cond_signal(&c_cond);
        pthread_mutex_unlock(&g_mutex);
    }
    pthread_exit(0);

}

int main(int argc, char *argv[])
{
    pthread_t w1, con;
    pthread_mutex_init(&g_mutex, 0);
    pthread_cond_init(&g_cond,0);
    pthread_cond_init(&c_cond,0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&w1, 0, worker1, 0);
    pthread_join(w1,0);
    pthread_join(con,0);
    pthread_cond_destroy(&g_cond);	
    pthread_cond_destroy(&c_cond);
    pthread_mutex_destroy(&g_mutex);
    return 0;    
}
