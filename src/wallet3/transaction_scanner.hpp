#pragma once

#include "output.hpp"
#include "keyring.hpp"

#include <cryptonote_basic/cryptonote_basic.h>

#include <vector>

namespace db
{
  class Database;
}

namespace wallet
{
  struct BlockTX;

  class TransactionScanner
  {
   public:
    TransactionScanner(std::shared_ptr<Keyring> keys, std::shared_ptr<db::Database> db)
        : wallet_keys(keys), db(db)
    {}

    std::vector<Output>
    scan_received(const BlockTX& tx, int64_t height, int64_t timestamp);

    std::vector<crypto::key_image>
    scan_spent(const cryptonote::transaction& tx);

   private:
    std::shared_ptr<Keyring> wallet_keys;
    std::shared_ptr<db::Database> db;
  };

}  // namespace wallet
