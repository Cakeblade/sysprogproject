# My String in C
<hr>

## Abstract
C의 string.h에서 지원하지 않는 기능 일부를 구현한 라이브러리

## Description
### Library function - mstr.h
- isNumber(const char*)
  - 입력된 text가 숫자인지 확인하는 함수
- hasCapital(const char*)
  - 입력된 text 내에 영어 대문자가 있는지 확인하는 함수
- hasLetter(const char*)
  - 입력된 text 내에 영어 소문자가 있는지 확인하는 함수

### Files
- main.c
  - 라이브러리 테스트 용 실행 파일 소스 코드
- runtime.c
  - runtime-linking 테스트 용 실행 파일 소스 코드
- mstr.h / mstr.c / mstr.o
  - 라이브러리 구현용 헤더, 소스 코드, object 파일
- libtest_(static / shared / runtime)
  - static library, shared library, runtime linking 테스트 용 실행 파일
- libmstr.a
  - static library
- libmstr.so
  - shared library
- Makefile
  - 실행파일 빌드

