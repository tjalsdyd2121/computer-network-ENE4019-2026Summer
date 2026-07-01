// 표준 헤더 : OS 관계 없이 사용가능.
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 리눅스용 헤더
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFSIZE     1024
#define MAX_CLIENT  64

int clnt_socks[MAX_CLIENT];
int clny_id = 0;

void error_handling(const char* message){
  fputs(message, stderr);
  fputs("\n", stderr);
  exit(-1);
}

int
main(int argc, char* argv[])
{
  return 0;
}