#!/bin/sh
set -x
#
# $Id: newdata.sh,v 1.1 2003/03/10 22:57:59 tong Exp $
#
if [ -f $1 ]
 then
 echo "ファイルが既に存在します"
 exit
fi

echo "#!/bin/sh
set -x
#
# \$Id\$
#
ld -r -o $1.o -objectlist $1.objs -m > $1.map
" > $1
chmod +x $1
echo "$2" > $1.objs
