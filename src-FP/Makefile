DIR_PROG = AKNP1 AKNP2 AKNP3 AKNP4 Baz1 Baz2 RPU DU result
cpc108 = /root/cpc108/include
ProgPATH = /root/all_prog
md5Path = /

del:
	@rm -f $(ProgPATH)/*/master.h
	@rm -f $(ProgPATH)/*/mainfp*.c

delObj:
	@rm -f $(ProgPATH)/*/*.o*


copyFP:
	@cp $(ProgPATH)/mainfpAKNP.c $(ProgPATH)/AKNP1/mainfpAKNP.c
	@cp $(ProgPATH)/mainfpAKNP.c $(ProgPATH)/AKNP2/mainfpAKNP.c
	@cp $(ProgPATH)/mainfpAKNP.c $(ProgPATH)/AKNP3/mainfpAKNP.c
	@cp $(ProgPATH)/mainfpAKNP.c $(ProgPATH)/AKNP4/mainfpAKNP.c
	@cp $(ProgPATH)/mainfp.c $(ProgPATH)/Baz1/mainfp.c
	@cp $(ProgPATH)/mainfp.c $(ProgPATH)/Baz2/mainfp.c
	@cp $(ProgPATH)/mainfpRPU.c $(ProgPATH)/RPU/mainfpRPU.c
	@cp $(ProgPATH)/mainfp.c $(ProgPATH)/DU/mainfp.c

makedir:
	@-mkdir -p all_prog/AKNP1
	@-mkdir -p all_prog/AKNP2
	@-mkdir -p all_prog/AKNP3
	@-mkdir -p all_prog/AKNP4
	@-mkdir -p all_prog/Baz1
	@-mkdir -p all_prog/Baz2
	@-mkdir -p all_prog/RPU
	@-mkdir -p all_prog/DU
	@-mkdir -p all_prog/result

md5Create:
	@md5sum /lib/modules/4.9.76-gentoo-r1/kernel/dsp/dsp.ko >> /etc/local.d/sumfp
	@md5sum /usr/local/lib/libteprLib.so >> /etc/local.d/sumfp
	@md5sum /usr/local/lib/libfp8.so >> /etc/local.d/sumfp
	@md5sum /root/fpcpc >> /etc/local.d/sumfp
	@rm -f /etc/local.d/Makefile