// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/log.hpp"

using arrow::Log;

Log::Log() : _counters() {
}

Log& Log::get() noexcept {
  static Log instance;
  return instance;
}

void Log::log(LogLevel level, const char* format, fmt::ArgList args) {
  fmt::print(stderr, "\x1b[0;37m{}", "arrow: ");

  // Move level_* determination to helper function

  const char* level_str;
  const char* level_color;

  switch (level) {
  case LOG_ERROR:
    level_str = "error";
    level_color = "0;31";
    break;

  case LOG_WARN:
    level_str = "warn";
    level_color = "0;33";
    break;

  case LOG_INFO:
    level_str = "info";
    level_color = "0;34";
    break;

  case LOG_DEBUG:
    level_str = "debug";
    level_color = "0;35";
    break;

  case LOG_TRACE:
    level_color = "0";
    level_str = "trace";
    break;

  default:
    level_str = "<?>";
  }

  fmt::print(stderr, "\x1b[{}m{}: \x1b[1;37m", level_color, level_str);

  fmt::print(stderr, format, args);
  fmt::print(stderr, "\x1b[0m\n");
}

void Log::log(
  LogLevel level, Span span, const char* format, fmt::ArgList args
) {
  fmt::print(stderr, "\x1b[0;37m{}: ", span);

  // Move level_* determination to helper function

  const char* level_str;
  const char* level_color;

  switch (level) {
  case LOG_ERROR:
    level_str = "error";
    level_color = "0;31";
    break;

  case LOG_WARN:
    level_str = "warn";
    level_color = "0;33";
    break;

  case LOG_INFO:
    level_str = "info";
    level_color = "0;34";
    break;

  case LOG_DEBUG:
    level_str = "debug";
    level_color = "0;35";
    break;

  case LOG_TRACE:
    level_color = "0";
    level_str = "trace";
    break;

  default:
    level_str = "<?>";
  }

  fmt::print(stderr, "\x1b[{}m{}: \x1b[1;37m", level_color, level_str);

  fmt::print(stderr, format, args);
  fmt::print(stderr, "\x1b[0m\n");
}
