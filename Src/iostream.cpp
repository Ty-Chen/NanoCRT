#include "../Include/NanoCRT.h"
#include "iostream"

#ifdef WIN32
#include <Windows.h>
#endif

namespace std
{
    stdout_stream::stdout_stream() : ofstream()
    {
        fp = stdout;
    }

    stdout_stream cout;

    ofstream::ofstream() : fp(0)
    {
    }

    ofstream::ofstream(const char* fileName, ofstream::openmode md) : fp(0)
    {
        open(fileName, md);
    }

    ofstream::~ofstream()
    {
        close();
    }


}