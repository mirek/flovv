//
// Released under the MIT License.
//
// Copyright (c) 2012 - 2013, Mirek Rusin <mirek [at] me [dot] com>
// http://flovv.org
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#ifndef __FLOVV_THREAD_POOL_HPP__
#define __FLOVV_THREAD_POOL_HPP__ 1

#include <vector>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>

#include <flovv/ThreadPoolWorker.hpp>

namespace flovv {
    
    /// Thread pool
    ///
    class ThreadPool {
    public:
        
        ThreadPool (size_t threadCount);
        ~ThreadPool ();

        template <class T>
        void enqueue (T f);
        

    private:
        
        friend class ThreadPoolWorker;
        
        // need to keep track of threads so we can join them
        std::vector< std::thread > mWorkers;
        
        // the task queue
        std::deque< std::function<void()> > mTasks;
        
        // synchronization
        std::mutex mMutex;
        std::condition_variable mConditionVariable;
        bool mStop;
    };
    
}

#endif
