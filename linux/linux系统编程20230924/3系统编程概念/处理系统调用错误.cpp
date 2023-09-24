#include <stdio.h>  //perror
#include <errno.h>  //errno
#include <fcntl.h>  //fopen
#include <string.h> //strerror
int main()
{

    int fd;
    char buffer[1024];

    // 尝试打开一个不存在的文件
    fd = open("nonexistent_file.txt", O_RDONLY);
    if (fd == -1)
    {
        // 打印错误消息和错误代码描述
        perror("Failed to open the file");              // Failed to open the file: No such file or directory
        printf("Error code: %d\n", errno);              // Error code: 2
        printf("Error message: %s\n", strerror(errno)); // Error message: No such file or directory
        return -1;
    }

    return 0;
}