class ThreadPool
{

private:
    std::queue<Task*> taskQueue;   //任务队列
    bool isRunning;           //线程池运行标志
    
    pthread_t* pThreadSet;  //指向线程id集合的指针
    int threadsNum;         //线程数目
    pthread_mutex_t mutex;    //互斥锁
    pthread_cond_t condition;   //条件变量

    //单例模式，保证全局线程池只有一个
    ThreadPool(int num=10);
    void createThreads();  //创建xianchen池
    void clearThreads();  //回收线程
    void clearQueue();  //清空任务队列

    static void* threadFunc(void* arg);
    Task* takeTask();  //工作线程获取任务

public:
    void addTask(Task* pTask);   //任务入队
    static ThreadPool* createThreadPool(int num=10); //静态方法，用于创建线程池实例
    ~ThreadPool();
    int getQueueSize(); //获取任务队列中的任务数目
    int getThreadlNum();  //获取线程池中线程总数目
};
