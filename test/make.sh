#eosiocpp -o Hello.wasm Hello.cpp
eosiocpp -o Sample.wasm Sample.cpp
./u.sh
cleos set contract zhaojingdong ./ Sample.wasm MsContract.abi.json
cleos set account permission zhaojingdong active '{"threshold": 1, "keys":[{"key":"EOS6XUCKZygRxAar38xEQWQsb5ynaGpbCok6JixDBT1wp7ALkpuGF","weight":1}],"accounts":[{"permission":{"actor":"zhaojingdong","permission":"eosio.code"},"weight":1}]}' -p zhaojingdong@owner

#cleos --url http://node.eosflare.io set contract zhaojingdong ./ Hello.wasm MsContract.abi.json
#cleos set contract zhaojingdong ./ Hello.wasm MsContract.abi.json

