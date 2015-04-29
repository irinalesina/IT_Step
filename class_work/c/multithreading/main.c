#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>  //многопроцессорность
#include <pthread.h>  //для  многопоточности


/*
разбиение на процессы
int main()
{
    int i = 0;
    for( ; i < 10; i++)
    {
        printf("%d\n", i);
    }
    fork();
  13	74  for( ; i < 50; i++)
    {
        printf("%d\n", i);
        sched_yield();//разбивает на потоки
    }
    return 0;
}
*/

/*
убить систему
int main()
{
    fork();
    main();
    return 0;
}
*/


/*
//создание потока
void *run(void *args);

int main(int argc, char **argv)
{
    //int pthread_create(pthread_t *tid, void *attributes, void *(*thread_func)(void*), void *arg);
    //tid - идентификатор нового потока
    //attributes - атрибуты(если 0-то будут по умолчанию)
    //-//- - ф-я для р-ты с потоком
    //arg - аргументы потока(0, если не нужно указывать)

    pthread_t tid;
    int arg, result;

    if(argc < 2)
    {
        fprintf(stderr, "Error, you loser!\n");
        return 1;
    }

    arg = atoi(argv[1]);
    result = pthread_create(&tid, NULL, run, &arg);
    if(result)
    {
        fprintf(stderr, "Error! %d\n", result);
        return 1;
    }
    fprintf(stdout, "Goodbye world\n");
    while(1);

    return 0;
}


void *run(void *args)
{
    int a = *(int *)args;

    usleep(500000);
    fprintf(stderr, "Hello world! >> %d\n", a);

    //stdout - записать в консоль

    return NULL;
}
*/


//2 потока
void *run(void *arg);
int main()
{
    pthread_t tid_1, tid_2; //, tid_3, tid_4, tid_5, tid_6, tid_7;
    int arg = 0, result_1, result_2; //, result_3, result_4, result_5, result_6, result_7;

    result_1 = pthread_create(&tid_1, NULL, run, &arg);
    result_2 = pthread_create(&tid_2, NULL, run, &arg);
    /*result_3 = pthread_create(&tid_3, NULL, run, &arg);
    result_4 = pthread_create(&tid_4, NULL, run, &arg);
    result_5 = pthread_create(&tid_5, NULL, run, &arg);
    result_6 = pthread_create(&tid_6, NULL, run, &arg);
    result_7 = pthread_create(&tid_7, NULL, run, &arg);*/
    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);


    while(1);

    return 0;
}


void *run(void *arg)
{
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        fprintf(stderr, "%d\n", i);
        sched_yield();
    }
    return NULL;
}













