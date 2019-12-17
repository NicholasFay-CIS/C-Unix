#PART A

FIRST=$( fgrep -n 91: passwd_212 | cut -d ':' -f1 )
STOP=$( fgrep -n 99: passwd_212 | cut -d ':' -f1 )
#gets the line number of the first ID in the 90's
END=$( wc -l passwd_212 | cut -d ' ' -f1 )
#gets the total line count in the file
BET=$(( $STOP - $FIRST ))
FILEN=$(( $END - $FIRST - $BET ))
#puts first 53 lines in file since 54th is a 90
head -n $(( $FIRST - 1 )) passwd_212 > passwd_212_no90s
#puts the last lines in excluded all the 90's
tail -n $FILEN passwd_212 >> passwd_212_no90s

#PART B
cat passwd_212_no90s | grep -v '#' | cut -d ':' -f7 | sort | uniq -c 
