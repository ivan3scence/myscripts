#!/usr/bin/bash

BATT=$(cat /sys/class/power_supply/BAT0/capacity)
DATE=$(date +"%F %R")
AUDIO=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -Po '\d+(?=%)' | head -n 1)
Memory=free -m | grep '^Mem' | awk '{print "total: " $2 "MB used: " $3"MB"}'
CPU=top -bn 1 | grep '^Cpu' | tr -d 'usy,' | awk '{print "user " $2 ", sys " $3}'
NET=$(net_speed)
ROOT="$Memory | $CPU | $NET | $DATE | $AUDIO% | $BATT% "
xsetroot -name "$ROOT"
