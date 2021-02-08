# NanoCRT

一个简易的跨平台64位运行时库，兼容Linux和Windows。

## 文件结构

- Include：运行时库头文件
- Src：源码
- Test：测试用例

## 使用方式

### window (手动编译链接)

```shell
编译库
>cl /c /DWIN32 /GS- Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c
>lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:nanocrt.lib

编译测试用例
>cl /c /DWIN32 Test/test.c
>link test.obj nanocrt.lib kernel32.lib /NODEFAULTLIB /entry:nano_crt_entry
```

### linux (手动编译链接)

```shell
# 编译库
# gcc -c -fno-builtin -nostdlib Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c
# ar -rs nanocrt.a malloc.o printf.o stdio.o string.o
#
# 编译测试用例
# gcc -c -ggdb -fno-builtin -nostdlib Test/test.c
# ld -static -e nano_crt_entry entry.o test.o nanocrt.a -o test
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

- #### [I/O与文件操作](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/IO.md)

- #### [字符串操作](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/string.md)

- #### [格式化字符串](https://github.com/Ty-Chen/NanoCRT/blob/main/Doc/printf.md)

