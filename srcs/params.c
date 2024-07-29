#include "../include/philosophers.h"

params_t *params()
{
  static params_t params;

  return (&params);
}
