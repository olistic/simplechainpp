#include "miner.h"

#include "block.h"

namespace simplechain {

void Miner::MineBlock(Block* block) {
  while (!block->IsValid()) {
    block->inc_nonce();
    block->set_hash(block->CalculateHash());
  }
}

}  // namespace simplechain
