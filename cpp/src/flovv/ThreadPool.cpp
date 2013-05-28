
#include <flovv/ThreadPool.hpp>

namespace flovv {
    
    
    // the constructor just launches some amount of workers
    ThreadPool::ThreadPool (size_t threads) : mStop(false)
    {
        for (size_t i = 0; i < threads; ++i) {
            mWorkers.push_back(std::thread(ThreadPoolWorker(*this)));
        }
    }
    
    // the destructor joins all threads
    ThreadPool::~ThreadPool ()
    {
        // stop all threads
        mStop = true;
        mConditionVariable.notify_all();
        
        // join them
        for (size_t i = 0; i < mWorkers.size(); ++i) {
            mWorkers[i].join();
        }
    }
    
    // add new work item to the pool
    template<class T>
    void
    ThreadPool::enqueue(T f)
    {
        // Critical section
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mTasks.push_back(std::function<void ()>(f));
        }
        
        // wake up one thread
        mConditionVariable.notify_one();
    }
}