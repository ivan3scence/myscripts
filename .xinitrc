#!/bin/bash

setxkbmap -layout us,ru -option grp:caps_toggle
picom -b
xwallpaper --zoom /home/vano/.config/wall.png
//while true;
//do
//  BATT=$(cat /sys/class/power_supply/BAT0/capacity)
//  if [[ $BATT == "5" ]]
//  then
//    low_power_disco &
//  elif [[ $BATT == "1" ]]
//  then
//    systemctl suspend
//  fi
//  DATE=$(date +"%F %R")
//  AUDIO=$(pactl get-sink-volume @DEFAULT_SINK@ | grep -Po '\d+(?=%)' | head -n 1)
//  Memory=$(free --mega  | grep '^Mem' | awk '{print "" $3"MB"}')
//  CPU=$(top -bn 1 | grep '^%Cpu' | tr -d 'usy,' | awk '{print "user " $2 ", sys " $3}')
//  NET=$(net_speed)
//  ROOT=" $Memory | $CPU | $NET | $DATE | $AUDIO% | $BATT% "
//  xsetroot -name "$ROOT"
//  sleep 1s
//done &

spoon&

exec dwm

