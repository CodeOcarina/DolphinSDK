#include "MinsiSDK.h"

BEGIN_DEF_RPC(Hello, (aaa)(bbb)(ccc)(transfer));

void Hello::transfer()
{
    MAKE_PARAM(param,
        (account_name from)(account_name to)(eosio::asset quantity)(std::string memo));

    // Json::JSON jsonObj = this->LoadParam(param.memo);

    //eosio::require_recipient(S2N(jsonObj["tar"].ToString()));

    // MsLog("Contract::transfer,默认处理", eosio::name{param.from});
    // MsLog("Contract::transfer,默认处理", eosio::name{param.to});
    // MsLog("Contract::transfer,默认处理", param.quantity);
    // MsLog("Contract::transfer,默认处理", param.memo);

    // Ms::Asset payAsset(N(eosio.token), param.quantity);
    // Ms::Account me(N(zhaojingdong));
    // me.CheckPermission();
    // me.Transfer(Ms::Account(N(jingdongzhao)), payAsset, "你赢了,发财了!");
}

void Hello::bbb()
{
    // MsLog("111111111");
    // MAKE_PARAM(param, (std::string json_param));
    // MsLog("222222222");
    // MsLog(param.json_param.size(), param.json_param.c_str());
    // auto jsonObj = this->LoadParam(param.json_param);

    // MsLog("Contract::bbb,默认处理", jsonObj["from"].ToString().c_str());
    // MsLog("Contract::bbb,默认处理", jsonObj["to"].ToString().c_str());
    // MsLog("Contract::bbb,默认处理", jsonObj["quantity"].ToString().c_str());
    // MsLog("Contract::bbb,默认处理", jsonObj["memo"].ToString().c_str());
}

void Hello::ccc()
{
}
using namespace Ms;

struct test_table
{
    uint64_t key;
    std::string balance;

    uint64_t primary_key() const
    {
        return key;
    }
};

void Hello::aaa()
{
    // auto josnObject = this->LoadParam(eosio::unpack_action_data<std::string>());

    // // eosio::execute_action(thiscontract, &OP::elem);

    // auto actor = S2N(josnObject["actor"].ToString());
    // auto tar = S2N(josnObject["tar"].ToString());
    // Ms::Account Actor(actor);
    // Ms::Account Tar(tar);

    // Actor.CheckPermission(N(owner));
    // eosio::extended_asset AssetType;
    // AssetType.symbol = S(4, EOS);
    // AssetType.amount = 1;
    // AssetType.contract = N(eosio.token);
    // Actor.Transfer(Tar, AssetType, josnObject["memo"].ToString());

    // MsLog("余额", Actor.GetBalance(AssetType.contract, S(4, EOS)));
    // MsLog("余额", Tar.GetBalance(AssetType.contract, S(4, EOS)));

    // // Ms::Table<N(testtable), test_table> t(Ms::Account(N(zhaojingdong)), Ms::Account(N(eosio.token)));

    // // t.Set(test_table{1, "1"});
    // // t.Set(test_table{2, "2"});

    // // t.Get(1).balance.c_str();
    // MsLog("aaa.admin");
}
