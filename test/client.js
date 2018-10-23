eosjs2 = require('eosjs2')
// Optional configuration..


const defaultPrivateKey = "5KPuEaQXe9Px98YUPrNq6ESh1vtzTKuCoq6uWG9pMjXTE8xexkc"; // useraaaaaaaa
// const rpc = new eosjs2_jsonrpc.JsonRpc('http://127.0.0.1:8888');
const rpc = new eosjs2.Rpc.JsonRpc('http://127.0.0.1:8888');
// const signatureProvider = new eosjs2_jssig.default([defaultPrivateKey]);
const signatureProvider = new eosjs2.SignatureProvider([defaultPrivateKey]);
const api = new eosjs2.Api({ rpc, signatureProvider });

(async () => {
    try {
        const result = await api.transact({
            actions: [{
                account: 'eosio.token',
                name: 'transfer',
                authorization: [{
                    actor: 'eosio.token',
                    permission: 'active',
                }],
                data: {
                    from: 'eosio.token',
                    to: 'zhaojingdong',
                    quantity: '0.0001 EOS',
                    memo: '备注',
                },
            }]
        }, {
                blocksBehind: 3,
                expireSeconds: 30,
            });
        pre.textContent += '\n\nTransaction pushed!\n\n' + JSON.stringify(result, null, 2);
    } catch (e) {
        pre.textContent = '\nCaught exception: ' + e;
        if (e instanceof eosjs2_jsonrpc.RpcError)
            pre.textContent += '\n\n' + JSON.stringify(e.json, null, 2);
    }
})();


// config = {
//     keyProvider: ['5KPuEaQXe9Px98YUPrNq6ESh1vtzTKuCoq6uWG9pMjXTE8xexkc'], // 配置私钥字符串
//     // httpEndpoint: 'https://api.eosnewyork.io', //DEV开发链url与端口
//     httpEndpoint: 'http://127.0.0.1:8888', //DEV开发链url与端口
//     chainId: "6cbecff836a9fa60da53bf97a0a180103b2e76041d4414693d11bf39e2341547", // 通过cleos get info可以获取chainId
//     mockTransactions: () => null, // 如果要广播，需要设为null
//     transactionHeaders: (expireInSeconds, callback) => {
//         callback(null/*error*/, headers) //手动设置交易记录头，该方法中的callback回调函数每次交易都会被调用
//     },
//     expireInSeconds: 60,
//     broadcast: true,
//     debug: false,
//     sign: true,
//     authorization: null // 该参数用于在多签名情况下，识别签名帐号与权限,格式如：account@permission
// }

// eos = Eos(config);

// // var x = eos.getAccount("zhaojingdong");

// eos.getInfo({}).then(result => {
//     console.log(result)
// })

// // eos = eos;

// // eos.transaction(
// //     {
// //         actions: [
// //             {
// //                 account: 'eosio.token',
// //                 name: 'transfer',
// //                 authorization: [{
// //                     actor: 'eosio.token',
// //                     permission: 'active'
// //                 }],
// //                 data: {
// //                     from: 'eosio.token',
// //                     to: 'zhaojingdong',
// //                     quantity: '0.3000 EOS',
// //                     memo: '备注'
// //                 }
// //             }
// //         ]
// //     }
// // ).then(result => console.log(result))


// eos.contract("eosio.token").then(c => {
//     c.transfer('{"from": "eosio.token","to": "zhaojingdong","quantity": "0.3000 EOS","memo": "备注"}', {
//         authorization: ['eosio.token']
//     }).then(result => {
//         console.log(result);
//     });
// });
