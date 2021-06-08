/*  _______ _____ _   ___     ___      ____   _____
 * |__   __|_   _| \ | \ \   / / |    / __ \ / ____|
 *    | |    | | |  \| |\ \_/ /| |   | |  | | |  __
 *    | |    | | | . ` | \   / | |   | |  | | | |_ |
 *    | |   _| |_| |\  |  | |  | |___| |__| | |__| |
 *    |_|  |_____|_| \_|  |_|  |______\____/ \_____|
 *
 * Author: Bryce Kellogg (bryce@kellogg.org)
 * Copyright: 2021 Bryce Kellogg
 * License: BSD 3-Clause
 */
#ifndef _TINYLOG_H_
#define _TINYLOG_H_
#ifdef __cplusplus
extern "C" {
#endif


/* Configure the default log level. This can be set via a
 * compiler define to override the default log level.  */
#ifndef TINYLOG_LEVEL
#define TINYLOG_LEVEL  TINYLOG_LEVEL_INFO
#endif


/* The defined log levels that allow us to filter at
 * compile time based on the selected log level. More
 * verbose levels should always be a lower value than
 * less verbose levels. Actual numbers do not matter. */
#define TINYLOG_LEVEL_DEBUG  0
#define TINYLOG_LEVEL_INFO   1
#define TINYLOG_LEVEL_WARN   2
#define TINYLOG_LEVEL_ERROR  3


/* String representations of log levels. These are used when
 * displaying the log level as part of the log message.
 * These can be redefined for localization if needed.  */
#ifndef TINYLOG_LEVEL_STR_DEBUG
#define TINYLOG_LEVEL_STR_DEBUG  "DEBUG"
#endif

#ifndef TINYLOG_LEVEL_STR_INFO
#define TINYLOG_LEVEL_STR_INFO   "INFO"
#endif

#ifndef TINYLOG_LEVEL_STR_WARN
#define TINYLOG_LEVEL_STR_WARN   "WARN"
#endif

#ifndef TINYLOG_LEVEL_STR_ERROR
#define TINYLOG_LEVEL_STR_ERROR  "ERROR"
#endif


/* Configure the maximum size of a log message, including all formatting
 * such as log level, filename, line number, etc. If a given log message
 * exceeds this maximum, it will be truncated but will still log. */
#ifndef TINYLOG_MAXBUFFER
#define TINYLOG_MAXBUFFER  256
#endif


/* Logging functions to be called by user code. Each function will only be
 * defined if the log level is set to the corresponding level or lower
 * (more verbose). Thus there is no overhead if the log level indicates that
 * the function should not log. The arguments mirror that of printf.  */
#if (TINYLOG_LEVEL <= TINYLOG_LEVEL_DEBUG)
#define tinylog_debug(...)  tinylog_log(TINYLOG_LEVEL_STR_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#else
#define tinylog_debug(...)
#endif

#if (TINYLOG_LEVEL <= TINYLOG_LEVEL_INFO)
#define tinylog_info(...)   tinylog_log(TINYLOG_LEVEL_STR_INFO, __FILE__, __LINE__, __VA_ARGS__)
#else
#define tinylog_info(...)
#endif

#if (TINYLOG_LEVEL <= TINYLOG_LEVEL_WARN)
#define tinylog_warn(...)   tinylog_log(TINYLOG_LEVEL_STR_WARN, __FILE__, __LINE__, __VA_ARGS__)
#else
#define tinylog_warn(...)
#endif

#if (TINYLOG_LEVEL <= TINYLOG_LEVEL_ERROR)
#define tinylog_error(...)  tinylog_log(TINYLOG_LEVEL_STR_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#else
#define tinylog_error(...)
#endif


/* The unified log function used by all helper logging functions. While this
 * function can be called directly, it is advised to use one of the helper
 * functions defined above.
 *    - level       the log level of the message
 *    - filename    the filename at the call location
 *    - linenumber  the line number of the call location
 *    - fmt         the message string, following printf formatting rules
 *    - ...         a variadic list of arguments to the message string
 */
void tinylog_log(const char* level, const char* filename, int linenumber, const char* fmt, ...);


#ifdef __cplusplus
}
#endif
#endif /* _TINYLO_H_ */
