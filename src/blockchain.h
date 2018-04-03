#ifndef SIMPLECHAIN_BLOCKCHAIN_H_
#define SIMPLECHAIN_BLOCKCHAIN_H_

#include "block.h"

namespace simplechain {

// The default difficulty of a blockchain.
const int kDifficulty = 5;

class Blockchain {
 public:
  // Creates a blockchain.
  //
  // A blockchain is a chain of blocks where each block points to the previous
  // block. It has also a difficulty, which represents the number of zeros the
  // hashes of the blocks that belong to the blockchain are required to start
  // with.
  //
  // A blockchain starts with a known block called the Genesis block.
  //
  // @param difficulty The difficulty of the blockchain.
  Blockchain(int difficulty = kDifficulty);

  int difficulty() const;

  Block* last_block() const;

  // Adds a block at the end of the chain.
  //
  // To add a block, its previous block needs to be the last block in the chain
  // and it has to be valid.
  //
  // @param block The block to add.
  void AddBlock(Block* block);

  // Checks if the blockchain is valid.
  //
  // A blockchain is valid if the following conditions are met:
  //
  //  - Each block in the chain is a valid block.
  //  - The first block in the chain is the Genesis block.
  //
  // @return Whether the blockchain is valid or not.
  bool IsValid() const;

 private:
  static Block* genesis_block_;

  int difficulty_;

  Block* last_block_;
};

}  // namespace simplechain

#endif  // SIMPLECHAIN_BLOCKCHAIN_H_
