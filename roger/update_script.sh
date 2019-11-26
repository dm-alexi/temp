LOG_FILE="/var/log/update_script.log"
echo "Entry date: " >> $LOG_FILE
date >> $LOG_FILE
echo "Packages updated: " >> $LOG_FILE
apt-get update -y
apt-get upgrade -y
grep upgrade /var/log/dpkg.log >> $LOG_FILE
echo "-----------------------------------" >> $LOG_FILE
echo >> $LOG_FILE