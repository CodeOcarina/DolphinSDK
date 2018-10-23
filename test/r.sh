ps -aux |grep nodeos |awk '{print $2}'|xargs kill -9
#nohup /usr/local/eosio/bin/nodeos --config-dir /home/ms/.local/share/eosio/nodeos/config/ --max-transaction-time=1000 --delete-all-blocks --contracts-console > /root/nodeos.log &

nohup /usr/local/eosio/bin/nodeos --config-dir ./ --max-transaction-time=1000 --delete-all-blocks --contracts-console --genesis-json ./genesis.json >> ./nodeos.log &
#nohup /usr/local/eosio/bin/nodeos --config-dir ./ --max-transaction-time=1000 --delete-all-blocks --genesis-json ./genesis.json >> ./nodeos.log &



