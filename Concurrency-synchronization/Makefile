.PHONY: all clean
#获取当前工作路径
# https://blog.csdn.net/javababy3/article/details/77918228
TOP_DIR:=$(CURDIR)

# 设置编译目录
BUILD_PATH:=$(TOP_DIR)/build

CC:=gcc
CPP:=g++
OBJ= cas_test hello stack-probe alipay sum store-load peterson sum-atomic counter sem_test


CCFLAGS:=-g -Wall -ggdb 

CPPFLAGS:=-g -Wall -std=c++11 -pthread

all: $(OBJ)



cas_test: cas_test.cpp 
	$(CPP) $(CPPFLAGS) -o $(BUILD_PATH)/$@ $^

hello: hello.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^ 

stack-probe: stack-probe.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^ 

alipay: alipay.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^

sum: sum.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^

store-load: store-load.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^

peterson: peterson.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^

sum-atomic: sum-atomic.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^
counter: counter.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^
	
sem_test: sem_test.c
	$(CC) $(CCFLAGS) -o $(BUILD_PATH)/$@ $^
$(BUILD_PATH):
	mkdir $(BUILD_PATH)
clean:
	rm -rf $(BUILD_PATH)/$(OBJ)
