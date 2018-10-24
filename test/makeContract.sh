eosiocpp -o Sample.wasm Sample.cpp
../nodeos/unlockWallet.sh
cleos set contract zhaojingdong ./ Sample.wasm msContract.abi.json
cleos set account permission zhaojingdong active '{"threshold": 1, "keys":[{"key":"EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV","weight":1}],"accounts":[{"permission":{"actor":"zhaojingdong","permission":"eosio.code"},"weight":1}]}' -p zhaojingdong@owner

