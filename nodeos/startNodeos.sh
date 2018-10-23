nohup /usr/local/eosio/bin/nodeos --config-dir ./ --max-transaction-time=1000 --delete-all-blocks --contracts-console --genesis-json ./genesis.json >> ./nodeos.log &
