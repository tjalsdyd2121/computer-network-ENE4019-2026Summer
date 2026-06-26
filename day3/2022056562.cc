#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

// Header ?     -> library or API
// API ?        -> application programming Interface
// Interface ?  -> 사용자가 내부구조/원리를 알지 못하더라도 사용할 수 있게 해줌.
// Library ?    -> API와 달리 standard함. / 이익창출 X.
// Header ?     -> C에서의 독자적인 Library의 이름
// unistd는 unix에서만 가능한 header
// ncurses는 따로 설치한 API
int
main(void)
{
  // main 은 어떤 언어던간에 모든 program들의 시작점. so called 시작함수
  return 0;
}