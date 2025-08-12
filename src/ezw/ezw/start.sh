#!/bin/bash

# --- CONFIGURATION ---
REMOTE_USER="swd_sk"
REMOTE_HOST="10.1.69.215"
REMOTE_PASS="swd_sk"
REMOTE_SCRIPT="/home/swd_sk/embedded-idec-ez-wheel/TCP-CAN/tcp_to_can_diff.py"
LOCAL_DIFF_DRIVE="/home/icr247/external-idec-ez-wheel/src/ezw/ezw/diff_drive.py"

# --- Start joy_node locally ---
echo "[LOCAL] Starting joy_node..."
source /opt/ros/jazzy/setup.bash
ros2 run joy joy_node &
JOY_PID=$!
echo "[LOCAL] joy_node PID: $JOY_PID"

# --- Wait for SSH connection ---
echo "[SSH] Waiting for SSH connection to $REMOTE_HOST..."
until sshpass -p "$REMOTE_PASS" ssh -o StrictHostKeyChecking=no ${REMOTE_USER}@${REMOTE_HOST} "exit 0" &>/dev/null
do
    echo "[SSH] Connection failed, retrying in 3 seconds..."
    sleep 3
done
echo "[SSH] Connection successful."

# --- Start remote CANopen script in background ---
echo "[REMOTE] Starting TCP_to_CAN..."
sshpass -p "$REMOTE_PASS" ssh -o StrictHostKeyChecking=no ${REMOTE_USER}@${REMOTE_HOST} \
    "nohup python3 '$REMOTE_SCRIPT' > /tmp/tcp_can.log 2>&1 &"
if [ $? -ne 0 ]; then
    echo "[REMOTE] Failed to start TCP_to_CAN script."
    exit 1
fi
echo "[REMOTE] TCP_to_CAN running in background. Logs: /tmp/tcp_can.log"

# --- Start diff_drive locally ---
echo "[LOCAL] Starting diff_drive.py..."
/bin/python3 "$LOCAL_DIFF_DRIVE" &
DIFF_PID=$!
echo "[LOCAL] diff_drive PID: $DIFF_PID"

# --- Final Status ---
echo "------------------------------------"
echo "All processes started."
echo " joy_node PID     : $JOY_PID"
echo " diff_drive PID   : $DIFF_PID"
echo " Remote CANopen   : running in background on $REMOTE_HOST"
echo " Remote log file  : /tmp/tcp_can.log"
echo "------------------------------------"
