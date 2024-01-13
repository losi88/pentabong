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
