#! /bin/sh

# Init
echo "BenchName;Mono;Vala;plain-C" > bench-time.csv
echo "BenchName;Mono;Vala;plain-C" > bench-size.csv

# Loop
for dir in $*
do	
	echo $dir';'$(cat `find ./$dir/ |grep time.csv` |tr '\n' ';' |sed 's/;$//') >> bench-time.csv
	echo $dir';'$(cat `find ./$dir/ |grep size.csv` |tr '\n' ';' |sed 's/;$//') >> bench-size.csv
done;

# (warning: just a note)
# to convert to html , Google Wiki syntax and Tab separated values
# sed 's|;|</td><td>|g;s|^\(.*\)$|<tr><td>\1</td></tr>|' data.csv
# sed 's/;/||/g;s/^\(.*\)$/||\1||/' data.csv
# sed 's/;/\t/g;s/^\(.*\)$/\t\1\t/' data.csv

# Generating charts
#
cp ploticus-time.tmpl template
sed 's/;/\t/g;s/^\(.*\)$/\1\t/' bench-time.csv >> template
ploticus -png -o bench-time.png template
rm template
#
cp ploticus-size.tmpl template
sed 's/;/\t/g;s/^\(.*\)$/\1\t/' bench-size.csv >> template
ploticus -png -o bench-size.png template
rm template
#