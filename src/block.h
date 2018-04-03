#ifndef SIMPLECHAIN_BLOCK_H_
#define SIMPLECHAIN_BLOCK_H_

#include <ctime>
#include <string>

namespace simplechain {

class Block {
 public:
  // Creates a block.
  //
  // @param previous_block The previous block in the blockchain.
  // @param data The data of the block.
  // @param difficulty The difficulty to mine the block.
  // @param timestamp The timestamp of the block.
  // @param nonce The nonce.
  Block(Block* previous_block, std::string data, int difficulty,
        std::time_t timestamp = 0, int nonce = 0);

  int index() const;

  Block* previous_block() const;

  std::string data() const;

  int difficulty() const;

  std::time_t timestamp() const;

  int nonce() const;

  std::string header() const;

  std::string hash() const;

  // Calculates the hash of the block.
  //
  // The hash of a block is the SHA-256 digest of its header.
  //
  // @return The hash of the block.
  std::string CalculateHash() const;

  // Checks if the block is a valid block.
  //
  // A block is valid if the following conditions are met:
  //
  //  - The hash stored in the block matches the calculated hash of the block.
  //  - The block complies with the difficulty requirements of the blockchain
  //    at the time it was mined.
  //
  // @return Whether the block is valid or not.
  bool IsValid() const;

 private:
  int index_;

  Block* previous_block_;

  std::string data_;

  int difficulty_;

  std::time_t timestamp_;

  int nonce_;

  std::string hash_;
};

}  // namespace simplechain

#endif  // SIMPLECHAIN_BLOCK_H_
