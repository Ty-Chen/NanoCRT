#include "../Include/NanoCRT.h"

int main(long argc, char *argv[])
{
    long i;
    FILE* fp;

    fp = fopen("test.txt", "w");

    //
    {
        char* buf = "hello how are you \n";
        long len = strlen(buf);
        fwrite(buf, 1, len, fp);
        //fwrite(0, "c", 1);
        printf("hello world\n");
        printf("%d  %s\n", len, buf);
    }

    fclose(fp);

    return 0;
}