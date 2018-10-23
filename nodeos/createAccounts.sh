sh ./u.sh
#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900  wallet unlock -n bag --password PW5K9pr9wAxCtMipXR9L2Q1i6fhh7nyd7137HnQQh6G2KsXxQTuvV

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio bancordexapi EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.code EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.admin EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.token EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio bancordexbac EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.rmb EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.a EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.b EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.c EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio zhaojingdong EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 create account eosio eosio.d EOS5nFdkSc4cq8gQ4CtHvoSCFCe4qrEDUcfeHf2aCvyZzWV7YgbeF EOS5nFdkSc4cq8gQ4CtHvoSCFCe4qrEDUcfeHf2aCvyZzWV7YgbeF

#cd /home/ms/eos/build/contracts/eosio.token
cd /eos/build/contracts/eosio.token

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set contract eosio.token ./ eosio.token.wasm eosio.token.abi -x 3600
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set contract bancordexbac ./ eosio.token.wasm eosio.token.abi -x 3600
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set contract eosio.rmb ./ eosio.token.wasm eosio.token.abi -x 3600

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token create '["eosio.token", "100000000000.0000 EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac create '["bancordexbac", "100000000000.0000 BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb create '["eosio.rmb", "100000000000.0000 RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["bancordexapi", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["bancordexapi", "1000000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["bancordexapi", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.token", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.token", "10000000.0000 BAC", "issue EOS"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.token", "10000000.0000 RMB", "issue EOS"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["bancordexbac", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["bancordexbac", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["bancordexbac", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.a", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.a", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.a", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.b", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.b", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.b", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.c", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.c", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.c", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.rmb", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.rmb", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.rmb", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token issue '["eosio.admin", "10000000.0000 EOS", "issue EOS"]' -p eosio.token
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac issue '["eosio.admin", "10000000.0000 BAC", "issue BAC"]' -p bancordexbac
/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.rmb issue '["eosio.admin", "10000000.0000 RMB", "issue RMB"]' -p eosio.rmb

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission bancordexapi active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p bancordexapi@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.token active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"eosio.token","permission":"eosio.code"},"weight":1}]}' owner -p eosio.token@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission bancordexbac active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p bancordexbac@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.a active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.a@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.b active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.b@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.c active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.c@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900  wallet lock -n bag2

#cd -

