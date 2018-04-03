#include "sha256.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <openssl/sha.h>

namespace simplechain {

std::string sha256(const std::string input) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX context;
  SHA256_Init(&context);
  SHA256_Update(&context, input.c_str(), input.length());
  SHA256_Final(hash, &context);
  std::stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}

}  // namespace simplechain
