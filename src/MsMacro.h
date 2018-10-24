#pragma once

#define MsAssert(condition, info)                                   \
    if (!(condition))                                               \
    {                                                               \
        eosio::print("\n===assert=====================\n");         \
        eosio::print(info);                                         \
        eosio::print("\n==============================\n\n\n\n\n"); \
        eosio_assert(condition, info);                              \
    }

#define MsLogName(n, ...)                                       \
    if (true)                                                   \
    {                                                           \
        eosio::print("\n---" #n, "------------------------\n"); \
        eosio::print(__VA_ARGS__);                              \
        eosio::print("\n------------------------------\n");     \
    }

#define MsLog(...)                                          \
    if (true)                                               \
    {                                                       \
        eosio::print("\n---log------------------------\n"); \
        eosio::print(__VA_ARGS__);                          \
        eosio::print("\n------------------------------\n"); \
    }

#define MsAssetPrint(d, x) eosio::asset((uint64_t)(d * 1000000), eosio::string_to_symbol(6, #x))

namespace eosio
{
    uint64_t string_to_name(std::string str) { return string_to_name(str.c_str()); }
} // namespace eosio
#define S2N(s) (eosio::string_to_name(s))
#define N2S(n) (eosio::name{(n)}.to_string())

#define SplitParam(_params, _delimiter, _pstr)                                      \
    std::vector<std::string> _params;                                               \
    string::size_type p1_##_params, p2_##_params;                                   \
    p2_##_params = _pstr.find(_delimiter);                                          \
    p1_##_params = 0;                                                               \
    while (std::string::npos != p2_##_params)                                       \
    {                                                                               \
        _params.push_back(_pstr.substr(p1_##_params, p2_##_params - p1_##_params)); \
        p1_##_params = p2_##_params + 1;                                            \
        p2_##_params = _pstr.find(_delimiter, p1_##_params);                        \
    }                                                                               \
    _params.push_back(_pstr.substr(p1_##_params));                                  \
    eosio::print("\n---params---------------------\n");                             \
    for (int i = 0; i < _params.size(); i++)                                        \
    {                                                                               \
        eosio::print("  ", i, ":\t", _params[i], "\n");                             \
    }                                                                               \
    eosio::print("\n------------------------------\n");

#define MsAssertHelpInfo msAssert(false, makeHelpInfo().c_str())

#define DefBuff(_n, _s) \
    char _n[_s];        \
    memset(_n, 0, _s);

#define MS_RPC_API_DEF(r, OP, elem) \
    void elem(void);

#define MS_RPC_API_REG(r, OP, elem) \
    x->m_listRPC[N(elem)] = (msContract::RPC_CALL)&OP::elem;

#define MS_RPC_API_LIST(TYPE, MEMBERS) \
    BOOST_PP_SEQ_FOR_EACH(MS_RPC_API_DEF, TYPE, MEMBERS)

#define BEGIN_DEF_RPC(contract_name, MEMBERS)                                                                          \
    class contract_name : public msContract                                                                            \
    {                                                                                                                  \
      public:                                                                                                          \
        contract_name(uint64_t _receiver, uint64_t _code, uint64_t _action) : msContract(_receiver, _code, _action) {} \
        virtual void onTransferToMe(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo);        \
        virtual void onTransferFromMe(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo);      \
        virtual void onTransferOther(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo);       \
        BOOST_PP_SEQ_FOR_EACH(MS_RPC_API_DEF, contract_name, MEMBERS)                                                  \
    };                                                                                                                 \
    msContract *msContract::createNewContractInstance(uint64_t _receiver, uint64_t _code, uint64_t _action)            \
    {                                                                                                                  \
        auto x = new contract_name(_receiver, _code, _action);                                                         \
        BOOST_PP_SEQ_FOR_EACH(MS_RPC_API_REG, contract_name, MEMBERS)                                                  \
        return x;                                                                                                      \
    }                                                                                                                  \
    typedef contract_name __this_contract__;

#define DEFINE_CONTRACT_INTERFACE BEGIN_DEF_RPC

#define BEGIN_IMPL(__fun__) void __this_contract__::__fun__()
#define END_IMPL

#define MS_UNPACK_FIELD(r, OP, elem) elem;

#define MS_MAKE_PACK_STRUCT(MEMBERS) \
    BOOST_PP_SEQ_FOR_EACH(MS_UNPACK_FIELD, , MEMBERS)

#define MAKE_PARAM(param, MEMBERS)        \
    auto unpack_param_fun = []() {        \
    struct ___rpc_cmd_param___            \
    {                                     \
        MS_MAKE_PACK_STRUCT(MEMBERS)      \
    } param_name = eosio::unpack_action_data<___rpc_cmd_param___>();\
    return param_name; }; \
    auto param = unpack_param_fun();

typedef uint64_t MarkName;
typedef account_name AccountName;
