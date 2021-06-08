ROOT = ../../
CC = gcc

EXENAME=

INCDIRS = -I$(ROOT)/tinylog/ -I./ -I../

SOURCES = $(ROOT)/tinylog/tinylog.c \
		  ./main.c

HEADERS = $(ROOT)/tinylog/tinylog.h

CFLAGS=--std=c99 \
	   -Wall     \
	   -Wpedantic \
	   -D_GNU_SOURCE \

all: tinylog-x86-debug  \
	 tinylog-x86-info   \
	 tinylog-x86-warn   \
	 tinylog-x86-error  \
	 tinylog-x86-default

tinylog-x86-debug: $(SOURCES) $(HEADERS)
	@$(CC) -DTINYLOG_LEVEL=TINYLOG_LEVEL_DEBUG $(CFLAGS) $(INCDIRS) $(SOURCES) -o $@

tinylog-x86-info: $(SOURCES) $(HEADERS)
	@$(CC) -DTINYLOG_LEVEL=TINYLOG_LEVEL_INFO $(CFLAGS) $(INCDIRS) $(SOURCES) -o $@

tinylog-x86-warn: $(SOURCES) $(HEADERS)
	@$(CC) -DTINYLOG_LEVEL=TINYLOG_LEVEL_WARN $(CFLAGS) $(INCDIRS) $(SOURCES) -o $@

tinylog-x86-error: $(SOURCES) $(HEADERS)
	@$(CC) -DTINYLOG_LEVEL=TINYLOG_LEVEL_ERROR $(CFLAGS) $(INCDIRS) $(SOURCES) -o $@

tinylog-x86-default: $(SOURCES) $(HEADERS)
	@$(CC) $(CFLAGS) $(INCDIRS) $(SOURCES) -o $@

clean:
	@rm -rf tinylog-x86-debug   \
		    tinylog-x86-info    \
			tinylog-x86-warn    \
			tinylog-x86-error   \
			tinylog-x86-default

