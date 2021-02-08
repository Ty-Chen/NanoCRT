#include "../Include/NanoCRT.h"

int main(long argc, char *argv[])
{
    FILE*  fp  = NULL;
    char*  buf = "hello how are you \n";
    char*  tmp = NULL;
    long   len = strlen(buf);
      
    fp = fopen("test.txt", "w");

    fwrite(buf, 1, len, fp);
    printf("hello world\n");
    printf("%d\n%s\n", len, buf);

    fclose(fp);
    
    tmp = (char*) malloc(strlen(buf));
    if (tmp == NULL)
    {
    	return -1;
    }
    
    tmp = strcpy(tmp, buf);  
    printf("%s\n", tmp);
    
    free(tmp);
    
    return 0;
}
