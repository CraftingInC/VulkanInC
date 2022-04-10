/* Unknown license from original author. Once I rewrite it, it will be MIT. */

#include "logging.h"

#include <time.h>    // time()  localtime()  strftime()  tzset()
#include <unistd.h>  // getpid()

void _log(FILE *file, const char *fmt, ...) {
  va_list ap;
  time_t t;
  char datestr[51];

  file = (file == NULL) ? stderr : file;

  t = time(NULL);
  tzset();
  strftime(datestr, sizeof(datestr) - 1, "%a %b %d %Y %H:%M:%S %Z", localtime(&t));
  fprintf(file, "%s [PID %d]: ", datestr, getpid());

  va_start(ap, fmt);
  vfprintf(file, fmt, ap);
  va_end(ap);

  fprintf(file, "\n");
}
