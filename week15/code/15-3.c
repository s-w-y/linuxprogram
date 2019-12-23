

void *watch_count(void *idp){
	int *my_id = idp;
	printf("Starting watch count() : thread %d\n", *my_id);
	pthread_mutex_look(&count_mutex);
	if(count<COUNT_LIMIT){
	pthread_cond_wait(&count_threshold_cv, &count_mutex);
	prinntf("watch_count() : thread %d Condition signal received.\n", my id);
	}
	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}
