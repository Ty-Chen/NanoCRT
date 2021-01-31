# NanoCRT

一个简易的跨平台64位CRT，兼容Linux和Windows。

## 使用方式

### window (手动编译链接)

```
>cl /c /DWIN32 /GS- entry.c malloc.c printf.c stdio.c string.c

>lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:minicrt.lib
>cl /c /DWIN32 test.c
>link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry
```

### linux (手动编译链接)

```
# gcc -c -fno-builtin -nostdlib  entry.c malloc.c stdio.c string.c printf.c
# ar -rs minicrt.a malloc.o printf.o stdio.o string.o
# gcc -c -ggdb -fno-builtin -nostdlib test.c
# ld -static -e mini_crt_entry entry.o test.o minicrt.a -o test
```

#### linux (make)

```
make
./test
make clean
```

## 主要功能

## 待做功能
