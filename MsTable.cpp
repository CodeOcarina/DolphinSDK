// namespace Ms
// {
// Account::Account(std::string _account_name)
//     : m_account(S2N(_account_name.c_str()))
// {
// }
// Account::Account(const char *_account_name)
//     : m_account(S2N(_account_name))
// {
// }
// Account::Account(AccountName _account)
//     : m_account(_account)
// {
// }

// void Account::CheckPermission()
// {
//     eosio::require_auth(m_account);
// }

// void Account::CheckPermission(MarkName PermissionName)
// {
//     eosio::require_auth(eosio::permission_level(m_account, PermissionName));
// }

// AccountName
// Account::GetEosName()
// {
//     return m_account;
// }

// std::string
// Account::ToString() { return N2S(m_account); }

// eosio::extended_asset
// Account::GetBalance(Account token_contract, uint64_t precision, const char *symbol)
// {
//     return GetBalance(token_contract, eosio::string_to_symbol(precision, symbol));
// }

// void Account::Transfer(Account target_account, eosio::extended_asset asset_amount, std::string memo)
// {
//     MsLogName(Transfer, this->ToString().c_str(), " ==> ", target_account.ToString().c_str(), asset_amount, "  [pending]");
//     eosio::currency::inline_transfer(this->m_account, target_account.m_account, asset_amount, memo);
//     MsLogName(Transfer, this->ToString().c_str(), " ==> ", target_account.ToString().c_str(), asset_amount, "  [completed]");
// }

// eosio::extended_asset
// Account::GetBalance(Account token_contract, eosio::symbol_type sym)
// {
//     eosio::extended_asset _extended_asset;
//     _extended_asset.symbol = sym;
//     _extended_asset.contract = token_contract.m_account;

//     accounts_balance _t(token_contract.m_account, token_contract.m_account);

//     auto _token = _t.find(sym.name());
//     if (_token == _t.end())
//     {
//         _extended_asset.amount = 0;
//     }
//     else
//     {
//         _extended_asset.amount = _token->balance.amount;
//     }
//     return _extended_asset;
// }

// }