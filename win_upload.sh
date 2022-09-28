make
USER="r65liu"
HOST="linux.student.cs.uwaterloo.ca"
U_H=${USER}@${HOST}
PWD="1357911@Lrh"

SCP="sshpass -p ${PWD} scp kernel8.img ${U_H}:~/"
SCRIPT="cd ~; sh upload.sh $1"
UPL="sshpass -p ${PWD} ssh -l ${USER} ${HOST} '${SCRIPT}'"
echo "${SCP}"
echo "${UPL}"
eval "${SCP}"
eval "${UPL}"

