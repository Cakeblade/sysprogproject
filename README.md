# My String in C
<hr>

## Abstract
C의 string.h에서 지원하지 않는 기능 일부를 구현한 라이브러리

## Description
### Library function - mstr.h
- isNumber(const char*)
  - 입력된 text가 숫자인지 확인하는 함수, 문자가 같이 있으면 0을 return
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

## Examples
- static, hasCapital

![image](https://github.com/user-attachments/assets/18ec0d62-5b7a-4207-9c3c-d275f6566ad9)

- shared, hasLetter

![image](https://github.com/user-attachments/assets/b8513b37-6843-4798-ad4b-65b7aac4dcf4)

- runtime, isNumber

![image](https://github.com/user-attachments/assets/9059565e-550b-4824-983e-0c8b412cd2e0)
