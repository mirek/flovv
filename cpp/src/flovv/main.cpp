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

#include <iostream>

#include <vector>
#include <map>
#include <memory>
//#include <tuple>

//#include <boost/smart_ptr.hpp>
//#include <boost/weak_ptr.hpp>
#include <boost/any.hpp>

#include <stdint.h>
#include <iostream>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
//#include <boost/archive/binary_iarchive.hpp>

#include <boost/lexical_cast.hpp>
#include <typeinfo>

#include <flovv/flovv.hpp>
#include <flovv/type.hpp>

using namespace std;
using namespace boost;

using namespace flovv;

//using std::string;
//using std::int32_t;
//
//using boost::any;
//using boost::any_cast;

//class lexical_convertion {
//public:
//    template <typename T>
//};

//class node_info {
//public:
//
//    std::string id_name;
//
//
//};

#include <flovv/Log.hpp>

int
main (void) {

//	flovv::param p;

    Engine engine("test.flovv");
    Node *randomNode = engine.createNode("Random");
    Node *printerNode = engine.createNode("Printer");
    engine.connect(*randomNode, *printerNode);

    (*randomNode)();
    (*printerNode)();
//
//    randomNode();
//    printerNode();
    
//    while (e.running()) {
//        e.update();
//    }

//    while (true) {
//        e.update();
//    }

//    for (int i = 0; i < 10; i++) {
//        e.node(random)();
//        std::cout << e.node(random).output().load<std::int64_t>() << std::endl;
//    }
}

