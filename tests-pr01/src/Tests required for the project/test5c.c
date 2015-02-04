/*
  Test 5c
  Enrique Saurez :)
  esaurez@gatech.edu
  Copyright (C) 2015  
*/

#include <stdio.h>
#include <gtthread.h>

#define NUM_THREADS 100

gtthread_mutex_t g_mutex;
int g_num = 0;

void* worker(void* arg)
{
	int i,j=0;
	while(j < 5){
		gtthread_mutex_lock(&g_mutex);
		printf("Mutex Lock obtained by: %lu\n", gtthread_self());
		gtthread_mutex_unlock(&g_mutex);
		for(i=0;i<99999999;++i);
		++j;
	}	
    return NULL;
}

int main()
{
	printf("Each threads should write five times, interleaved\n");
	gtthread_t th1;
	gtthread_init(1000);
	gtthread_mutex_init(&g_mutex);
	gtthread_mutex_lock(&g_mutex);
	gtthread_create(&th1, worker, NULL);
	printf("Hello is main!\n");
	gtthread_mutex_unlock(&g_mutex);
	gtthread_join(th1, NULL);
	return 0;
}
