//entry.c
#include "../Include/NanoCRT.h"

#ifdef WIN32
#include <Windows.h>
#endif

extern int main(long agrc, char *argv[]);
void exit(long);

static void crt_fatal_error(const char *msg)
{
    //printf("fatal error : %s",msg);
    exit(1);
}

// 入口函数
void nano_crt_entry(void)
{
    long ret;

#ifdef WIN32
    long flag = 0;
    long argc = 0;
    char* argv[16];
    char* cl = GetCommandLineA();

    argv[0] = cl;
    argc++;
    while (*cl)
    {
        if (*cl == '\"')
        {
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 1;
            }
        }
        else if (*cl == ' ' && flag == 0)
        {
            if (*(cl + 1))
            {
                argv[argc] = cl + 1;
                argc++;
            }
            *cl = '\0';
        }
        cl++;
    }
#else
    long argc;
    char** argv;
    char* rbp_reg = 0;
    //ebp_reg = %ebp
    asm("movq %%rbp,%0 \n":"=r"(rbp_reg));

    argc = *(long*)(rbp_reg + 4);
    argv = (char**)(rbp_reg + 8);
#endif

    // 初始化
    if (!nano_crt_init_heap())
    {
        crt_fatal_error("heap initalize failed");
    }

    if (!nano_crt_init_io())
    {
        crt_fatal_error("IO initalize failed");
    }

    ret = main(argc, argv);

    // 结束部分
    exit(ret);
}

// 结束部分
void exit(long exitCode)
{
    //nano_crt_call_exit_routine();
#ifdef WIN32
    ExitProcess(exitCode);
#else
    asm("movq %0, %%rbx \n\t"
        "movq $1, %%rax \n\t"
        "int $0x80		\n\t"
        "hlt    \n\t"::"m"(exitCode));
#endif
}

