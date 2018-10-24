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

#include "json.hpp"

class msContract : public eosio::contract
{
protected:
    msAccount m_self;
    msAccount m_receiver;
    msAccount m_code;
    msAccount m_action;

public:
    static msContract *createNewContractInstance(uint64_t _self, uint64_t _code, uint64_t _action);
    msContract(uint64_t _self, uint64_t _code, uint64_t _action);

    typedef void (msContract::*RPC_CALL)(void);
    std::map<uint64_t, RPC_CALL> m_listRPC;

    msAccount getCurrentReceiver();
    msAccount getCurrentCode();

    void commitAndExit(uint64_t ret_code = 1);

    json::JSON loadParam(std::string &&_json_param) { return this->loadParam(_json_param); }
    json::JSON loadParam(std::string &_json_param);

    void onCall();
    void onTransfer(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo);
    virtual void onTransferToMe(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual onTransferToMe()"); }
    virtual void onTransferFromMe(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual onTransferFromMe()"); }
    virtual void onTransferOther(msAccount _from, msAccount _to, msAsset _assetQuantity, std::string _memo) { MsAssert(false, "默认禁止转账,请重载并实现virtual onTransferOther()"); }
};
