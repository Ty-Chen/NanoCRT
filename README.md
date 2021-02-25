# NanoCRT

一个简易的跨平台64位C/C++运行时库，兼容Linux和Windows。

## 文件结构

- Include：运行时库头文件
- Src：源码
- Test：测试用例

## 使用方式

### window (手动编译链接)

#### 编译命令

```shell
编译C库
>cl /c /DWIN32 /GS- Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c Src/atexit.c
>lib entry.obj malloc.obj printf.obj stdio.obj string.obj atexit.obj /OUT:nanocrt.lib

编译C/C++库
>cl /c /DWIN32 /GS- Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c
>cl /c /DWIN32 /GS- /GR- Src/crtbegin.cpp Src/crtend.cpp Src/ctor.cpp Src/new_delete.cpp Src/iostream.cpp
>lib entry.obj malloc.obj printf.obj stdio.obj string.obj ctor.obj new_delete.obj atexit.obj iostream.obj /OUT:nanocrt.lib

编译C测试用例
>cl /c /DWIN32 Test/test.c
>link test.obj nanocrt.lib kernel32.lib /NODEFAULTLIB /entry:nano_crt_entry

编译C++测试用例
>cl /c /DWIN32 Test/test2.cpp
>link test2.obj nanocrt.lib kernel32.lib /NODEFAULTLIB /entry:nano_crt_entry

```

#### 参数说明

- `/DWIN32`表示定义宏WIN32，用以区分平台
- `/GS-`表示关闭堆栈保护功能，最新版gcc会在变长参数函数中加入堆栈保护功能（如`vprintf()`）

### linux (手动编译链接)

```shell
# 编译C库
# gcc -c -fno-builtin -nostdlib Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c Src/atexit.c
# ar -rs nanocrt.a malloc.o printf.o stdio.o string.o atexit.o

# 编译C++库
# gcc -c -fno-builtin -nostdlib -fno-stack-protector Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c Src/atexit.c
# g++ -c -nostdinc++ -fno-rtti -fno-exceptions -fno-builtin -nostdlib -fno-stack-protector Src/crtbegin.cpp Src/crtend.cpp Src/ctor.cpp Src/new_delete.cpp Src/iostream.cpp
# ar -rs nanocrt.a entry.obj malloc.obj printf.obj stdio.obj string.obj ctor.obj new_delete.obj atexit.obj iostream.obj

# 编译C测试用例
# gcc -c -ggdb -fno-builtin -nostdlib Test/test.c
# ld -static -e nano_crt_entry entry.o test.o nanocrt.a -o test

# 编译C++测试用例
# g++ -c -nostdinc++ -fno-rtti -fno-exceptions -fno-builtin -nostdlib -fno-stack-protector Test/test2.cpp
# ld -static -e nano_crt_entry entry.o crtbegin.o test2.o nanocrt.a crtend.o -o test2
```

### linux (make)

```shell
# 编译全部/库/测试用例，默认全部编译
make (all/lib/test)

# 清理
make clean
```

## 主要功能及待做功能

- #### [入口、初始化及结束功能](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/entry.md)

- #### [内存分配（堆）](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/malloc.md)

- #### [I/O文件操作](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/IO.md)

- #### [字符串操作](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/string.md)

- #### [格式化字符串](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/printf.md)

