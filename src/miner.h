#ifndef SIMPLECHAIN_MINER_H_
#define SIMPLECHAIN_MINER_H_

#include "block.h"

namespace simplechain {

class Miner {
 public:
  // Mines a block.
  //
  // Finds a special number (called nonce) which, combined with the rest of the
  // fields of the block, produces a hash that complies with the difficulty
  // requirements of the blockchain.
  //
  // @param block The block to mine.
  void MineBlock(Block* block);
};

}  // namespace simplechain

#endif  // SIMPLECHAIN_BLOCK_H_
