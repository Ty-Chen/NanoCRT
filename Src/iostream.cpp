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

    ofstream& ofstream::operator<<(char c)
    {
        fputc(c, fp);
        return *this;
    }

    ofstream& ofstream::operator<<(int n)
    {
        fprintf(fp, "%d", n);
        return *this;
    }

    ofstream& ofstream::operator<<(const char* str)
    {
        fprintf(fp, "%s", str);
    }

    ofstream& ofstream::operator<<(ofstream& (*manip)(ofstream&))
    {
        return manip(*this);
    }

    void ofstream::open(const char* fileName, ofstream::openmode md)
    {
        char mode[4];

        close();
        switch (md)
        {
        case std::ofstream::out | trunc:
            strcpy(mode, "w");
            break;
        case std::ofstream::out | in | trunc:
            strcpy(mode, "w+");
            break;
        case std::ofstream::out | trunc | binary:
            strcpy(mode, "wb");
            break;
        case std::ofstream::out | in | trunc | binary:
            strcpy(mode, "wb+");
            break;
        default:
            break;
        }
        fp = open(fileName, mode);
    }

    void ofstream::close()
    {
        if (fp)
        {
            fclose(fp);
            fp = 0;
        }
    }

    ofstream& ofstream::write(const char* buf, unsigned size)
    {
        fwrite(buf, 1, size, fp);
        return *this;
    }
}