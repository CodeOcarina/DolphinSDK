#pragma once

class msAsset : public eosio::extended_asset
{
private:
    std::string
        _AmountN2S(uint8_t precision, uint64_t intAmount);

    uint64_t
        _AmountS2N(std::string strAmount, uint8_t &precision);

public:
    msAsset(std::string theTokenAccountName, uint8_t thePrecision, std::string theTokenSymbol);
    msAsset(AccountName theTokenAccountName, eosio::symbol_type theTokenSymbol, uint64_t amount = 0);
    msAsset(AccountName theTokenAccountName, eosio::asset quantity);

    bool
        isSystemEOSToken();

    std::string
        SymbolToString();

    // bool
    // analyzing_asset(std::string &p1, std::string &p2, eosio::asset &out_asset);

    std::string
        AmountN2S(uint8_t precision, uint64_t intAmount);

    uint64_t
        AmountS2N(std::string strAmount, uint8_t &precision);

    bool
        Validate(std::string min, std::string max, AccountName TokenContractName, eosio::symbol_type theTokenSymbol);

    AccountName
        GetContractEosName();

    // Ms::Account
    // GetContractName();

    std::string
        ToString();

    uint64_t
        GetAmountByInt();

    // eosio::extended_asset
    // ToEosExtendedAsset();
};
