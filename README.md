##  Philosophers 

The philosephers are the threads, the forks are the mutexes.
When I am having a big heated discussion at work, I use a rubber chicken which I keep in my desk for just such occasions. The person holding the chicken is the only person who is allowed to talk. If you don't hold the chicken you cannot speak. You can only indicate that you want the chicken and wait until you get it before you speak. Once you have finished speaking, you can hand the chicken back to the moderator who will hand it to the next person to speak. This ensures that people do not speak over each other, and also have their own space to talk.

The function used in the code are:
- memset:
    void *memset(void *buf, int c, size_t len);
    Memset writes len bytes of value c (converted to an unsigned char) to the string buf. The void *buf points to the location in the string where you start to write. The function returns its first argument(void *buf)
- malloc:
    void *malloc(size_t size);
    Malloc allocates size bytes of memory and returns a pointer to the allocated memory. If the allocation fails, it returns NULL. The allocated memory is aligned such that is can be used for any data type. 
- free:
    void free(void *ptr);
    The free function frees the allocated memory. It returns nothing. 
- write:
    ssize_t write(int fd, const void *buf, size_t nbyte);
    Write tries to write nbyte of data to the object referenced by the file descriptor(fd). Upon succesful completion the number of bytes which were written are returned, otherwise a -1 and errno is set to indicate the error.
- usleep:
    int usleep(useconds_t microseconds);
    This function suspends execution of the calling thread until either the microseconds have elapsed or a signal is deliverd to the thread and it action is to invoke a signal-catching function or to terminate the process.
- gettimeofday:
    int gettimeofday(struct timeval *restrict tp, void *restrict tzp);
    Gives the system's notion of the current Greenwich time.
    truct timeval: 
    {
        time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
        suseconds_t  tv_usec;  /* and microseconds */
    };
    The function returns a 0 when the call succeeded, a -1 is returned when an error occured and the errno is set to indicate the error. 
    Depending on whether tp or tzp is NULL, one of the structs is populated with the timezone struct.

A thread is a single sequence stream within in a process. Threads have some of the properties of processes. But threads are not independent of one other like processes, as a result threads share with other threads their code section, data section and OS resources like open files and signals. But, like processes, a thread had its own program counter, a register and a stack space. 
- pthread_create: 
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
    void *(*start_routine)(void *), void *arg);
    This function is used to create a new thread, with attributes specified bij attr, within a process. Upon succesful completion this function will store the ID of the created thread in the location specified by thread. Upon succes the function will return 0, otherwise an error number will be returned.
    - thread: pointer to an unsigned integer value that returns the thread id of the thread created.
    - attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy en stack address. If attr is NULL, the default attributes are used.
    - start_routine: pointer to a subroutine that is executed by the thread. The thread is creating  by executing start_routin with args as its sole argument.
- pthread_detach: 
    int pthread_detach(pthread_t thread);
    This function marks the thread identified by thread as detached. When a detached thread terminates, its recources are automatically released back to the system without the need for another thread to join with the terminated thread. By default all threads are joinable, so to make a thread detach we need to call this function. 
- pthread_join:
    int pthread_join(pthread_t thread, void **value_ptr);
    This function waits for the thread speciied by thread to terminate. If it is already terminated, then the function returns immediately. The thread specified by thread must be joinable. If value_ptr is not NULL, then pthread_join copies the exit status of the target thread into the location pointed to by value_ptr
- pthread_mutex_init:
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    This function creates a new mutex, with attributes specified by attr. If attr is NULL, the default attributes are used. Upon succes, the function returns zero and it puts the new mutex ID into mutex(first argument), otherwise an error number will be returned.
- pthread_mutex_destroy:
    int pthread_mutex_destroy(pthread_mutex_t *mutex);
    This function frees the resource allocated for mutex. Upon succes it will return zero, otherwise an aerror number will be returned.
- pthread_mutex_lock:
    int pthread_mutex_lock(pthread_mutex_t *mutex);
    This funciton lox the mutex. If the mutex is already locked, the calling thread will block until the mutex comes available. Upon succes it will return zero, otherwise an aerror number will be returned.
- pthread_mutex_unlock:
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    If the current thread holds the lock on mutex, then this function unlocks mutex.Upon succes it will return zero, otherwise an aerror number will be returned.