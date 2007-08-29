#! /bin/sh

# Init
echo "Bench Name;Mono;Vala;plain-C" > bench.csv

# Loop
for dir in $*
do	
	echo $dir';'$(cat `find ./$dir/ |grep csv` |tr '\n' ';' |sed 's/;$//') >> bench.csv	
done;
