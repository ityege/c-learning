#include <iostream>
#include <fcntl.h>  //open
#include <unistd.h> //close
#include <errno.h>  //errno

int main()
{
    int fd, openFlags;
    mode_t filePerms;

    // 设置 openFlags 变量为三个标志的按位或操作结果。
    // O_CREAT 表示如果文件不存在则创建文件，
    // O_WRONLY 表示以只写方式打开文件，
    // O_TRUNC 表示在打开文件时截断文件内容。
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    // 设置 filePerms 变量为六个权限模式的按位或操作结果。
    // S_IRUSR 表示用户可读权限，
    // S_IWUSR 表示用户可写权限，
    // S_IRGRP 表示组可读权限，
    // S_IWGRP 表示组可写权限，
    // S_IROTH 表示其他用户可读权限，
    // S_IWOTH 表示其他用户可写权限。
    // 这样的权限模式 rw-rw-rw- 表示文件对所有用户都具有读写权限。
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH; /* rw-rw-rw- */
    fd = open("file.txt", openFlags, filePerms);
    if (fd == -1)
    {
        // 打印错误消息和错误代码描述
        printf("Error code: %d\n", errno);
    }
    std::cout << "这里进行业务逻辑操作" << std::endl;
    // 关闭文件
    close(fd);
    return 0;
}