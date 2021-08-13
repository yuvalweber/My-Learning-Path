#! /bin/bash
echo -e "\e[0;33menter ip range (example:10.100.102.1/24):\e[0m"
read iprange
nmap -sP $iprange|grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" > ./ip_list.txt
mone=`cat ./ip_list.txt|wc -l`
echo -e "\n"
function ProgressBar {

    		let _progress=(${1}*100/${2}*100)/100
    		let _done=(${_progress}*4)/10
    		let _left=40-$_done

    		_fill=$(printf "%${_done}s")
    		_empty=$(printf "%${_left}s")


		printf "\rProgress : [${_fill// /\#}${_empty// /-}] ${_progress}%%"

}

for ((i=1;i<=$mone;i++))
do
	ip=`sed -n "$i p" ./ip_list.txt`
	quiet=`ping -c 4 $ip`
	sleep 0.1
	ProgressBar ${i} ${mone}
done
echo -e "\n\n\e[0;32mThe arp table is:\e[0m"
arp -a
rm -f ./ip_list.txt
