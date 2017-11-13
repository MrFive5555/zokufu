#!/bin/bash
# test script
E="./geneology.out"
function f1(){

	# test mate incorrect number of paras
	$E m 1
	# test mate on root
	$E m 0 1 2
	# test mate nonexist person
	$E m 97 98 99

	# test attach nonexist person
	$E a 100
	# attach correct
	$E a 1
	$E d
}
function f2(){

	# attach nonexist member
	$E a 99

	# attach correct
	$E a 1
	$E d

	# test mate wrong order master slave
	$E m 2 1 8
	$E d 

	# test mate correct order
	$E m 1 2 8
	$E d

}
function f3(){
	
	# let's be serious

	# Crunch everything 

	# test incest
	# 
	# test child wrench
	# 

	# $E mate 0 1 2 3
	# $E display
	# $E mate 0 1 4 5

}
# echo $(f1) | grep -v "browser"
function fx(){
	echo "hello"
	echo "yello"
}
# init b4 testing
echo -ne "\n" | $E i
# actual testing
f2 |& grep -v -F -e 'ERROR:browser_gpu_channel_host_factory.cc' -e 'Created new window in existing browser session.'

	# # more child
	# $E m 1 2 4
	# $E d
	# # waste
	# $E m 1 2 4 8
	# $E m 1 2 8 4
	# $E d