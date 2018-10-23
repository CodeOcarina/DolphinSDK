#pragma once

// rpc.result
#pragma region
struct rpcresult
{
    std::string param;
    std::string result;

    uint64_t primary_key() const { return 0; }
};
typedef eosio::multi_index<N(rpcparamresult), rpcresult> result;
#pragma endregion

#include "Json.hpp"

class MsContract : public eosio::contract
{
protected:
    MsAccount m_self;
    MsAccount m_receiver;
    MsAccount m_code;
    MsAccount m_action;

public:
    static MsContract *CreateNewContractInstance(uint64_t _self, uint64_t _code, uint64_t _action);
    MsContract(uint64_t _self, uint64_t _code, uint64_t _action);

    typedef void (MsContract::*RPC_CALL)(void);
    std::map<uint64_t, RPC_CALL> m_listRPC;

    MsAccount GetCurrentReceiver();
    MsAccount GetCurrentCode();

    void CommitAndExit(uint64_t ret_code = 1);

    Json::JSON LoadParam(std::string &&_json_param) { return this->LoadParam(_json_param); }
    Json::JSON LoadParam(std::string &_json_param);

    void OnCall();
    void OnTransfer(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo);
    virtual void OnTransferToMe(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual OnTransferToMe()"); }
    virtual void OnTransferFromMe(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual OnTransferFromMe()"); }
    virtual void OnTransferOther(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual OnTransferOther()"); }
};
