#ifndef SIMPLECHAIN_SHA256_H_
#define SIMPLECHAIN_SHA256_H_

#include <string>

namespace simplechain {

// Calculates SHA-256 digest of input.
//
// @param input The input.
std::string sha256(const std::string input);

}  // namespace simplechain

#endif  // SIMPLECHAIN_SHA256_H_
