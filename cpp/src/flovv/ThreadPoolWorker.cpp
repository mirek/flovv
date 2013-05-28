
#include <flovv/ThreadPoolWorker.hpp>

namespace flovv
{
    void
    ThreadPoolWorker::operator() ()
    {
        std::function<void()> task;
        while (true) {
            
            // Critical section
            {
                std::unique_lock<std::mutex> lock(mThreadPool.mMutex);
                
                // look for a work item
                while (!mThreadPool.mStop && mThreadPool.mTasks.empty()) {
                    
                    // if there are none wait for notification
                    mThreadPool.mConditionVariable.wait(lock);
                }
                
                // exit if the pool is stopped
                if (mThreadPool.mStop) {
                    break;
                }
                
                // get the task from the queue
                task = mThreadPool.mTasks.front();
                mThreadPool.mTasks.pop_front();
            }
            
            // Execute outside of critical section
            // TODO: Catch exception
            task();
        }
    }
}
