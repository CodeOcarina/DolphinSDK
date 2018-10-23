#cd /home/ms/eos/contracts/ebtrade/

sh ./u.sh

#/usr/local/eosio/bin/eosiocpp -o exchange.wast exchange.cpp
#/usr/local/eosio/bin/eosiocpp -g exchange.abi exchange.cpp
#scp root@10.10.41.105:/mnt/a/eos/contracts/ebtrade/* ./

/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set contract eosio ./ hello.wasm hello.abi

#/usr/local/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action eosio.token transfer '["bancordexbac", "bancordexapi", "1000.0000 EOS", "deposit"]' -p bancordexbac
#/usr/local/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexbac transfer '["bancordexbac", "bancordexapi", "1000000.0000 BAC", "deposit"]' -p bancordexbac

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexapi admin '[" ", "init_market_token 1000.0000 EOS eosio.token 1000000.0000 BAC bancordexbac"]' -p bancordexbac

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexapi createx '{"creator":"bancordexapi","initial_supply":"1.0000 NEW","fee":0,"base_deposit":{"quantity":"1.0000 BAC", "contract":"bancordexbac"}, "quote_deposit":{"quantity":"1.0000 EOS", "contract":"eosio.token"}}' -p bancordexapi
#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.a active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.a@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.b active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.b@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 set account permission eosio.c active '{"threshold": 1,"keys": [{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", "weight":1}],"accounts": [{"permission":{"actor":"bancordexapi","permission":"eosio.code"},"weight":1}]}' owner -p eosio.c@owner

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexapi addautha '{"_name":{"quantity":"100.0000 EOS", "contract":"eosio.token"}}' -p bancordexapi
#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900 --url http://127.0.0.1:8888 push action bancordexapi addautha '{"_name":{"quantity":"100.0000 BAC", "contract":"bancordexbac"}}' -p bancordexapi

#/usr/local/eosio/bin/cleos --wallet-url http://127.0.0.1:8900  wallet lock -n bag2

#cd -

#tail /root/nodeos.log -n 50

