#include <MinsiSDK.h>

DEFINE_CONTRACT_INTERFACE(eosdice, (help))

#define VALIDATE_ASSET(_quantity_, _min_, _max, _tokencontract_, _precision_, _symbol_) \
    _quantity_.Validate(#_min_, #_max, N(_tokencontract_), S(_precision_, _symbol_));

void eosdice::help()
{
    MsAssert(false, "帮助信息");
}

void gettime()
{
    uint64_t t_now = now();
    uint64_t t_time = current_time();
    uint64_t t_pub_time = publication_time();

    eosio::print(" now : ", t_now);
    eosio::print(" current time: ", t_time);
    eosio::print(" publication time: ", t_pub_time);
}

void eosdice::OnTransferToMe(MsAccount _from, MsAccount /*_to equal m_self*/, MsAsset _assetQuantity, std::string _memo)
{
    if (_memo == "")
    {
        this->CommitAndExit();
    }

    MsLog("time:", current_time());

    // MsLog(_memo.c_str());
    Json::JSON jsonObj = this->LoadParam(_memo);
    MsLog("time:", current_time());
    // int tarNumber = atoi(_memo.c_str());
    int tarNumber = Json::CheckInt(jsonObj["roll"], 2, 96);
    MsLog("time:", current_time());

    // auto number = Ms::Random(1, 100);
    int number = 49;
    if (tarNumber >= number)
    {
        MsLog(_from.ToString().c_str(), " rolled ", tarNumber, ", less than ", number, ", you loss!");
        this->CommitAndExit();
    }
    MsLog("time:", current_time());

    // 计算赔率的公式在这里
    auto ODDS = 98.0 / ((float)(tarNumber)-1.0);
    uint64_t payAmount = (uint64_t)((ODDS * _assetQuantity.amount) - _assetQuantity.amount);

    MsAsset payAsset(N(eosio.token), S(4, EOS), payAmount);
    VALIDATE_ASSET(payAsset, 0.0001, 10000.0000, eosio.token, 4, EOS);
    MsLog("time:", current_time());

    // if (!theTo.CheckBalance(payAsset))
    // {
    //     MsLog("the pool doesn't have ", payAmount, " money");
    //     MsAssert(false, "池子内余额不足");
    // }
    m_self.Transfer(_from, payAsset, "你赢了,发财了!");
    MsLog("time:", current_time());
}

void eosdice::OnTransferFromMe(MsAccount /*_from equal m_self*/, MsAccount _to, MsAsset _assetQuantity, std::string _memo)
{
    MsLog("合约:", m_self.ToString().c_str(), "转出:", _assetQuantity.ToString().c_str());
}

void eosdice::OnTransferOther(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo)
{
    MsLog("记录:", _from.ToString().c_str(), "转给:", _to.ToString().c_str(), ":", _assetQuantity.ToString().c_str());
}

// BEGIN_IMPL(transfer)
// {
//     MAKE_PARAM(param, (AccountName from)(AccountName to)(eosio::asset quantity)(std::string memo));
//     MsAccount theFrom(param.from);
//     MsAccount theTo(param.to);

//     MsAssert(param.from != param.to, "from != to");

//     if (param.from == m_receiver || param.to != m_receiver)
//     {
//         this->CommitAndExit();
//     }

//     // Ms::Asset theAsset(N(eosio.token), param.quantity);

//     // VALIDATE_ASSET(theAsset, 0.0001, 10000.0000, eosio.token, 4, EOS);

//     // auto tmp = theTo.GetBalance(N(eosio.token), S(4, EOS));
//     // MsLog("余额", tmp.ToString().c_str());

//     // if (!theFrom.CheckBalance(theAsset))
//     // {
//     //     MsLog(theFrom.ToString().c_str(), " doesn't have ", theAsset.ToString().c_str(), " money");
//     //     MsAssert(false, "余额不足");
//     // }

//     MsLog(param.memo);
//     Json::JSON jsonObj = this->LoadParam(param.memo);
//     MsLog("22222");
//     int tarNumber = Json::CheckInt(jsonObj["roll"], 2, 96);
//     MsLog("33333");

//     // auto number = Ms::Random(1, 100);
//     int number = 49;
//     if (tarNumber >= number)
//     {
//         MsLog(theFrom.ToString().c_str(), " rolled ", tarNumber, ", less than ", number, ", you loss!");
//         this->CommitAndExit();
//     }

//     // 计算赔率的公式在这里
//     auto ODDS = 98.0 / ((float)(tarNumber)-1.0);
//     uint64_t payAmount = (uint64_t)((ODDS * param.quantity.amount) - param.quantity.amount);

//     Ms::Asset payAsset(N(eosio.token), S(4, EOS), payAmount);
//     VALIDATE_ASSET(payAsset, 0.0001, 10000.0000, eosio.token, 4, EOS);

//     // if (!theTo.CheckBalance(payAsset))
//     // {
//     //     MsLog("the pool doesn't have ", payAmount, " money");
//     //     MsAssert(false, "池子内余额不足");
//     // }
//     theTo.Transfer(theFrom, payAsset, "你赢了,发财了!");

//     // auto tmp2 = theTo.GetBalance(N(eosio.token), S(4, EOS));
//     // MsLog("余额", tmp2.ToString().c_str());

//     // auto receipt = to.send(from, pay);
//     // return Ms::ExitAndCommit("%s rolled %n, bigger or equal to %n, you win! \n The incoming transaction_id = %s",
//     //                          from.GetName(),
//     //                          jsonParam["roll"],
//     //                          number,
//     //                          receipt);
// }
// END_IMPL
