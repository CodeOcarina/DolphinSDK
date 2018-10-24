
msAsset::msAsset(std::string theTokenAccountName, uint8_t thePrecision, std::string theTokenSymbol)
{
    this->amount = 0;
    this->symbol = ::eosio::string_to_symbol(thePrecision, theTokenSymbol.c_str());
    this->contract = S2N(theTokenAccountName);
}

msAsset::msAsset(AccountName theTokenAccountName, eosio::symbol_type theTokenSymbol, uint64_t amount)
{
    this->amount = amount;
    this->symbol = theTokenSymbol;
    this->contract = theTokenAccountName;
}

msAsset::msAsset(AccountName theTokenAccountName, eosio::asset quantity)
{
    this->amount = quantity.amount;
    this->symbol = quantity.symbol;
    this->contract = theTokenAccountName;
}

// std::string
// msAsset::SymbolToString(eosio::symbol_type _symbol_type)
// {
//     DefBuff(buff, 10);
//     auto sym = _symbol_type.value;
//     sym >>= 8;
//     for (int i = 0; i < 7; ++i)
//     {
//         char c = (char)(sym & 0xff);
//         if (!c)
//             return std::string(buff);
//         buff[i] = c;
//         sym >>= 8;
//     }
//     return std::string(buff);
// }

bool msAsset::isSystemEOSToken()
{
    return this->contract == N(eosio.token) && this->symbol.value == S(4, EOS);
}

std::string
msAsset::SymbolToString()
{
    DefBuff(buff, 10);

    auto sym = this->symbol.value;
    sym >>= 8;
    for (int i = 0; i < 7; ++i)
    {
        char c = (char)(sym & 0xff);
        if (!c)
            return std::string(buff);
        buff[i] = c;
        sym >>= 8;
    }
    return std::string(buff);
}

// bool msAsset::analyzing_asset(std::string &p1, std::string &p2, eosio::asset &out_asset)
// {
//     DefBuff(buff, 100);
//     int precision = 0;
//     int64_t amount;
//     const char *pos = strchr(p1.c_str(), '.');
//     if (pos)
//     {
//         precision = p1.size() - 1 - ((uint64_t)pos - (uint64_t)p1.c_str());

//         // 修复检查错误(合约本身问题#2)
//         //if (precision <= 0 && precision > 8)
//         if (precision <= 0 || precision > 8)
//         {
//             return false;
//         }

//         memset(buff, 0, 100);
//         memcpy(buff, p1.c_str(), p1.size() - precision - 1);
//         memcpy(buff + p1.size() - precision - 1, pos + 1, precision);
//         amount = atoll(buff);
//     }

//     eosio::symbol_type _symbol = eosio::string_to_symbol(precision, p2.c_str());
//     if (this->ToString(eosio::asset{amount, _symbol}) != p1 + " " + p2)
//     {
//         msLogName(string_to_symbol, "\n ", this->ToString(eosio::asset{amount, _symbol}).c_str(), " \n");
//         return false;
//     }
//     out_asset = eosio::asset{amount, _symbol};

//     return true;
// }

std::string
msAsset::_AmountN2S(uint8_t precision, uint64_t intAmount)
{
    if (precision <= 0 && precision > 8)
    {
        MsAssert(false, "amount 转换失败");
    }

    DefBuff(buff, 100);
    DefBuff(format_buff, 10);
    strcpy(format_buff, "%05lld");
    format_buff[2] = (char)(precision + 1 + 0x30);
    sprintf(buff, format_buff, intAmount);
    int size = strlen(buff);
    if (size < precision)
    {
        // MsLog((const char *)buff, "|||", (int)size, "|||", (int)precision);
        MsAssert(false, "_amount_ 转换异常");
    }
    // MsLog((const char *)buff);
    memmove(buff + (size - precision + 1), buff + (size - precision), precision);
    // MsLog((const char *)buff);
    buff[size - precision] = '.';

    std::string amount = buff;
    // MsLog(amount.c_str());
    return amount;
}

std::string
msAsset::AmountN2S(uint8_t precision, uint64_t intAmount)
{
    auto ret = _AmountN2S(precision, intAmount);
    // MsLog(_AmountS2N(ret, precision), "|||", intAmount);
    MsAssert(_AmountS2N(ret, precision) == intAmount, "amount 转换异常");
    return ret;
}

uint64_t
msAsset::_AmountS2N(std::string strAmount, uint8_t &precision)
{
    DefBuff(buff, 100);
    precision = 0;
    uint64_t amount;
    const char *pos = strchr(strAmount.c_str(), '.');
    if (pos)
    {
        precision = strAmount.size() - 1 - ((uint64_t)pos - (uint64_t)strAmount.c_str());

        if (precision <= 0 && precision > 8)
        {
            MsAssert(false, "amount 转换失败");
        }

        memset(buff, 0, 100);
        memcpy(buff, strAmount.c_str(), strAmount.size() - precision - 1);
        memcpy(buff + strAmount.size() - precision - 1, pos + 1, precision);
        amount = atoll(buff);
    }
    return amount;
}

uint64_t
msAsset::AmountS2N(std::string strAmount, uint8_t &precision)
{
    auto ret = _AmountS2N(strAmount, precision);
    // MsLog(_AmountN2S(precision, ret).c_str(), "||||", strAmount.c_str());
    MsAssert(_AmountN2S(precision, ret) == strAmount, "amount 转换异常");
    return ret;
}

// bool msAsset::analyzing_extended_asset(std::string &p1, std::string &p2, std::string &p3, extended_asset &out_extended_asset)
// {
//     defBuff(buff, 100);
//     int precision = 0;
//     int64_t amount;
//     const char *pos = strchr(p1.c_str(), '.');
//     if (pos)
//     {
//         precision = p1.size() - 1 - ((uint64_t)pos - (uint64_t)p1.c_str());

//         if (precision <= 0 && precision > 8)
//         {
//             return false;
//         }

//         memset(buff, 0, 100);
//         memcpy(buff, p1.c_str(), p1.size() - precision - 1);
//         memcpy(buff + p1.size() - precision - 1, pos + 1, precision);
//         amount = atoll(buff);
//     }

//     symbol_type _symbol = string_to_symbol(precision, p2.c_str());
//     if (_sprint(asset{amount, _symbol}) != p1 + " " + p2)
//     {
//         msLogName(string_to_symbol, "\n ", this->(asset{amount, _symbol}).c_str(), " \n");
//         return false;
//     }

//     if (n2s(s2n(p3.c_str())) != p3)
//     {
//         msLogName(contract, "\n ", p3.c_str(), " \n");
//         return false;
//     }

//     out_extended_asset.amount = amount;
//     out_extended_asset.symbol = _symbol;
//     out_extended_asset.contract = s2n(p3.c_str());

//     return true;
// }

AccountName
msAsset::GetContractEosName()
{
    return this->contract;
}

// Ms::Account
// msAsset::GetContractName()
// {
//     return Ms::Account(this->contract);
// }

std::string
msAsset::ToString()
{
    int64_t p = (int64_t)symbol.precision();
    int64_t p10 = 1;
    while (p > 0)
    {
        p10 *= 10;
        --p;
    }
    p = (int64_t)symbol.precision();

    char fraction[p + 1];
    fraction[p] = '\0';
    auto change = amount % p10;

    for (int64_t i = p - 1; i >= 0; --i)
    {
        fraction[i] = (change % 10) + '0';
        change /= 10;
    }

    DefBuff(buff, 100);
    sprintf(buff, "%lld.", amount / p10);
    strncpy(buff + strlen(buff), fraction, uint32_t(p));
    return std::string(buff) + " " + this->ToString();
}

bool msAsset::Validate(std::string min, std::string max, AccountName TokenContractName, eosio::symbol_type theTokenSymbol)
{
    if (TokenContractName != this->contract)
    {
        return false;
    }

    if (theTokenSymbol != this->symbol)
    {
        return false;
    }

    uint8_t precision = 0;
    if (this->amount < this->AmountS2N(min, precision) && this->symbol.precision() == precision)
    {
        return false;
    }

    if (this->amount > this->AmountS2N(max, precision) && this->symbol.precision() == precision)
    {
        return false;
    }

    return true;
}

uint64_t
msAsset::GetAmountByInt()
{
    return amount;
}

// eosio::extended_asset
// ToEosExtendedAsset()
// {
//     eosio::extended_asset ret;
//     ret.contract = contract
// }

// eosio::extended_asset
// msAsset::GetBalance(Account theAccount)
// {
// }
