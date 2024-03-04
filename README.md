# pentabong
Game Server Framework with Modern C++ &amp; Boost
# Summary
Game Server Framework with Modern C++ &amp; Boost


# Module
 - Pentabong (like daemon, service ...)
	 - Senbong (base framework)
		 - Network
		 - Scheduler
		 - DB
		 - Log
		 - File system
		 - Console
	 - Nobong
	 - Sacbong
	 - Jitbong
	 - Nanbong
		 - Test
		 - Unit Test

# Directory Path

 - pentabong
	 - framework
		 - senbong
			 - source
			 - include
		 - Nanbong
			 - source
			 - include
	 - external
		 - boost
			 - 1.0.0.1
				 - include
				 - lib
	 - server
		 - etc
	 - source
	 - bin
		 - config
	 - log
	 - lib

# Coding Convention

clang, clang-format

# R&R

 - cmake 구성
 - library 빌드 후 external에 추가
- pentabong main.cpp 빌드 hello world
# External Libraries

 - protobuf
 - boost asio
 - STL c++20

# Convention
 - 파일 및 디렉토리(폴더)의 이름에는 `-` 대신 `_`를 쓴다. 변수 명에는 `_`를 사용한다.
 - Enum의 0은 None을 넣어준다. 초기화 되지 않은 상태를 확인 하기 위해서 사용한다.
