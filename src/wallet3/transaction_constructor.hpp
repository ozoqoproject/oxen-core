#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include "pending_transaction.hpp"
#include "daemon_comms.hpp"
#include "decoy_selection/decoy_selection.hpp"

namespace wallet
{
  class WalletDB;

  class TransactionConstructor
  {
   public:
    TransactionConstructor(std::shared_ptr<WalletDB> database, std::shared_ptr<DaemonComms> dmn, cryptonote::address_parse_info sender = {})
        : db(std::move(database)), daemon(std::move(dmn)), decoy_selector(std::make_unique<DecoySelector>(0,0)), senders_address(sender)
    {
      std::tie(fee_per_byte, fee_per_output) = daemon->get_fee_parameters();

      // This initialises the decoys to be selected from global_output_index= 0 to global_output_index = highest_output_index
      // Oxen started with ringct transaction from its genesis so all transactions should be usable as decoys.
      // We keep track of the number of transactions in each block so we can recreate the highest_output_index by summing
      // all the transactions in every block.
      
      // TODO sean this should actually be kept track of somewhere in the schema. not just max of *our* outputs
      //int64_t max_output_index = db->prepared_get<int>("SELECT max(global_index) FROM outputs;");
      int64_t max_output_index = 100; 
      decoy_selector = std::make_unique<DecoySelector>(0, max_output_index);
    };

    PendingTransaction
    create_transaction(const std::vector<cryptonote::tx_destination_entry>& recipients, const cryptonote::tx_destination_entry& change_recipient);

    uint64_t fee_per_byte = cryptonote::FEE_PER_BYTE_V13;
    uint64_t fee_per_output = cryptonote::FEE_PER_OUTPUT_V18;

    std::unique_ptr<DecoySelector> decoy_selector;

   private:
    void
    select_inputs(PendingTransaction& ptx) const;

    void
    select_and_fetch_decoys(PendingTransaction& ptx);

    void
    select_inputs_and_finalise(PendingTransaction& ptx);

    int64_t
    estimate_fee() const;

    std::shared_ptr<WalletDB> db;
    std::shared_ptr<DaemonComms> daemon;

    cryptonote::address_parse_info senders_address{};
  };

}  // namespace wallet
