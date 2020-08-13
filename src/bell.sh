#!/bin/sh
# $Id: bell.sh,v 1.1.1.1 2003/03/10 22:42:55 tong Exp $
#set -x
(
COMPILEENDSOUND=${COMPILEENDSOUND:-compileend.aifc}

if [ ! -f $COMPILEENDSOUND ]
then
  COMPILEENDSOUND=/usr/local/pds/lib/paro_se.aifc
fi

if [ -f $COMPILEENDSOUND ]
then
    if [ $REMOTEHOST ]
    then
#    	rsh -n $REMOTEHOST "(unsetenv DISPLAY; audiopanel -nodisplay -nofork -outlevels ${COMPILEENDVOLUME:-100}; cd $PWD;  playaifc -p $COMPILEENDSOUND)"
    	rsh -n $REMOTEHOST "(volume ${COMPILEENDVOLUME:-20} ${COMPILEENDVOLUME:-20}; cd $PWD;  playaifc $COMPILEENDSOUND)"
    else
# ↓↓↓Onyx などではエラーダイアログが出てしまう。↓↓↓
#	audiopanel -nodisplay -nofork -outlevels ${COMPILEENDVOLUME:-20}
	volume ${COMPILEENDVOLUME:-20} ${COMPILEENDVOLUME:-20}
	playaifc -p $COMPILEENDSOUND
    fi
fi
) > /dev/null
