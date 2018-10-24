#pragma once

// 基础库
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/symbol.hpp>
#include <eosiolib/currency.hpp>

// 宏定义
#include "msMacro.h"
#include "msAsset.h"
#include "msAccount.h"
#include "msContract.h"
#include "msTable.h"

#include "msAccount.cpp"
#include "msAsset.cpp"
#include "msContract.cpp"

// 合约底层入口
extern "C"
{
    void apply(uint64_t _receiver, uint64_t _code, uint64_t _action)
    {
        auto _self = _receiver;
        msContract *thiscontract = msContract::createNewContractInstance(_self, _code, _action);

        switch (_action)
        {
            // 针对转账统一安全处理
            case N(transfer):
            {
                MAKE_PARAM(param, (AccountName from)(AccountName to)(eosio::asset quantity)(std::string memo));
                thiscontract->onTransfer(msAccount(param.from), msAccount(param.to), msAsset(_code, param.quantity), param.memo);
            }
            break;

            // 处理其他RPC
            default:
            {
                thiscontract->onCall();
            }
            break;
        }
    }
}
