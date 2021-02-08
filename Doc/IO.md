# I/O文件操作

## 主要功能

- 支持基本文件操作，包括`fopen(), fread(), fwrite(), fclose(), fseek()`
    - Windows下由`CreateFile(), ReadFile(), WriteFile(), CloseHandle(), SetFilePointer()`实现
    - Linux下内联汇编`open(), read(), write(), close(), seek()`实现
- 支持标准输入输出，包括`stdin`，`stdout`及`stderr`

## 待做功能

- 缓冲（Buffer）机制
- 对Windows下的换行机制进行转化，即`\r\n`和`\n`
- `fopen`区分二进制和文本模式，增加追加功能(`'a'`)

