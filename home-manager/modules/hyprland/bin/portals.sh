#!/bin/sh

systemctl --user stop xdg-desktop-portal-hyprland
systemctl --user stop xdg-desktop-portal-gtk
systemctl --user stop xdg-desktop-portal

systemctl --user start xdg-desktop-portal-hyprland
systemctl --user start xdg-desktop-portal-gtk
systemctl --user start xdg-desktop-portal
