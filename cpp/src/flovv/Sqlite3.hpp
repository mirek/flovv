//
// The MIT License
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

#ifndef __FLOVV_SQLITE3_HPP__
#define __FLOVV_SQLITE3_HPP__ 1

#include <iterator>
#include <sqlite3.h>

namespace flovv {
    
    class Sqlite3 {
        
        sqlite3 *mConnection;
        int mLastReturnValue;
        
    public:
        
        Sqlite3 (sqlite3 *connection = nullptr)
        {
            mConnection = connection;
        }
        
        Sqlite3 (const std::string &name = "")
        {
            if (name == "") {
//                sqlite3_
                
            }
        }

        bool
        connect (const std::string &name) {
            mLastReturnValue = sqlite3_open_v2 ();
        }
        
        void
        disconnect () {
        }

        Iterator
        select (const std::string &sql) {
            
        }
        
        Row
        first (const std::string &sql) {
            
        }
        
    };
    
    class Sqlite3Iterator :: std::iterator {
    public:
        
    }

}

#endif
