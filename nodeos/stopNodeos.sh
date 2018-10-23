ps -aux |grep nodeos |awk '{print $2}'|xargs kill -9
