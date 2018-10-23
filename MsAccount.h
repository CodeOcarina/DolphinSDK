#pragma once

// 通eosio.token=>accounts结构
#pragma region
struct account_balance
{
    eosio::asset balance;

    uint64_t primary_key() const
    {
        return balance.symbol.name();
    }
};
typedef eosio::multi_index<N(accounts), account_balance> accounts_balance;
#pragma endregion

enum INTERFACE_ROLE_TYPE
{
    IRT_ADMIN,
    IRT_DB,
    IRT_USER,
};

class MsAccount
{
  private:
    AccountName m_account;

  public:
    MsAccount(std::string _account_name);
    // MsAccount(const char *_account_name);
    MsAccount(AccountName _account);

    void
    CheckPermission();

    void
    CheckPermission(MarkName PermissionName);

    AccountName
    GetEosName();

    std::string
    ToString();

    MsAsset
    GetBalance(MsAccount token_contract, uint64_t precision, const char *symbol);

    bool
    CheckBalance(MsAsset theAsset);

    void
    Transfer(MsAccount target_account, MsAsset asset_amount, std::string memo);

    MsAsset
    GetBalance(MsAccount token_contract, eosio::symbol_type sym);

    bool operator==(MsAccount &other)
    {
        return this->m_account == other.m_account;
    }

    bool operator!=(MsAccount &other)
    {
        return this->m_account != other.m_account;
    }
};
