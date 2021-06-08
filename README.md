# Tinylog

Tinylog is a small C library for performing simple logging on resource
constrained embedded systems. The library is designed to be small, lightweight,
and extremely portble. It exposes no-overhead functions for logging at various
levels, formatted log messages, and filename/line number logging.

## Uage

```c
#include <tinylog.h>

int main() {
    tinylog_error("an error message");
    tinylog_warn("a warning message");
    tinylog_info("an info message");
    tinylog_debug("a debug message");

    tinylog_info("formatted messages: %d", -1);
}
```

You set the log level at compile time via a preprocessor macro:

```bash
gcc -DTINYLOG_LEVEL=TINYLOG_LEVEL_INFO ${SOURCE}
```
