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

class msAccount
{
  private:
    AccountName m_account;

  public:
    msAccount(std::string _account_name);
    // msAccount(const char *_account_name);
    msAccount(AccountName _account);

    void
    CheckPermission();

    void
    CheckPermission(MarkName PermissionName);

    AccountName
    GetEosName();

    std::string
    ToString();

    msAsset
    GetBalance(msAccount token_contract, uint64_t precision, const char *symbol);

    bool
    CheckBalance(msAsset theAsset);

    void
    Transfer(msAccount target_account, msAsset asset_amount, std::string memo);

    msAsset
    GetBalance(msAccount token_contract, eosio::symbol_type sym);

    bool operator==(msAccount &other)
    {
        return this->m_account == other.m_account;
    }

    bool operator!=(msAccount &other)
    {
        return this->m_account != other.m_account;
    }
};
