#! /bin/sh

# Init
echo "Bench Name;Mono;Vala;plain-C" > bench-time.csv
echo "Bench Name;Mono;Vala;plain-C" > bench-size.csv

# Loop
for dir in $*
do	
	echo $dir';'$(cat `find ./$dir/ |grep time.csv` |tr '\n' ';' |sed 's/;$//') >> bench-time.csv
	echo $dir';'$(cat `find ./$dir/ |grep size.csv` |tr '\n' ';' |sed 's/;$//') >> bench-size.csv
done;

# to convert to html (warning: just a note)
# sed 's|;|</td><td>|g;s|^\(.*\)$|<tr><td>\1</td></tr>|' data.csv > out.html
# sed 's/;/||/g;s/^\(.*\)$/||\1/' data.csv > out.html
