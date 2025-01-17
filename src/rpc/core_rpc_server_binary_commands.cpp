#include "core_rpc_server_binary_commands.h"

namespace cryptonote::rpc {

KV_SERIALIZE_MAP_CODE_BEGIN(EMPTY)
KV_SERIALIZE_MAP_CODE_END()


  void to_json(nlohmann::json& j, const GET_BLOCKS_BIN::tx_output_indices& toi)
  {
    j = nlohmann::json{{"indices", toi.indices}};
  }

  void to_json(nlohmann::json& j, const GET_BLOCKS_BIN::block_output_indices& boi)
  {
    j = nlohmann::json{{"indices", boi.indices}};
  }

KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BIN::request)
  KV_SERIALIZE_CONTAINER_POD_AS_BLOB(block_ids)
  KV_SERIALIZE(start_height)
  KV_SERIALIZE(prune)
  KV_SERIALIZE_OPT(no_miner_tx, false)
KV_SERIALIZE_MAP_CODE_END()

KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BIN::tx_output_indices)
  KV_SERIALIZE(indices)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BIN::block_output_indices)
  KV_SERIALIZE(indices)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BIN::response)
  KV_SERIALIZE(blocks)
  KV_SERIALIZE(start_height)
  KV_SERIALIZE(current_height)
  KV_SERIALIZE(status)
  KV_SERIALIZE(output_indices)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BY_HEIGHT_BIN::request)
  KV_SERIALIZE(heights)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_BLOCKS_BY_HEIGHT_BIN::response)
  KV_SERIALIZE(blocks)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_ALT_BLOCKS_HASHES_BIN::response)
  KV_SERIALIZE(blks_hashes)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_HASHES_BIN::request)
  KV_SERIALIZE_CONTAINER_POD_AS_BLOB(block_ids)
  KV_SERIALIZE(start_height)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_HASHES_BIN::response)
  KV_SERIALIZE_CONTAINER_POD_AS_BLOB(m_block_ids)
  KV_SERIALIZE(start_height)
  KV_SERIALIZE(current_height)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_TX_GLOBAL_OUTPUTS_INDEXES_BIN::request)
  KV_SERIALIZE_VAL_POD_AS_BLOB(txid)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_TX_GLOBAL_OUTPUTS_INDEXES_BIN::response)
  KV_SERIALIZE(o_indexes)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(get_outputs_out)
  KV_SERIALIZE(amount)
  KV_SERIALIZE(index)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_OUTPUTS_BIN::request)
  KV_SERIALIZE(outputs)
  KV_SERIALIZE_OPT(get_txid, true)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_OUTPUTS_BIN::outkey)
  KV_SERIALIZE_VAL_POD_AS_BLOB(key)
  KV_SERIALIZE_VAL_POD_AS_BLOB(mask)
  KV_SERIALIZE(unlocked)
  KV_SERIALIZE(height)
  KV_SERIALIZE_VAL_POD_AS_BLOB(txid)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_OUTPUTS_BIN::response)
  KV_SERIALIZE(outs)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_TRANSACTION_POOL_HASHES_BIN::request)
  KV_SERIALIZE_OPT(blinked_txs_only, false)
  KV_SERIALIZE_OPT(long_poll, false)
  KV_SERIALIZE_VAL_POD_AS_BLOB_OPT(tx_pool_checksum, crypto::hash{})
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_TRANSACTION_POOL_HASHES_BIN::response)
  KV_SERIALIZE(status)
  KV_SERIALIZE_CONTAINER_POD_AS_BLOB(tx_hashes)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()


KV_SERIALIZE_MAP_CODE_BEGIN(GET_OUTPUT_BLACKLIST_BIN::response)
  KV_SERIALIZE(blacklist)
  KV_SERIALIZE(status)
  KV_SERIALIZE(untrusted)
KV_SERIALIZE_MAP_CODE_END()

}
