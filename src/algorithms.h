#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdint.h>
#include <stdbool.h>

/// Retry a function until it returns true.
/// @param[in] fn The function. 
/// @param[in] attempts Max number of attempts. 
void retry (bool (*function)(), uint8_t attempts); 
 
 
#endif // ALGORITHMS_H
