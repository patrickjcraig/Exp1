//compile
gcc -w -fno-stack-protector bo_test.c -o bo_test


//get addresses
./bo_test hello


//change and run it
perl ./run.pl

