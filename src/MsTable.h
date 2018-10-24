#pragma once

template <uint64_t TableName, class T>
class msTable
{
private:
    msAccount m_contract;
    msAccount m_owner;

    typedef eosio::multi_index<TableName, T> TABLE;
    TABLE *m_Table;

public:
    msTable(msAccount _contract, msAccount _owner)
        : m_contract(_contract), m_owner(_owner)
    {
        m_Table = new TABLE(m_contract.GetEosName(), m_owner.GetEosName());
    }

    T Get(uint64_t _key)
    {
        return *m_Table->find(_key);
    }

    void Set(T _t)
    {
        auto _it = m_Table->find(_t.primary_key());
        if (_it == m_Table->end())
        {
            m_Table->emplace(m_contract.GetEosName(), [&](auto &a) {
                a = _t;
            });
        }
        else
        {
            m_Table->modify(_it, 0, [&](auto &a) {
                a = _t;
            });
        }
    }
};
