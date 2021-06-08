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
#include "tinylog.h"

#include <stdarg.h>
#include <stdio.h>

void tinylog_log(const char* level, const char* filename, int linenumber, const char* fmt, ...) {
    static char messageBuffer[TINYLOG_MAXBUFFER];
    char* p = messageBuffer;

    // Log level
    p += snprintf(p, TINYLOG_MAXBUFFER, "%s\t| ", level);

    // Message
    va_list arglist;
    va_start(arglist, fmt);
    p += vsnprintf(p, TINYLOG_MAXBUFFER, fmt, arglist);
    va_end(arglist);

    // Filename + Line Number
    p += snprintf(p, TINYLOG_MAXBUFFER, " | (%s:%d)\n", filename, linenumber);

    // Actually log it
    printf(messageBuffer);
}
