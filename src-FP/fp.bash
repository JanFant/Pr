#!/bin/bash
#	if (md5sum -c /etc/local.d/sumfp 2>/dev/null | grep "FAILED"); then
#	echo "Checksum doesn't match" > /dev/kmsg
#	else
#	(
	cd /root
	while true
	do
	rm *.bin
	./fpcpc > /dev/null
	done
#	)
#	fi