#include "blockchain.h"

#include "block.h"

namespace simplechain {

Blockchain::Blockchain(int difficulty) {
  difficulty_ = difficulty;
  last_block_ = genesis_block_;
}

int Blockchain::difficulty() const { return difficulty_; }

Block* Blockchain::last_block() const { return last_block_; }

void Blockchain::AddBlock(Block* block) {
  if (block->previous_block() == last_block_ && block->IsValid()) {
    last_block_ = block;
  }
}

bool Blockchain::IsValid() const {
  if (!last_block_) {
    return false;
  }

  Block* block = last_block_;
  while (block->previous_block()) {
    if (!block->IsValid()) {
      return false;
    }

    block = block->previous_block();
  }

  if (block != genesis_block_) {
    return false;
  }

  return true;
}

// TODO: Adjust nonce to meet difficulty.
Block* Blockchain::genesis_block_ = new Block(
    nullptr, "Everything should be made as simple as possible, but not simpler",
    kDifficulty, 1509926400, 0);

}  // namespace simplechain
