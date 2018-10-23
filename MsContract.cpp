#pragma once

MsContract::MsContract(uint64_t _self, uint64_t _code, uint64_t _action)
    : eosio::contract(_self), m_self(_self), m_receiver(_self), m_code(_code), m_action(_action)
{
}

MsAccount
MsContract::GetCurrentReceiver()
{
    return m_receiver;
}

MsAccount
MsContract::GetCurrentCode()
{
    return m_code;
}

void MsContract::CommitAndExit(uint64_t ret_code)
{
    MsLog("commit and exit ret code: ", ret_code);
    eosio_exit(0);
}

Json::JSON
MsContract::LoadParam(std::string &_json_param)
{
    eosio::print("\n\n");
    eosio::print("\n===json======================\n");

    eosio::print("  receiver:\t", m_receiver.ToString().c_str(),
        "\n  code:\t\t", m_code.ToString().c_str(),
        "\n  action:\t", m_action.ToString().c_str(), "\n");

    eosio::print("\n==============================\n");
    eosio::print("params\n");
    Json::JSON obj = Json::JSON::Load(_json_param);
    eosio::print(obj.dump().c_str());
    eosio::print("\n==============================\n");
    return obj;
}

void MsContract::OnCall()
{
    MsAssert(m_action.GetEosName() != N(onerror), "onerror action's are unsafe");

    // MsAssert(m_action.GetEosName() != N(onerror), "onerror action's are unsafe");
    // MsAssert(m_action.GetEosName() != N(onerror), "onerror action's are unsafe");
    // MsAssert(m_action.GetEosName() != N(onerror), "onerror action's are unsafe");
    // MsAssert(m_action.GetEosName() != N(onerror), "onerror action's are unsafe");

    auto itRPC = m_listRPC.find(m_action.GetEosName());
    if (itRPC != m_listRPC.end())
    {
        eosio::execute_action(this, itRPC->second);
    }
}
void MsContract::OnTransfer(MsAccount _from, MsAccount _to, MsAsset _assetQuantity, std::string _memo)
{
    MsAssert(_from != _to, "must from != to");

    if (_to == this->m_self)
    {
        return this->OnTransferToMe(_from, _to, _assetQuantity, _memo);
    }
    else if (_from == this->m_self)
    {
        return this->OnTransferFromMe(_from, _to, _assetQuantity, _memo);
    }
    else
    {
        return this->OnTransferOther(_from, _to, _assetQuantity, _memo);
    }
}
