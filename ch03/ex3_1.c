// 파일명으로 inode 정보 검색하기
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void){
        struct stat buf;

        stat("unix.txt", &buf);

        printf("Inode = %d\n", (int)buf.st_ino);    //inode 번호
        printf("Mode = %o\n", (unsigned int)buf.st_mode);   //파일의 형식과 접근 권한
        printf("Nlink = %o\n", (unsigned int)buf.st_nlink); //하드 링크의 개수
        printf("UID = %d\n", (int)buf.st_uid);  // 소유자의 UID
        printf("GID = %d\n", (int)buf.st_gid);  // 소유 그룹의 GID
        printf("SIZE = %d\n", (int)buf.st_size);    // 크기
        printf("Atime = %d\n", (int)buf.st_atime);  // 마지막으로 파일에 접근한 시간
        printf("Mtime = %d\n", (int)buf.st_mtime);  // 마지막으로 파일의 내용을 변경한 시간
        printf("Ctime = %d\n", (int)buf.st_ctime);  // 마지막으로 inode의 내용을 변경한 시간
        printf("Blksize = %d\n", (int)buf.st_blksize);  // 입출력 버퍼 크기
        printf("Blocks = %d\n", (int)buf.st_blocks);    // 512바이트로 나눈 블록 개수
        printf("FStype = %s\n", buf.st_fstype); // 파일시스템 종류 정보

        return 0;
}
