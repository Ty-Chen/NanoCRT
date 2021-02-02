# NanoCRT

一个简易的跨平台64位CRT，兼容Linux和Windows。

## 使用方式

### window (手动编译链接)

```
>cl /c /DWIN32 /GS- Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c

>lib entry.obj malloc.obj printf.obj stdio.obj string.obj /OUT:minicrt.lib
>cl /c /DWIN32 test.c
>link test.obj minicrt.lib kernel32.lib /NODEFAULTLIB /entry:mini_crt_entry
```

### linux (手动编译链接)

```
# gcc -c -fno-builtin -nostdlib Src/entry.c Src/malloc.c Src/stdio.c Src/string.c Src/printf.c
# ar -rs nanocrt.a malloc.o printf.o stdio.o string.o
# gcc -c -ggdb -fno-builtin -nostdlib Test/test.c
# ld -static -e nano_crt_entry entry.o test.o nanocrt.a -o test
```

#### linux (make)

```
make
./test
make clean
```

## 主要功能

## 待做功能
