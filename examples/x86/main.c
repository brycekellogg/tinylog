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
#include <tinylog.h>

int main() {
    tinylog_error("this is an error: %d", -1);
    tinylog_warn("this is a warning: %s", "help!");
    tinylog_info("this is an info");
    tinylog_debug("this is a debug");
}
