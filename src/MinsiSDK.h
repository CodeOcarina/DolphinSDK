#pragma once

// 基础库
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/symbol.hpp>
#include <eosiolib/currency.hpp>

// 宏定义
#include "MsMacro.h"
#include "MsAsset.h"
#include "MsAccount.h"
#include "MsContract.h"
#include "MsTable.h"

#include "MsAccount.cpp"
#include "MsAsset.cpp"
#include "MsContract.cpp"

// 合约底层入口
extern "C"
{
    void apply(uint64_t _receiver, uint64_t _code, uint64_t _action)
    {
        auto _self = _receiver;
        MsContract *thiscontract = MsContract::CreateNewContractInstance(_self, _code, _action);

        switch (_action)
        {
            // 针对转账统一安全处理
            case N(transfer):
            {
                MAKE_PARAM(param, (AccountName from)(AccountName to)(eosio::asset quantity)(std::string memo));
                thiscontract->OnTransfer(MsAccount(param.from), MsAccount(param.to), MsAsset(_code, param.quantity), param.memo);
            }
            break;

            // 处理其他RPC
            default:
            {
                thiscontract->OnCall();
            }
            break;
        }
    }
}
