#ifndef DOCHEADER_H
#define DOCHEADER_H

#include <time.h>
#include "../include/utf8.h"
#include "../src/gsoap_autogenerated/soapStub.h"

namespace DePlaguarism{

    struct DocHeader {
        tm dateTime;
        size_t textName_len;
        size_t authorName_len;
        size_t authorGroup_len;
        size_t data_len;
        t__type type;
    };

}

#endif // DOCHEADER_H
